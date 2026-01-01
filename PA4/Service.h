/**
 * @file Service.h
 * @brief The main simulation orchestrator for the Student Services Center.
 * 
 * This is the TOP LEVEL of the simulation architecture:
 * 
 * COMPLETE ARCHITECTURE:
 *   ListNode -> DblList -> ListQueue (Data Structures Layer)
 *                              |
 *                              v
 *   Customer, Window, Office (Simulation Components)
 *                              |
 *                              v
 *   Service (You are here) - Orchestrates the entire simulation
 *                              |
 *                              v
 *   main.cpp - Entry point
 * 
 * SERVICE RESPONSIBILITIES:
 * 1. Read and parse input file (window counts, arrival events)
 * 2. Create and manage the three offices (Registrar, Cashier, Financial Aid)
 * 3. Run the simulation tick by tick
 * 4. Route customers between offices
 * 5. Print final metrics
 * 
 * INPUT FILE FORMAT:
 *   Line 1: Number of windows at Registrar
 *   Line 2: Number of windows at Cashier
 *   Line 3: Number of windows at Financial Aid
 *   Line 4: Arrival tick
 *   Line 5: Number of customers arriving
 *   Lines 6+: Customer data (time1 time2 time3 office1 office2 office3)
 *   ... repeat arrival events ...
 * 
 * OUTPUT METRICS:
 * 1. Mean student wait time per office
 * 2. Longest student wait time per office
 * 3. Students waiting over 10 minutes (total)
 * 4. Mean window idle time per office
 * 5. Longest window idle time per office
 * 6. Windows idle over 5 minutes (total)
 * 
 * @author Julian Carbajal
 * @date Spring 2024
 */

#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <sstream>

#include "Office.h"

using namespace std;

/**
 * @struct CustomerData
 * @brief Holds parsed customer data from input file.
 */
struct CustomerData {
    int timeAtRegistrar;      ///< Service time needed at Registrar
    int timeAtCashier;        ///< Service time needed at Cashier
    int timeAtFinancialAid;   ///< Service time needed at Financial Aid
    char firstOffice;         ///< First office to visit (R, C, or F)
    char secondOffice;        ///< Second office to visit
    char thirdOffice;         ///< Third office to visit
};

/**
 * @struct ArrivalEvent
 * @brief Represents a group of customers arriving at a specific tick.
 */
struct ArrivalEvent {
    int arrivalTick;              ///< Simulation tick when customers arrive
    vector<CustomerData> customers; ///< List of customers arriving at this tick
};

/**
 * @class Service
 * @brief Main simulation controller for the Student Services Center.
 */
class Service
{
public:
    /** @brief Default constructor. */
    Service();
    
    /** @brief Destructor - frees office objects. */
    ~Service();
    
    /** @brief Read and parse the input file. @param file Path to input file. */
    void ReadFile(string file);
    
    /** @brief Run the simulation until all customers are processed. */
    void Simulate();
    
    /** @brief Print all simulation metrics to stdout. */
    void PrintMetrics();
    
private:
    /** @brief Route a customer to the appropriate office. */
    void routeCustomerToOffice(Customer* customer, char officeChar);
    
    /** @brief Check if simulation is complete. @return True if done. */
    bool simulationComplete();
    
    Office* registrar;              ///< Registrar office
    Office* cashier;                ///< Cashier office
    Office* financialAid;           ///< Financial Aid office
    
    int numWindowsAtRegistrar;      ///< Windows at Registrar (from file)
    int numWindowsAtCashier;        ///< Windows at Cashier (from file)
    int numWindowsAtFinancialAid;   ///< Windows at Financial Aid (from file)
    
    int currentTick;                ///< Current simulation tick
    vector<ArrivalEvent> arrivalEvents; ///< All arrival events from file
    int nextArrivalIndex;           ///< Index of next arrival event to process
};

#endif // SERVICE_H
