/**
 * @file Window.cpp
 * @brief Implementation of the Window class.
 * 
 * This file implements the window behavior in the simulation:
 * - Tracking idle time when no customer is present
 * - Processing customers and tracking service time
 * - Returning finished customers for routing to next office
 * 
 * @author Julian Carbajal
 * @date Spring 2024
 */

#include "Window.h"

/**
 * @brief Default constructor - creates an available window.
 */
Window::Window(){
    currentCustomer = nullptr;
    idleTime = 0;
    serviceTimeRemaining = 0;
}

/**
 * @brief Destructor.
 */
Window::~Window(){
}

/**
 * @brief Check if window is available to serve a customer.
 * @return True if no customer is currently being served.
 */
bool Window::isAvailable(){
    return currentCustomer == nullptr;
}

/**
 * @brief Assign a customer to this window for service.
 * 
 * Sets the service time based on which office visit this is for the customer.
 * The customer's timeAtFirstOffice/Second/Third determines how long they need.
 * 
 * @param customer Pointer to the customer to serve.
 */
void Window::SetCurrentCustomer(Customer* customer){
    if (customer == nullptr) {
        return;
    }
    currentCustomer = customer;
    
    // Get the service time based on which office visit this is for the customer
    switch (currentCustomer->current_office_index)
    {
    case 0:
        serviceTimeRemaining = currentCustomer->timeAtFirstOffice;
        break;
    case 1:
        serviceTimeRemaining = currentCustomer->timeAtSecondOffice;
        break;
    case 2:
        serviceTimeRemaining = currentCustomer->timeAtThirdOffice;
        break;
    default:
        serviceTimeRemaining = 0;
        break;
    }
}

/**
 * @brief Process one simulation tick.
 * 
 * If idle: increment idle time counter.
 * If serving: decrement service time, return customer if done.
 * 
 * @return Pointer to finished customer, or nullptr if still serving/idle.
 */
Customer* Window::Tick(){
    // If no customer, window is idle
    if(currentCustomer == nullptr){
        idleTime++;
        return nullptr;
    }
    
    // Decrement service time
    serviceTimeRemaining--;
    
    // If service complete, return the customer for routing to next office
    if(serviceTimeRemaining <= 0){
        Customer* finishedCustomer = currentCustomer;
        currentCustomer = nullptr;
        return finishedCustomer;
    }
    
    return nullptr;
}