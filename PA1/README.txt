================================================================================
                    PA1 - ROBBER LANGUAGE TRANSLATOR
================================================================================

Full name: Julian Carbajal
Student ID: 002401916
Chapman email: jcarbajal@chapman.edu
Course number and section: CPSC-350-01
Assignment or exercise number: PA 1 RobberLanguage Program

================================================================================
                           PROGRAM DESCRIPTION
================================================================================

This program translates English text into "Robber Language" - a simple cipher
where each consonant is doubled with an 'o' inserted between.

ROBBER LANGUAGE RULE:
    Consonant -> Consonant + "o" + Consonant
    Example: 'b' becomes "bob", 't' becomes "tot", 's' becomes "sos"
    Vowels remain unchanged.

EXAMPLE TRANSLATION:
    Input:  "Hello World"
    Output: "Hohelollolo Wowororloldod"

================================================================================
                           FILE STRUCTURE
================================================================================

The program follows a layered architecture with 3 main classes:

    main.cpp                    <- Entry point
        |
        v
    FileProcessor (.h/.cpp)     <- Step 3: File I/O & HTML generation
        |
        v
    Translator (.h/.cpp)        <- Step 2: Word & sentence translation
        |
        v
    Model (.h/.cpp)             <- Step 1: Character classification & rules

FILE DESCRIPTIONS:
    - main.cpp           : Program entry point, initializes FileProcessor
    - FileProcessor.h/cpp: Reads input.txt, writes Translation.html
    - Translator.h/cpp   : Translates words and sentences using Model
    - Model.h/cpp        : Defines isConsonant(), isVowel(), translation rules
    - input.txt          : Input file containing English text to translate
    - Translation.html   : Output file with formatted translations

================================================================================
                           HOW TO BUILD & RUN
================================================================================

COMPILE:
    g++ -o MyProgram Model.cpp Translator.cpp main.cpp FileProcessor.cpp

RUN:
    ./MyProgram

INPUT:
    - Place English text in "input.txt" (one sentence per line)

OUTPUT:
    - Console: Displays translated text
    - Translation.html: Formatted HTML with original (bold) and translated (italic)

================================================================================
                           SOURCES USED
================================================================================

Books:
    - C++ Crash Course: A Fast Paced Introduction by Josh Lospinoso
      https://ccc.codes

Websites:
    - w3schools
    - Stack Overflow
    - cplusplus.com

Specific References:
    - https://stackoverflow.com/questions/478075/creating-files-in-c
    - https://www.w3schools.com/cpp/cpp_for_loop.asp
    - https://cplusplus.com/doc/tutorial/files/
    - https://stackoverflow.com/questions/51054902/error-no-matching-function-for-call-to-stdvectorstd-cxx11basic-string
    - https://stackoverflow.com/questions/28442719/are-c-strings-mutable-unlike-java-strings
    - https://stackoverflow.com/questions/7868936/read-file-line-by-line-using-ifstream-in-c

ChatGPT Usage (debugging assistance):
    - "What is wrong with my code?.."
    - "How to iterate over a string in C++"
    - "example template for classes in C++"
    - "what does std::string(1, c) do?"
    - "how to process a file in C++ and projecting it onto an html file"
    - "how to create a main file using several cpp files"

================================================================================
                           KNOWN ISSUES / NOTES
================================================================================

- Code tested and works with Docker environment
- Input file must be named "input.txt" and placed in same directory as executable
- Output HTML file is always named "Translation.html"





