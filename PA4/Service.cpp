/**
 * @file Service.cpp
 * @brief Implementation of the Service class - the simulation orchestrator.
 * 
 * This file implements the main simulation loop:
 * 1. ReadFile() - Parse input file into arrival events
 * 2. Simulate() - Run tick-by-tick simulation
 * 3. PrintMetrics() - Output final statistics
 * 
 * SIMULATION LOOP (each tick):
 * 1. Check if customers arrive at this tick
 * 2. Create Customer objects and route to first office
 * 3. Tick each office (process windows, fill from queue)
 * 4. Route finished customers to next office or delete if done
 * 5. Repeat until all customers processed
 * 
 * @author Julian Carbajal
 * @date Spring 2024
 */

#include "Service.h"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * @brief Default constructor - initializes all fields.
 */
Service::Service(){
    currentTick = 0;
    nextArrivalIndex = 0;
    registrar = nullptr;
    cashier = nullptr;
    financialAid = nullptr;
    numWindowsAtRegistrar = 0;
    numWindowsAtCashier = 0;
    numWindowsAtFinancialAid = 0;
}

/**
 * @brief Destructor - frees dynamically allocated offices.
 */
Service::~Service(){
    delete registrar;
    delete cashier;
    delete financialAid;
}

void Service::ReadFile(string file){
    ifstream inFile(file);
    if (!inFile){
        cout << "Unable to open file: " << file << endl;
        exit(1);
    }
    
    // Read number of windows for each office
    inFile >> numWindowsAtRegistrar;
    inFile >> numWindowsAtCashier;
    inFile >> numWindowsAtFinancialAid;
    
    // Read arrival events until end of file
    int arrivalTick;
    while(inFile >> arrivalTick){
        ArrivalEvent event;
        event.arrivalTick = arrivalTick;
        
        int numCustomers;
        inFile >> numCustomers;
        
        // Read each customer's data
        for(int i = 0; i < numCustomers; i++){
            CustomerData cd;
            int time1, time2, time3;
            char office1, office2, office3;
            
            inFile >> time1 >> time2 >> time3 >> office1 >> office2 >> office3;
            
            // Map times to offices based on the order specified
            // The times are given in the ORDER the customer visits offices
            // So time1 goes with office1, time2 with office2, time3 with office3
            cd.firstOffice = office1;
            cd.secondOffice = office2;
            cd.thirdOffice = office3;
            
            // Store times based on which office they correspond to
            // We need to map: time at R, time at C, time at F
            // But input gives: time at 1st visit, time at 2nd visit, time at 3rd visit
            cd.timeAtRegistrar = 0;
            cd.timeAtCashier = 0;
            cd.timeAtFinancialAid = 0;
            
            // Map first office time
            if(office1 == 'R') cd.timeAtRegistrar = time1;
            else if(office1 == 'C') cd.timeAtCashier = time1;
            else if(office1 == 'F') cd.timeAtFinancialAid = time1;
            
            // Map second office time
            if(office2 == 'R') cd.timeAtRegistrar = time2;
            else if(office2 == 'C') cd.timeAtCashier = time2;
            else if(office2 == 'F') cd.timeAtFinancialAid = time2;
            
            // Map third office time
            if(office3 == 'R') cd.timeAtRegistrar = time3;
            else if(office3 == 'C') cd.timeAtCashier = time3;
            else if(office3 == 'F') cd.timeAtFinancialAid = time3;
            
            event.customers.push_back(cd);
        }
        
        arrivalEvents.push_back(event);
    }
    
    inFile.close();
    
    cout << "Read " << arrivalEvents.size() << " arrival events from file." << endl;
}

void Service::routeCustomerToOffice(Customer* customer, char officeChar){
    if(officeChar == 'R'){
        registrar->addCustomer(customer);
    } else if(officeChar == 'C'){
        cashier->addCustomer(customer);
    } else if(officeChar == 'F'){
        financialAid->addCustomer(customer);
    }
}

bool Service::simulationComplete(){
    // Check if all arrival events have been processed
    if(nextArrivalIndex < arrivalEvents.size()){
        return false;
    }
    // Check if any office still has customers
    if(registrar->hasCustomers() || cashier->hasCustomers() || financialAid->hasCustomers()){
        return false;
    }
    return true;
}

