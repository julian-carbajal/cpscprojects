/**
 * @file main.cpp
 * @brief Entry point for the Student Services Center Simulation.
 * 
 * ============================================================================
 * PA4 - STUDENT SERVICES CENTER SIMULATION
 * ============================================================================
 * 
 * This program simulates a Student Services Center (SSC) with three offices:
 * - Registrar (R)
 * - Cashier (C)
 * - Financial Aid (F)
 * 
 * COMPLETE ARCHITECTURE:
 * 
 *   DATA STRUCTURES LAYER:
 *   ListNode -> DblList -> ListQueue
 *                              |
 *   SIMULATION LAYER:          v
 *   Customer, Window, Office <-+
 *                              |
 *   ORCHESTRATION LAYER:       v
 *   Service <------------------+
 *                              |
 *   ENTRY POINT:               v
 *   main.cpp (You are here) <--+
 * 
 * USAGE:
 *   ./ssc <input_file>
 *   Example: ./ssc PA4_TestSampleInput.txt
 * 
 * INPUT FILE FORMAT:
 *   Line 1: Windows at Registrar
 *   Line 2: Windows at Cashier
 *   Line 3: Windows at Financial Aid
 *   Line 4: Arrival tick
 *   Line 5: Number of customers
 *   Lines 6+: time1 time2 time3 office1 office2 office3
 *   ... repeat for more arrival events ...
 * 
 * OUTPUT:
 *   Simulation progress messages
 *   Final metrics (wait times, idle times)
 * 
 * @author Julian Carbajal
 * @date Spring 2024
 */

#include "Service.h"
#include <iostream>

using namespace std;

/**
 * @brief Main function - program entry point.
 * 
 * Parses command line arguments, creates the Service object,
 * runs the simulation, and prints metrics.
 * 
 * @param argc Number of command line arguments.
 * @param argv Array of argument strings (argv[1] = input file).
 * @return 0 on success, 1 on error.
 */
int main(int argc, char* argv[]) {
    // Check for command line argument
    if(argc < 2){
        cout << "Usage: " << argv[0] << " <input_file>" << endl;
        cout << "Example: " << argv[0] << " PA4_TestSampleInput.txt" << endl;
        return 1;
    }
    
    string inputFile = argv[1];
    
    // Create service center and run simulation
    Service service;
    service.ReadFile(inputFile);   // Parse input file
    service.Simulate();            // Run simulation
    service.PrintMetrics();        // Output results
    
    return 0;
}
