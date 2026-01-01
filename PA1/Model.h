/**
 * @file Model.h
 * @brief Header file for the Model class - the foundation of the Robber Language translation system.
 * 
 * The Model class serves as the core linguistic engine, providing methods to:
 * 1. Identify whether a character is a vowel or consonant
 * 2. Translate individual consonants according to Robber Language rules
 * 
 * ROBBER LANGUAGE RULES:
 * - Each consonant is doubled with an 'o' inserted between (e.g., 'b' becomes "bob")
 * - Vowels remain unchanged
 * 
 * This class is used by the Translator class to perform word and sentence translations.
 * 
 * @author Julian Carbajal
 * @date Spring 2024
 */

#ifndef MODEL_H
#define MODEL_H

#include <iostream>
using namespace std;

/**
 * @class Model
 * @brief Core class that defines the Robber Language translation rules and character classification.
 * 
 * The Model class is the first building block in the translation pipeline. It provides
 * low-level character analysis and translation capabilities that higher-level classes
 * (like Translator) rely upon.
 */
class Model
{
public:
    /**
     * @brief Default constructor for Model.
     */
    Model();

    /**
     * @brief Destructor for Model.
     */
    ~Model();

    /**
     * @brief Translates a single consonant to its Robber Language equivalent.
     * @param input The consonant character to translate (lowercase).
     * @return The translated string (e.g., 'b' returns "bob").
     */
    string TranslateSingleConsonant(char input);

    /**
     * @brief Translates a single vowel (currently returns space - vowels unchanged in practice).
     * @param input The vowel character to translate.
     * @return A space character (vowels are handled differently in actual translation).
     */
    string TranslateSingleVowel(char input);

    /**
     * @brief Prints a debug message indicating the Model class.
     */
    void print();

    /**
     * @brief Translates an entire input string (declared but not implemented).
     * @param input The string to translate.
     * @return The translated string.
     */
    string Translate(string input);

    /**
     * @brief Checks if a character is a letter (declared but not implemented).
     * @param input The character to check.
     * @return True if the character is a letter, false otherwise.
     */
    bool isLetter(char input);

    /**
     * @brief Checks if a character is a vowel (a, e, i, o, u).
     * @param input The character to check.
     * @return True if the character is a vowel, false otherwise.
     */
    bool isVowel(char input);

    /**
     * @brief Checks if a character is a consonant (a letter that is not a vowel).
     * @param input The character to check.
     * @return True if the character is a consonant, false otherwise.
     */
    bool isConsonant(char input);
};

#endif
