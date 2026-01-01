================================================================================
                PA3 - SPEAKER VIEW (DO YOU SEE WHAT I SEE?)
================================================================================

Full name: Julian Carbajal
Student ID: 002401916
Chapman email: jcarbajal@chapman.edu
Course number and section: CPSC-350-03
Assignment: PA3 - Speaker View

================================================================================
                           PROGRAM DESCRIPTION
================================================================================

This program determines which people in an audience can see the speaker,
given a grid of heights where each row represents a row of seats and
each column represents a vertical column of seats.

VISIBILITY RULES:
- Row 0 is closest to the speaker (front row)
- A person can see if they are taller than ALL people in front of them
- The program processes each column independently

EXAMPLE:
For input:
    121.4 50.2 75.3
    90.5  80.2 60.3
    80.3  90.7 89.9
    72.1  92.6 54.4

Column 0: Only 121.4 can see (everyone else is shorter)
Column 1: 50.2, 80.2, 90.7, 92.6 can see (each taller than previous max)
Column 2: 75.3, 89.9 can see

================================================================================
                           FILE STRUCTURE
================================================================================

ARCHITECTURE:
    main.cpp              <- Entry point
        |
        v
    SpeakerView (.h/.cpp) <- Processes heights and determines visibility
        |
        v
    MonoStack.h           <- Monotonic stack data structure
    FileProcessor (.h/.cpp) <- Reads input file

FILE DESCRIPTIONS:
    - main.cpp           : Program entry point, parses command-line args
    - SpeakerView.h/cpp  : Main logic for processing heights
    - MonoStack.h        : Template monotonic stack class
    - FileProcessor.h/cpp: Input file reading
    - input.txt          : Sample input file

================================================================================
                           HOW TO BUILD & RUN
================================================================================

COMPILE:
    g++ -std=c++11 -o program *.cpp

RUN:
    ./program <input_file> <direction>

EXAMPLE:
    ./program input.txt d

ARGUMENTS:
    - input_file: Path to file containing height grid
    - direction: 'd' for descending (standard visibility check)

INPUT FILE FORMAT:
    Space-separated heights, one row per line:
    121.4 50.2 75.3
    90.5 80.2 60.3
    80.3 90.7 89.9
    72.1 92.6 54.4

================================================================================
                           SOURCES USED
================================================================================

Books:
    - C++ Crash Course by Josh Lospinoso
    - Think Like a Programmer by V. Anton Spraul

Websites:
    - https://stackoverflow.com/
    - https://www.w3schools.com/cpp/
    - https://cplusplus.com/doc/tutorial/files/

================================================================================
                           KNOWN ISSUES / NOTES
================================================================================

- Program compiles and runs successfully
- Visibility logic correctly identifies who can see the speaker
- Uses monotonic stack concept for efficient processing