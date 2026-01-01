/**
 * @file Translator.h
 * @brief Header file for the Translator class - the word and sentence translation engine.
 * 
 * The Translator class is STEP 2 in the translation pipeline:
 * 
 * NARRATIVE FLOW:
 * 1. Model (Step 1) - Provides character-level analysis (isConsonant, isVowel)
 * 2. Translator (Step 2) - Uses Model to translate entire WORDS and SENTENCES
 * 3. FileProcessor (Step 3) - Uses Translator to process entire files
 * 
 * The Translator bridges the gap between single-character operations (Model)
 * and file-level operations (FileProcessor).
 * 
 * @author Julian Carbajal
 * @date Spring 2024
 */

#ifndef TRANSLATOR_H
#define TRANSLATOR_H
#include <string>
#include "Model.h"

/**
 * @class Translator
 * @brief Translates English words and sentences to Robber Language.
 * 
 * This class uses the Model class to check each character and applies
 * the Robber Language transformation at the word and sentence level.
 */
class Translator
{
public:
    /**
     * @brief Default constructor for Translator.
     */
    Translator();

    /**
     * @brief Destructor for Translator.
     */
    ~Translator();

    /**
     * @brief Translates a single English word to Robber Language.
     * @param word The English word to translate.
     * @return The word translated to Robber Language.
     */
    std::string TranslateEnglishWord(const std::string &word);

    /**
     * @brief Translates an entire English sentence to Robber Language.
     * @param sentence The English sentence to translate.
     * @return The sentence translated to Robber Language.
     */
    std::string TranslateEnglishSentence(const std::string &sentence);
};

#endif