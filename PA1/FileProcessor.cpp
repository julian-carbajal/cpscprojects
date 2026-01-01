/**
 * @file FileProcessor.cpp
 * @brief Implementation file for the FileProcessor class.
 * 
 * This file contains the implementation of file processing and HTML generation.
 * The FileProcessor class is STEP 3 (final step) in the translation pipeline:
 * 
 * NARRATIVE FLOW:
 * 1. Open the input text file for reading
 * 2. Create an output HTML file with proper HTML structure
 * 3. For each line in the input file:
 *    a. Create a Translator object
 *    b. Translate the line using TranslateEnglishSentence()
 *    c. Print the translation to console
 *    d. Write both original (bold) and translated (italic) to HTML
 * 4. Close HTML tags and both files
 * 
 * OUTPUT FORMAT (Translation.html):
 * - Original text appears in <b>bold</b>
 * - Translated text appears in <i>italic</i>
 * - Each line pair is wrapped in <p> tags
 * 
 * @author Julian Carbajal
 * @date Spring 2024
 */

#include "FileProcessor.h"
#include "Translator.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief Default constructor - initializes the FileProcessor object.
 * 
 * No special initialization needed. File handles are created in processFile().
 */
FileProcessor::FileProcessor()
{
}

/**
 * @brief Destructor - cleans up the FileProcessor object.
 * 
 * File handles are closed within processFile(), so no cleanup needed here.
 */
FileProcessor::~FileProcessor()
{
}

/**
 * @brief Main processing method - reads input file and generates HTML output.
 * 
 * This method orchestrates the entire translation workflow:
 * 
 * STEP-BY-STEP PROCESS:
 * 1. Open input file (filename) for reading
 * 2. Create output file (Translation.html) for writing
 * 3. Write HTML document header (DOCTYPE, html, head, body tags)
 * 4. Validate that input file opened successfully
 * 5. Loop through each line of input:
 *    - Create Translator instance
 *    - Translate the line to Robber Language
 *    - Output translation to console (for user feedback)
 *    - Write original text in bold to HTML
 *    - Write translated text in italic to HTML
 * 6. Close HTML document (body, html tags)
 * 7. Close both file handles
 * 
 * @param filename The path to the input text file (e.g., "input.txt").
 */
void FileProcessor::processFile(std::string filename)
{
    // STEP 1: Open input file for reading
    ifstream myfile(filename);
    
    // STEP 2: Create output HTML file
    ofstream outfile("Translation.html");

    // STEP 3: Write HTML document header
    outfile << "<!DOCTYPE html>\n";
    outfile << "<html>\n";
    outfile << "<head>\n";
    outfile << "<title>English to Robber Language Translation</title>\n";
    outfile << "</head>\n";
    outfile << "<body>\n";

    // STEP 4: Validate input file opened successfully
    if (!myfile.is_open())
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // STEP 5: Process each line of the input file
    string line;
    while (getline(myfile, line))
    {
        // Create a Translator for this line
        Translator translator;
        
        // Translate the entire line (sentence) to Robber Language
        string translatedLine = translator.TranslateEnglishSentence(line);

        // Output translation to console for immediate user feedback
        cout << translatedLine << endl;

        // Write to HTML: original in bold, translated in italic
        outfile << "<p><b>" << line << "</b><br></p>\n";
        outfile << "<p><i>" << translatedLine << "</i><br></p>\n";
    }

    // STEP 6: Close HTML document structure
    outfile << "</body>\n";
    outfile << "</html>\n";

    // STEP 7: Close both file handles to flush buffers and release resources
    myfile.close();
    outfile.close();
}
