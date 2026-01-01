/**
 * @file Office.h
 * @brief Models an office (Registrar, Cashier, or Financial Aid) in the SSC.
 * 
 * SIMULATION ARCHITECTURE:
 *   Customer - Represents a student with office visit schedule
 *   Window - Service window that processes one customer at a time
 *   Office (You are here) - Contains windows and a queue of waiting customers
 *   Service - Orchestrates the entire simulation
 * 
 * OFFICE BEHAVIOR:
 * - Has N service windows (configurable)
 * - Maintains a queue of waiting customers (FIFO)
 * - Each tick: increment wait times, process windows, fill empty windows
 * - Tracks metrics: wait times, idle times
 * 
 * @author Julian Carbajal
 * @date Spring 2024
 */

#ifndef OFFICE_H
#define OFFICE_H

#include "ListQueue.h"
#include "Window.h"
#include "Customer.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

/**
 * @class Office
 * @brief An office with multiple windows and a customer queue.
 */
class Office{
    public:
        /** @brief Default constructor. */
        Office();
        
        /** @brief Destructor - frees windows and queue. */
        ~Office();
        
        /** @brief Constructor with specified number of windows. @param numWindows Number of service windows. */
        Office(int numWindows);
        
        /** @brief Add a customer to the waiting queue. @param customer Customer to add. */
        void addCustomer(Customer* customer);
        
        /** @brief Process one simulation tick. @return Vector of customers who finished service. */
        vector<Customer*> Tick();
        
        /** @brief Check if office has any customers (queue or windows). @return True if customers present. */
        bool hasCustomers();
        
        /** @brief Get number of customers waiting in queue. @return Queue size. */
        int getQueueSize();
        
        // ===== METRICS METHODS =====
        /** @brief Get total idle time across all windows. @return Sum of idle times. */
        int getTotalIdleTime();
        
        /** @brief Get longest idle time of any single window. @return Max idle time. */
        int getLongestIdleTime();
        
        /** @brief Get longest customer wait time. @return Max wait time. */
        int getLongestWaitTime();
        
        /** @brief Get average customer wait time. @return Mean wait time. */
        double getMeanWaitTime();
        
        /** @brief Count customers who waited over 10 minutes. @return Count. */
        int getCustomersOver10Min();
        
        /** @brief Count windows idle over 5 minutes. @return Count. */
        int getWindowsIdleOver5Min();
        
        string name;                           ///< Office name (Registrar, Cashier, Financial Aid)
        Window* windows;                       ///< Array of service windows
        ListQueue<Customer*> *customers;       ///< Queue of waiting customers
        int numWindows;                        ///< Number of windows at this office
        vector<int> customerWaitTimes;         ///< Recorded wait times for metrics
};

#endif