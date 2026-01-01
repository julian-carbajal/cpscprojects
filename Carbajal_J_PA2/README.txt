================================================================================
                    PA2 - MARIO GAME SIMULATION
================================================================================

Full name: Julian Carbajal
Student ID: 2401916
Chapman email: jcarbajal@chapman.edu
Course number and section: CPSC-350
Assignment: PA2 - Mario Game Simulation

================================================================================
                           PROGRAM DESCRIPTION
================================================================================

This program simulates a Mario-style game where Mario navigates through
multiple levels, collecting coins, fighting enemies, and trying to reach
the boss at the end of each level.

GAME MECHANICS:
- Mario starts with configurable lives
- Power levels: 0 (normal), 1 (super), 2 (max)
- Collecting 20 coins = 1 extra life
- Kill streak of 7 enemies = 1 extra life
- Enemy fight outcomes are probability-based:
  - Goomba: 80% win chance
  - Koopa: 65% win chance
  - Boss: 50% win chance

LEVEL ENTITIES:
- c = Coin
- g = Goomba (enemy)
- m = Mushroom (power-up)
- k = Koopa (enemy)
- b = Boss
- w = Warp Pipe (advance to next level)
- . = Nothing/Empty

================================================================================
                           FILE STRUCTURE
================================================================================

ARCHITECTURE:
    main.cpp           <- Entry point, reads input file
        |
        v
    Mario (.h/.cpp)    <- Player character with lives, power, position
        |
        v
    Level (.h/.cpp)    <- 2D grid level with entities
        |
        v
    FileProcessor (.h/.cpp) <- Reads configuration from input file

FILE DESCRIPTIONS:
    - main.cpp           : Program entry point, parses command-line args
    - Mario.h/cpp        : Mario character class with game logic
    - Level.h/cpp        : Level generation and management
    - FileProcessor.h/cpp: Input file parsing

================================================================================
                           HOW TO BUILD & RUN
================================================================================

COMPILE:
    g++ -std=c++11 -o myprogram *.cpp

RUN:
    ./myprogram <input_file> <output_file>

EXAMPLE:
    ./myprogram input.txt output.txt

INPUT FILE FORMAT:
    Line 1: Number of levels
    Line 2: Grid size (N x N)
    Line 3: Starting lives
    Line 4: Coin percentage
    Line 5: Nothing percentage
    Line 6: Goomba percentage
    Line 7: Koopa percentage
    Line 8: Mushroom percentage
    (Percentages must sum to 100)

================================================================================
                           SOURCES USED
================================================================================

Websites:
    - https://devdocs.io/cpp/
    - https://cplusplus.com/doc/tutorial/arrays/
    - https://stackoverflow.com/
    - https://www.w3schools.com/cpp/cpp_arrays_loop.asp

================================================================================
                           KNOWN ISSUES / NOTES
================================================================================

- Program compiles successfully
- Game simulation logic is partially implemented
- Output is written to specified output file
