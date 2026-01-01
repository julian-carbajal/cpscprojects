/**
 * @file main.cpp
 * @brief Entry point for the Robber Language Translator program.
 * 
 * This is the MAIN FILE that ties everything together. It demonstrates the
 * complete translation pipeline in action.
 * 
 * ============================================================================
 * COMPLETE PROGRAM NARRATIVE - How the Translation Pipeline Works:
 * ============================================================================
 * 
 * ARCHITECTURE OVERVIEW:
 * The program follows a layered architecture where each class has a specific role:
 * 
 *   main.cpp (You are here)
 *       |
 *       v
 *   FileProcessor (Step 3) - Handles file I/O and HTML generation
 *       |
 *       v
 *   Translator (Step 2) - Translates words and sentences
 *       |
 *       v
 *   Model (Step 1) - Character classification and translation rules
 * 
 * EXECUTION FLOW:
 * 1. main() creates a FileProcessor object
 * 2. FileProcessor::processFile("input.txt") is called
 * 3. FileProcessor reads each line from input.txt
 * 4. For each line, Translator::TranslateEnglishSentence() is called
 * 5. Translator breaks the sentence into words and calls TranslateEnglishWord()
 * 6. TranslateEnglishWord() uses Model::isConsonant() to identify consonants
 * 7. Each consonant is transformed: char -> char + "o" + char (e.g., 'b' -> "bob")
 * 8. Results are printed to console AND written to Translation.html
 * 
 * ROBBER LANGUAGE RULE:
 * Every consonant is doubled with an 'o' in between.
 * Example: "Hello" -> "Hohelollolo"
 *          "Test"  -> "Totesostot"
 * 
 * TO RUN:
 *   g++ -o MyProgram Model.cpp Translator.cpp main.cpp FileProcessor.cpp
 *   ./MyProgram
 * 
 * INPUT:  input.txt (plain text file with English sentences)
 * OUTPUT: Translation.html (formatted HTML with original and translated text)
 *         Console output (translated text only)
 * 
 * @author Julian Carbajal
 * @date Spring 2024
 */

#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"
#include <iostream>

using namespace std;

/**
 * @brief Main function - program entry point.
 * 
 * This function initializes the translation pipeline and processes the input file.
 * 
 * @param argc Number of command-line arguments (unused in this version).
 * @param argv Array of command-line argument strings (unused in this version).
 * @return 0 on successful execution.
 */
int main(int argc, char* argv[]){
    // Model instance created but not directly used here
    // (Model is used internally by Translator)
    Model model;

    // Create the FileProcessor - the orchestrator of the translation pipeline
    FileProcessor process = FileProcessor();
    
    // Specify the input file containing English text to translate
    std::string filename = "input.txt";
    
    // Execute the translation pipeline:
    // FileProcessor -> Translator -> Model
    // Results: console output + Translation.html
    process.processFile(filename);

    return 0;
}


