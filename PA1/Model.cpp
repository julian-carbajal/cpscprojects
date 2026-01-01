/**
 * @file Model.cpp
 * @brief Implementation file for the Model class.
 * 
 * This file contains the implementation of all Model class methods.
 * The Model class is STEP 1 in understanding the translation pipeline:
 * 
 * NARRATIVE FLOW:
 * 1. Model provides the fundamental building blocks - it knows what makes a vowel vs consonant
 * 2. Model defines HOW to translate a single consonant (the core Robber Language rule)
 * 3. These methods are called by Translator (see Translator.cpp) to translate entire words
 * 
 * @author Julian Carbajal
 * @date Spring 2024
 */

#include "Model.h"
#include <iostream>
using namespace std;

/**
 * @brief Default constructor - initializes the Model object.
 * 
 * No special initialization is needed as Model is stateless.
 * It simply provides utility methods for character classification and translation.
 */
Model::Model()
{
}

/**
 * @brief Destructor - cleans up the Model object.
 * 
 * No dynamic memory to free, so destructor is empty.
 */
Model::~Model()
{
}

/**
 * @brief Translates a single lowercase consonant to Robber Language.
 * 
 * THE CORE ROBBER LANGUAGE RULE:
 * Each consonant is transformed by doubling it with 'o' in between.
 * Example: 'b' becomes "bob", 't' becomes "tot", 's' becomes "sos"
 * 
 * NOTE: This method expects lowercase input. The Translator class handles
 * case conversion before calling this method.
 * 
 * @param input A lowercase consonant character.
 * @return The Robber Language translation (e.g., "bob" for 'b').
 */
string Model::TranslateSingleConsonant(char input)
{   
    string output;
    switch (input)
    { case 'b':
        output = "bob";
        break;
    case 'c':
        output = "coc";
        break;
    case 'd':
        output = "dod";
        break;
    case 'f':
        output = "fof";
        break;
    case 'g':
        output = "gog";
        break;
    case 'h':
        output = "hoh";
        break;
    case 'j':
        output = "joj";
        break;
    case 'k':
        output = "kok";
        break;
    case 'l':
        output = "lol";
        break;
    case 'm':
        output = "mom";
        break;
    case 'n':
        output = "non";
        break;
    case 'p':
        output = "pop";
        break;
    case 'q':
        output = "qoq";
        break;
    case 'r':
        output = "ror";
        break;
    case 's':
        output = "sos";
        break;
    case 't':
        output = "tot";
        break;
    case 'v':
        output = "vov";
        break;
    case 'w':
        output = "wow";
        break;
    case 'x':
        output = "xox";
        break;
    case 'y':
        output = "yoy";
        break;
    case 'z':
        output = "zoz";
        break;
    default:
        output = " ";
        break;
    }
    return output;
}

/**
 * @brief Placeholder method for vowel translation.
 * 
 * In Robber Language, vowels remain unchanged. This method exists for
 * completeness but returns a space. In practice, the Translator class
 * handles vowels by simply appending them unchanged to the output.
 * 
 * @param input A vowel character.
 * @return A space character (vowels are not transformed).
 */
string Model::TranslateSingleVowel(char input)
{
    string output;
    switch (input)
    { case 'a':
        output = " ";
        break;
    case 'e':
        output = " ";
        break;
    case 'i':
        output = " ";
        break;
    case 'o':
        output = " ";
        break;
    case 'u':
        output = " ";
        break;
    case 'y':
        output = " ";
        break;
    default:
        output = " ";
        break;
    }
    return output;
}

/**
 * @brief Determines if a character is a vowel.
 * 
 * Vowels are: a, e, i, o, u (case-insensitive).
 * This method is used by isConsonant() and by Translator to decide
 * whether to apply the Robber Language transformation.
 * 
 * @param input The character to check.
 * @return True if the character is a vowel, false otherwise.
 */
bool Model::isVowel(char input)
{
    input = tolower(input); // Convert to lowercase for consistent comparison
    return input == 'a' || input == 'e' || input == 'i' || input == 'o' || input == 'u';
}

/**
 * @brief Determines if a character is a consonant.
 * 
 * A consonant is any letter (a-z) that is NOT a vowel.
 * This is the KEY method used by Translator::TranslateEnglishWord() to decide
 * which characters need the Robber Language transformation applied.
 * 
 * @param input The character to check.
 * @return True if the character is a consonant, false otherwise.
 */
bool Model::isConsonant(char input)
{
    input = tolower(input); // Convert to lowercase for consistent comparison
    return (input >= 'a' && input <= 'z') && !isVowel(input);
}

/**
 * @brief Debug method to print the class name.
 * 
 * Useful for debugging to confirm Model object exists.
 */
void Model::print()
{
    cout << "Model" << endl;
}


