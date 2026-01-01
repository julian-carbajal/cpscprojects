/**
 * @file FileProcessor.h
 * @brief Header file for the FileProcessor class - the file I/O and HTML generation engine.
 * 
 * The FileProcessor class is STEP 3 in the translation pipeline:
 * 
 * NARRATIVE FLOW:
 * 1. Model (Step 1) - Character-level analysis and translation rules
 * 2. Translator (Step 2) - Word and sentence translation
 * 3. FileProcessor (Step 3) - Reads input files, uses Translator, generates HTML output
 * 
 * FileProcessor is the highest-level class that orchestrates the entire translation
 * process from file input to formatted HTML output.
 * 
 * @author Julian Carbajal
 * @date Spring 2024
 */

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H
#include <string>
#include <fstream>
#include "Model.h"
#include "Translator.h"

/**
 * @class FileProcessor
 * @brief Handles file I/O operations and generates HTML output with translations.
 * 
 * This class reads an input text file line by line, translates each line using
 * the Translator class, and outputs results to both the console and an HTML file.
 */
class FileProcessor
{
public:
    /**
     * @brief Default constructor for FileProcessor.
     */
    FileProcessor();

    /**
     * @brief Destructor for FileProcessor.
     */
    ~FileProcessor();

    /**
     * @brief Processes an input file and generates translated output.
     * 
     * Reads the specified file, translates each line to Robber Language,
     * prints results to console, and writes formatted HTML to Translation.html.
     * 
     * @param filename The name of the input text file to process.
     */
    void processFile(std::string filename);
};

#endif