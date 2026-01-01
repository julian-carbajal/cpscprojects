/**
 * @file Translator.cpp
 * @brief Implementation file for the Translator class.
 * 
 * This file contains the implementation of word and sentence translation.
 * The Translator class is STEP 2 in understanding the translation pipeline:
 * 
 * NARRATIVE FLOW:
 * 1. Model provides isConsonant() to identify which characters need transformation
 * 2. TranslateEnglishWord() iterates through each character in a word:
 *    - If consonant: append char + "o" + lowercase(char)  (e.g., 'T' -> "Tot")
 *    - If vowel/other: append unchanged
 * 3. TranslateEnglishSentence() breaks sentences into words, translates each,
 *    and preserves punctuation/spaces between words
 * 
 * EXAMPLE:
 * Input:  "Hello"
 * Output: "Hohelollolo"  (H->Hoh, e->e, l->lol, l->lol, o->o)
 * 
 * @author Julian Carbajal
 * @date Spring 2024
 */

#include <iostream>
#include <cctype>
#include <string>
#include "Translator.h"
#include "Model.h"

using namespace std;

/**
 * @brief Default constructor - initializes the Translator object.
 * 
 * No special initialization needed. Translator is stateless and creates
 * Model instances as needed for each translation operation.
 */
Translator::Translator() {}

/**
 * @brief Destructor - cleans up the Translator object.
 * 
 * No dynamic memory to free.
 */
Translator::~Translator() {}

/**
 * @brief Translates a single English word to Robber Language.
 * 
 * This is the CORE translation method. It processes each character:
 * - Consonants: transformed to char + "o" + lowercase(char)
 *   Example: 'B' becomes "Bob", 't' becomes "tot"
 * - Vowels and other characters: kept unchanged
 * 
 * The method preserves the original case of the first character while
 * ensuring the repeated consonant is lowercase.
 * 
 * @param word The English word to translate (e.g., "Test").
 * @return The Robber Language translation (e.g., "Totesostot").
 */
std::string Translator::TranslateEnglishWord(const std::string &word)
{
    Model model;
    string translatedWord = "";
    for (char ch : word)
    {
        if (model.isConsonant(tolower(ch)))
        {
            // ROBBER LANGUAGE RULE: consonant -> consonant + "o" + consonant(lowercase)
            translatedWord += ch + string("o") + char(tolower(ch));
        }
        else
        {
            // Vowels and non-letters pass through unchanged
            translatedWord += ch;
        }
    }
    return translatedWord;
}

/**
 * @brief Translates an entire English sentence to Robber Language.
 * 
 * This method handles sentences by:
 * 1. Building up words character by character (letters only)
 * 2. When a non-letter is encountered (space, punctuation):
 *    - Translate the accumulated word using TranslateEnglishWord()
 *    - Append the non-letter character unchanged (preserves spaces, punctuation)
 *    - Reset the word buffer
 * 3. After the loop, translate any remaining word
 * 
 * This approach preserves the original sentence structure while translating
 * only the alphabetic words.
 * 
 * @param sentence The English sentence to translate (e.g., "Hello, World!").
 * @return The Robber Language translation (e.g., "Hohelollolo, Wowororloldod!").
 */
std::string Translator::TranslateEnglishSentence(const std::string &sentence){
    Model model;
    string translatedSentence = "";
    string word = "";
    
    // Iterate through each character in the sentence
    for (int i = 0; i < sentence.length(); i++){
        if (isalpha(sentence[i])){
            // Accumulate letters into the current word
            word += sentence[i];
        }
        else{
            // Non-letter found: translate accumulated word and append separator
            translatedSentence += TranslateEnglishWord(word);
            translatedSentence += sentence[i];  // Preserve spaces, punctuation, etc.
            word = "";  // Reset word buffer for next word
        }
    }
    // Don't forget the last word (if sentence doesn't end with punctuation)
    translatedSentence += TranslateEnglishWord(word);
    return translatedSentence;
}