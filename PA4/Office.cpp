/**
 * @file Office.cpp
 * @brief Implementation of the Office class.
 * 
 * This file implements the office behavior in the simulation:
 * - Managing the customer queue
 * - Processing windows each tick
 * - Tracking wait time and idle time metrics
 * 
 * TICK PROCESSING ORDER:
 * 1. Increment wait time for all customers in queue
 * 2. Process each window (may return finished customers)
 * 3. Fill available windows with waiting customers
 * 
 * @author Julian Carbajal
 * @date Spring 2024
 */

#include "Office.h"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <algorithm>

/**
 * @brief Default constructor - creates an office with no windows.
 */
Office::Office(){
    name = "";
    numWindows = 0;
    windows = nullptr;
    customers = new ListQueue<Customer*>();
}

/**
 * @brief Destructor - frees windows array and customer queue.
 */
Office::~Office(){
    if(windows != nullptr){
        delete[] windows;
    }
    delete customers;
}

/**
 * @brief Constructor with specified number of windows.
 * @param numWindows Number of service windows to create.
 */
Office::Office(int numWindows){
    name = "";
    this->numWindows = numWindows;
    windows = new Window[numWindows];
    customers = new ListQueue<Customer*>();
}

/**
 * @brief Add a customer to the waiting queue.
 * @param customer Pointer to customer to add.
 */
void Office::addCustomer(Customer* customer){
    customers->add(customer);
}

/**
 * @brief Get the number of customers waiting in queue.
 * @return Queue size.
 */
int Office::getQueueSize(){
    return customers->size();
}

/**
 * @brief Check if office has any customers (in queue or at windows).
 * @return True if any customers are present.
 */
bool Office::hasCustomers(){
    if(!customers->isEmpty()){
        return true;
    }
    for(int i = 0; i < numWindows; i++){
        if(!windows[i].isAvailable()){
            return true;
        }
    }
    return false;
}

/**
 * @brief Helper function for forEach - increments customer wait time.
 * @param c Customer pointer to increment.
 */
static void incrementCustomerWait(Customer* c){
    if(c != nullptr){
        c->incrementWaitTime();
    }
}

/**
 * @brief Process one simulation tick for this office.
 * 
 * PROCESSING ORDER:
 * 1. Increment wait time for all customers in queue
 * 2. Tick each window (returns finished customers)
 * 3. Fill available windows with waiting customers
 * 
 * @return Vector of customers who finished service this tick.
 */
vector<Customer*> Office::Tick(){
    vector<Customer*> finishedCustomers;
    
    // Step 1: Increment wait time for all customers waiting in queue
    customers->forEach(incrementCustomerWait);
    
    // Step 2: Process all windows - tick each one
    for(int i = 0; i < numWindows; i++){
        Customer* finished = windows[i].Tick();
        if(finished != nullptr){
            finished->moveToNextOffice();
            finishedCustomers.push_back(finished);
        }
    }
    
    // Step 3: Fill available windows with waiting customers
    for(int i = 0; i < numWindows; i++){
        if(windows[i].isAvailable() && !customers->isEmpty()){
            Customer* nextCustomer = customers->remove();
            customerWaitTimes.push_back(nextCustomer->wait_time_at_current);
            windows[i].SetCurrentCustomer(nextCustomer);
        }
    }
    
    return finishedCustomers;
}

// ==================== METRICS METHODS ====================

/**
 * @brief Get total idle time across all windows.
 * @return Sum of all window idle times.
 */
int Office::getTotalIdleTime(){
    int total = 0;
    for(int i = 0; i < numWindows; i++){
        total += windows[i].idleTime;
    }
    return total;
}

/**
 * @brief Get the longest idle time of any single window.
 * @return Maximum idle time.
 */
int Office::getLongestIdleTime(){
    int longest = 0;
    for(int i = 0; i < numWindows; i++){
        if(windows[i].idleTime > longest){
            longest = windows[i].idleTime;
        }
    }
    return longest;
}

/**
 * @brief Get the longest customer wait time at this office.
 * @return Maximum wait time, or 0 if no customers served.
 */
int Office::getLongestWaitTime(){
    if(customerWaitTimes.empty()) return 0;
    return *max_element(customerWaitTimes.begin(), customerWaitTimes.end());
}

/**
 * @brief Get the average customer wait time at this office.
 * @return Mean wait time, or 0.0 if no customers served.
 */
double Office::getMeanWaitTime(){
    if(customerWaitTimes.empty()) return 0.0;
    int sum = 0;
    for(int wt : customerWaitTimes){
        sum += wt;
    }
    return (double)sum / customerWaitTimes.size();
}

/**
 * @brief Count customers who waited over 10 minutes.
 * @return Number of customers with wait time > 10.
 */
int Office::getCustomersOver10Min(){
    int count = 0;
    for(int wt : customerWaitTimes){
        if(wt > 10) count++;
    }
    return count;
}

/**
 * @brief Count windows that were idle for over 5 minutes.
 * @return Number of windows with idle time > 5.
 */
int Office::getWindowsIdleOver5Min(){
    int count = 0;
    for(int i = 0; i < numWindows; i++){
        if(windows[i].idleTime > 5) count++;
    }
    return count;
}