================================================================================
                PA4 - STUDENT SERVICES CENTER SIMULATION
================================================================================

Full name: Julian Carbajal
Student ID: 2401916
Chapman email: jcarbajal@chapman.edu
Course number and section: CPSC-350
Assignment: PA4 - Student Services Center Simulation

================================================================================
                           PROGRAM DESCRIPTION
================================================================================

This program simulates a Student Services Center (SSC) with three offices:
- Registrar (R)
- Cashier (C)
- Financial Aid (F)

Students arrive at specified times, visit offices in a specified order, and
the simulation calculates wait time and idle time metrics.

SIMULATION RULES:
- Each office has a configurable number of service windows
- Students wait in a FIFO queue at each office
- When a window is available, the next student in queue is served
- Students move to their next office after being served
- Simulation ends when all students have visited all their offices

================================================================================
                           FILE STRUCTURE
================================================================================

ARCHITECTURE (layered design):

    main.cpp                    <- Entry point
        |
        v
    Service (.h/.cpp)           <- Simulation orchestrator
        |
        v
    Office (.h/.cpp)            <- Individual office with windows and queue
        |
        v
    Window (.h/.cpp)            <- Single service window
    Customer (.h/.cpp)          <- Student visiting the SSC
        |
        v
    ListQueue.h                 <- Queue data structure (FIFO)
        |
        v
    DblList.h                   <- Doubly-linked list
        |
        v
    ListNode.h                  <- Individual list node

FILE DESCRIPTIONS:
    - main.cpp           : Program entry point, handles command-line args
    - Service.h/cpp      : Main simulation controller, file parsing, metrics
    - Office.h/cpp       : Models an office with windows and customer queue
    - Window.h/cpp       : Models a single service window
    - Customer.h/cpp     : Models a student with office visit schedule
    - ListQueue.h        : Template queue class (built on DblList)
    - DblList.h          : Template doubly-linked list class
    - ListNode.h         : Template node class for linked list
    - PA4_TestSampleInput.txt : Sample input file for testing

================================================================================
                           HOW TO BUILD & RUN
================================================================================

COMPILE:
    g++ -std=c++11 -o ssc *.cpp

RUN:
    ./ssc <input_file>
    
EXAMPLE:
    ./ssc PA4_TestSampleInput.txt

INPUT FILE FORMAT:
    Line 1: Number of windows at Registrar
    Line 2: Number of windows at Cashier
    Line 3: Number of windows at Financial Aid
    Line 4: Arrival tick (clock time)
    Line 5: Number of students arriving
    Lines 6+: time1 time2 time3 office1 office2 office3
              (service times and office visit order for each student)
    ... repeat arrival tick, count, students ...

EXAMPLE INPUT:
    1
    1
    1
    1
    3
    5 1 2 R C F
    5 1 2 F R C
    5 1 2 C F R

OUTPUT METRICS:
    1. Mean student wait time for each office
    2. Longest student wait time for each office
    3. Number of students waiting over 10 minutes (total)
    4. Mean window idle time for each office
    5. Longest window idle time for each office
    6. Number of windows idle over 5 minutes (total)

================================================================================
                           SOURCES USED
================================================================================

Websites:
    - https://devdocs.io/cpp/
    - https://www.geeksforgeeks.org/
    - https://www.cplusplus.com/
    - https://stackoverflow.com/
    - https://www.tutorialspoint.com/cplusplus/index.htm
    - https://www.w3schools.com/cpp/

================================================================================
                           KNOWN ISSUES / NOTES
================================================================================

- Program compiles and runs successfully
- Simulation produces correct metrics for wait times and idle times
- Uses custom doubly-linked list and queue (no STL containers for queue)
- Input file must be specified as command-line argument