void Service::Simulate(){
    // Create the offices
    registrar = new Office(numWindowsAtRegistrar);
    registrar->name = "Registrar";
    
    cashier = new Office(numWindowsAtCashier);
    cashier->name = "Cashier";
    
    financialAid = new Office(numWindowsAtFinancialAid);
    financialAid->name = "Financial Aid";
    
    cout << "Created offices: Registrar(" << numWindowsAtRegistrar << " windows), "
         << "Cashier(" << numWindowsAtCashier << " windows), "
         << "Financial Aid(" << numWindowsAtFinancialAid << " windows)" << endl;
    
    currentTick = 1;  // Simulation starts at tick 1
    
    while(!simulationComplete()){
        // Check if customers arrive at this tick
        if(nextArrivalIndex < arrivalEvents.size() && 
           arrivalEvents[nextArrivalIndex].arrivalTick == currentTick){
            
            ArrivalEvent& event = arrivalEvents[nextArrivalIndex];
            cout << "Tick " << currentTick << ": " << event.customers.size() << " customers arriving" << endl;
            
            for(CustomerData& cd : event.customers){
                Customer* newCustomer = new Customer();
                newCustomer->arrival_time = currentTick;
                newCustomer->firstOffice = cd.firstOffice;
                newCustomer->secondOffice = cd.secondOffice;
                newCustomer->thirdOffice = cd.thirdOffice;
                
                // Set times based on office order
                // Customer visits offices in order: first, second, third
                // We need to set timeAtFirstOffice = time at their FIRST office visit
                if(cd.firstOffice == 'R') newCustomer->timeAtFirstOffice = cd.timeAtRegistrar;
                else if(cd.firstOffice == 'C') newCustomer->timeAtFirstOffice = cd.timeAtCashier;
                else if(cd.firstOffice == 'F') newCustomer->timeAtFirstOffice = cd.timeAtFinancialAid;
                
                if(cd.secondOffice == 'R') newCustomer->timeAtSecondOffice = cd.timeAtRegistrar;
                else if(cd.secondOffice == 'C') newCustomer->timeAtSecondOffice = cd.timeAtCashier;
                else if(cd.secondOffice == 'F') newCustomer->timeAtSecondOffice = cd.timeAtFinancialAid;
                
                if(cd.thirdOffice == 'R') newCustomer->timeAtThirdOffice = cd.timeAtRegistrar;
                else if(cd.thirdOffice == 'C') newCustomer->timeAtThirdOffice = cd.timeAtCashier;
                else if(cd.thirdOffice == 'F') newCustomer->timeAtThirdOffice = cd.timeAtFinancialAid;
                
                // Route to first office
                routeCustomerToOffice(newCustomer, newCustomer->firstOffice);
            }
            
            nextArrivalIndex++;
        }
        
        // Process each office tick and collect finished customers
        vector<Customer*> finishedAtRegistrar = registrar->Tick();
        vector<Customer*> finishedAtCashier = cashier->Tick();
        vector<Customer*> finishedAtFinancialAid = financialAid->Tick();
        
        // Route finished customers to their next office (alphabetical order: C, F, R)
        // Cashier finishers go first
        for(Customer* c : finishedAtCashier){
            if(!c->isFinished()){
                routeCustomerToOffice(c, c->getCurrentOffice());
            } else {
                delete c;  // Customer done with all offices
            }
        }
        
        // Financial Aid finishers go second
        for(Customer* c : finishedAtFinancialAid){
            if(!c->isFinished()){
                routeCustomerToOffice(c, c->getCurrentOffice());
            } else {
                delete c;
            }
        }
        
        // Registrar finishers go last
        for(Customer* c : finishedAtRegistrar){
            if(!c->isFinished()){
                routeCustomerToOffice(c, c->getCurrentOffice());
            } else {
                delete c;
            }
        }
        
        currentTick++;
        
        // Safety check to prevent infinite loops during development
        if(currentTick > 10000){
            cout << "Safety limit reached at tick " << currentTick << endl;
            break;
        }
    }
    
    cout << "Simulation complete at tick " << currentTick << endl;
}

void Service::PrintMetrics(){
    cout << "\n========== SIMULATION METRICS ==========" << endl;
    
    // 1. Mean student wait time for each office
    cout << "\n1. Mean student wait time:" << endl;
    cout << "   Registrar: " << registrar->getMeanWaitTime() << " minutes" << endl;
    cout << "   Cashier: " << cashier->getMeanWaitTime() << " minutes" << endl;
    cout << "   Financial Aid: " << financialAid->getMeanWaitTime() << " minutes" << endl;
    
    // 2. Longest student wait time for each office
    cout << "\n2. Longest student wait time:" << endl;
    cout << "   Registrar: " << registrar->getLongestWaitTime() << " minutes" << endl;
    cout << "   Cashier: " << cashier->getLongestWaitTime() << " minutes" << endl;
    cout << "   Financial Aid: " << financialAid->getLongestWaitTime() << " minutes" << endl;
    
    // 3. Number of students waiting over 10 minutes total
    int totalOver10 = registrar->getCustomersOver10Min() + 
                      cashier->getCustomersOver10Min() + 
                      financialAid->getCustomersOver10Min();
    cout << "\n3. Students waiting over 10 minutes (total): " << totalOver10 << endl;
    
    // 4. Mean window idle time for each office
    cout << "\n4. Mean window idle time:" << endl;
    cout << "   Registrar: " << (numWindowsAtRegistrar > 0 ? (double)registrar->getTotalIdleTime() / numWindowsAtRegistrar : 0) << " minutes" << endl;
    cout << "   Cashier: " << (numWindowsAtCashier > 0 ? (double)cashier->getTotalIdleTime() / numWindowsAtCashier : 0) << " minutes" << endl;
    cout << "   Financial Aid: " << (numWindowsAtFinancialAid > 0 ? (double)financialAid->getTotalIdleTime() / numWindowsAtFinancialAid : 0) << " minutes" << endl;
    
    // 5. Longest window idle time for each office
    cout << "\n5. Longest window idle time:" << endl;
    cout << "   Registrar: " << registrar->getLongestIdleTime() << " minutes" << endl;
    cout << "   Cashier: " << cashier->getLongestIdleTime() << " minutes" << endl;
    cout << "   Financial Aid: " << financialAid->getLongestIdleTime() << " minutes" << endl;
    
    // 6. Number of windows idle for over 5 minutes
    int totalIdleOver5 = registrar->getWindowsIdleOver5Min() + 
                         cashier->getWindowsIdleOver5Min() + 
                         financialAid->getWindowsIdleOver5Min();
    cout << "\n6. Windows idle over 5 minutes (total): " << totalIdleOver5 << endl;
    
    cout << "\n=========================================" << endl;
}

