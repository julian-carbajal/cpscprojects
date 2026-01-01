/**
 * @file Customer.h
 * @brief Models a student visiting the Student Services Center.
 * 
 * This is part of the SIMULATION LAYER:
 * 
 * SIMULATION ARCHITECTURE:
 *   Customer (You are here) - Represents a student with office visit schedule
 *   Window - Service window that processes one customer at a time
 *   Office - Contains windows and a queue of waiting customers
 *   Service - Orchestrates the entire simulation
 * 
 * CUSTOMER LIFECYCLE:
 * 1. Created when arriving at SSC (from input file)
 * 2. Routed to first office queue
 * 3. Waits in queue (wait_time increments each tick)
 * 4. Served at window (service time from input)
 * 5. Moves to next office (repeat 3-4)
 * 6. Deleted after visiting all 3 offices
 * 
 * @author Julian Carbajal
 * @date Spring 2024
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * @class Customer
 * @brief Represents a student visiting multiple offices in the SSC.
 */
class Customer {
    public:
        /** @brief Default constructor - initializes all fields to 0/null. */
        Customer();
        
        /** @brief Destructor. */
        ~Customer();
        
        /** @brief Increment wait time (called each tick while in queue). */
        void incrementWaitTime();
        
        /** @brief Move to the next office after finishing current one. */
        void moveToNextOffice();
        
        /** @brief Check if customer has visited all 3 offices. @return True if done. */
        bool isFinished();
        
        /** @brief Get the next office to visit. @return Office char or '\0' if done. */
        char getNextOffice();
        
        /** @brief Get the current office. @return Office char (R, C, or F). */
        char getCurrentOffice();
        
        int arrival_time;          ///< Tick when customer arrived at SSC
        int current_office_index;  ///< 0, 1, or 2 (which office visit they're on)
        int wait_time_at_current;  ///< Wait time at current office
        int total_wait_time;       ///< Total wait time across all offices
        
        int timeAtFirstOffice;     ///< Service time needed at first office visit
        int timeAtSecondOffice;    ///< Service time needed at second office visit
        int timeAtThirdOffice;     ///< Service time needed at third office visit
        
        char firstOffice;          ///< First office to visit (R, C, or F)
        char secondOffice;         ///< Second office to visit
        char thirdOffice;          ///< Third office to visit
};

#endif