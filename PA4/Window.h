/**
 * @file Window.h
 * @brief Models a service window at an office.
 * 
 * SIMULATION ARCHITECTURE:
 *   Customer - Represents a student with office visit schedule
 *   Window (You are here) - Service window that processes one customer at a time
 *   Office - Contains windows and a queue of waiting customers
 *   Service - Orchestrates the entire simulation
 * 
 * WINDOW BEHAVIOR:
 * - Each window can serve one customer at a time
 * - When idle, idleTime increments each tick
 * - When serving, serviceTimeRemaining decrements each tick
 * - Returns the customer when service is complete
 * 
 * @author Julian Carbajal
 * @date Spring 2024
 */

#ifndef WINDOW_H
#define WINDOW_H

#include "Customer.h"

/**
 * @class Window
 * @brief A service window that processes one customer at a time.
 */
class Window {
    public:
        /** @brief Default constructor - creates an available window. */
        Window();
        
        /** @brief Destructor. */
        ~Window();
        
        /** @brief Assign a customer to this window. @param customer Customer to serve. */
        void SetCurrentCustomer(Customer* customer);
        
        /** @brief Process one tick. @return Customer if finished, nullptr otherwise. */
        Customer* Tick();
        
        /** @brief Check if window is available. @return True if no customer being served. */
        bool isAvailable();
        
        Customer *currentCustomer;     ///< Customer currently being served (nullptr if idle)
        int idleTime;                  ///< Total ticks this window has been idle
        int serviceTimeRemaining;      ///< Ticks remaining for current customer
};

#endif