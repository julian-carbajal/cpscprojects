/**
 * @file Customer.cpp
 * @brief Implementation of the Customer class.
 * 
 * This file implements the customer behavior in the simulation:
 * - Tracking wait times while in queue
 * - Moving between offices
 * - Determining when all visits are complete
 * 
 * @author Julian Carbajal
 * @date Spring 2024
 */

#include "Customer.h"

/**
 * @brief Default constructor - initializes customer with default values.
 */
Customer::Customer(){
    arrival_time = 0;
    current_office_index = 0;
    wait_time_at_current = 0;
    total_wait_time = 0;
    timeAtFirstOffice = 0;
    timeAtSecondOffice = 0;
    timeAtThirdOffice = 0;
    firstOffice = '\0';
    secondOffice = '\0';
    thirdOffice = '\0';
}

/**
 * @brief Destructor.
 */
Customer::~Customer(){}

/**
 * @brief Increment wait time counters.
 * 
 * Called each simulation tick while the customer is waiting in a queue.
 * Updates both the current office wait time and total wait time.
 */
void Customer::incrementWaitTime(){
    wait_time_at_current++;
    total_wait_time++;
}

/**
 * @brief Move customer to their next office.
 * 
 * Called when the customer finishes being served at a window.
 * Resets the current wait time and increments the office index.
 */
void Customer::moveToNextOffice(){
    wait_time_at_current = 0;
    current_office_index++;
}

/**
 * @brief Check if customer has completed all office visits.
 * @return True if all 3 offices have been visited.
 */
bool Customer::isFinished(){
    return current_office_index >= 3;
}

/**
 * @brief Get the current office the customer should be at.
 * @return 'R', 'C', 'F', or '\0' if finished.
 */
char Customer::getCurrentOffice(){
    switch(current_office_index){
        case 0: return firstOffice;
        case 1: return secondOffice;
        case 2: return thirdOffice;
        default: return '\0';
    }
}

/**
 * @brief Get the next office the customer will visit.
 * @return 'R', 'C', 'F', or '\0' if no more offices.
 */
char Customer::getNextOffice(){
    switch(current_office_index){
        case 0: return secondOffice;
        case 1: return thirdOffice;
        default: return '\0';
    }
}