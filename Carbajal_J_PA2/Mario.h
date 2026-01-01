/**
 * @file Mario.h
 * @brief Models Mario character in the game simulation.
 * 
 * ARCHITECTURE:
 *   Level - Generates and manages a 2D grid level
 *       ^
 *       |
 *   Mario (You are here) - Player character with lives, power, position
 *       ^
 *       |
 *   main.cpp - Entry point
 * 
 * MARIO MECHANICS:
 * - Starts with configurable lives
 * - Power levels: 0 (normal), 1 (super), 2 (max)
 * - Collects coins (20 coins = extra life)
 * - Fights enemies with probability-based outcomes
 * - Kill streak of 7 = extra life
 * 
 * @author Julian Carbajal
 * @date Spring 2024
 */

#ifndef MARIO_H
#define MARIO_H
#include <iostream>
#include <fstream>
#include "Level.h"

/**
 * @class Mario
 * @brief Player character that navigates levels and interacts with entities.
 */
class Mario
{
public:
    /** @brief Constructor. @param startingLives Initial lives. @param totalLevels Number of levels. @param outputFilePath Log file path. */
    Mario(int startingLives, int totalLevels, const std::string &outputFilePath);
    
    /** @brief Destructor - closes output file. */
    ~Mario();
    
    /** @brief Get entity type at Mario's position. @return Entity code. */
    int getPositionType(int **currentLevel);
    
    /** @brief Move Mario in a random direction. */
    void move(int **currentLevel);
    
    /** @brief Get current lives. @return Number of lives. */
    int getLives();
    
    /** @brief Get current coins. @return Number of coins. */
    int getCoins();
    
    /** @brief Get current power level. @return Power level (0-2). */
    int getPowerLevel();
    
    /** @brief Collect a coin at current position. */
    void collectCoin(int **currentLevel);
    
    /** @brief Gain one life. */
    void gainLife();
    
    /** @brief Lose one life. */
    void loseLife();
    
    /** @brief Collect mushroom to increase power. */
    void getMushroom(int **currentLevel);
    
    /** @brief Decrease power level by 1. */
    void decreasePowerLevel();
    
    /** @brief Take damage (lose power or life). */
    void takeDamage();
    
    /** @brief Place Mario at random position. */
    void initializeRandomPosition();
    
    /** @brief Increment kill streak counter. */
    void increaseStreak();
    
    /** @brief Reset kill streak to 0. */
    void endStreak();
    
    /** @brief Fight a Goomba (80% win chance). */
    void fightGoomba(int **currentLevel);
    
    /** @brief Fight a Koopa (65% win chance). */
    void fightKoopa(int **currentLevel);
    
    /** @brief Fight the boss (50% win chance). */
    void fightBoss();
    
    /** @brief Run the game simulation. @param filename Input file. */
    void runGame(std::string filename);
    
    /** @brief Print the level grid to output file. */
    void printLevel(int **currentLevel, int arrSize, int currentLevelNumber);
    
    /** @brief Print Mario's current status. */
    void printMarioStatus(int currentLevel);
    
    /** @brief Move using Level reference. */
    void move(Level &currentLevel);
    
    /** @brief Generate random direction (0-3). @return Direction code. */
    int randomDirection();
    
    /** @brief Use warp pipe to advance level. */
    void warpPipe();
    
    Level level;  ///< Current level object

private:
    int lives;           ///< Current lives
    int coins;           ///< Current coins
    int powerLevel;      ///< Power level (0-2)
    int killStreak;      ///< Consecutive kills
    int marioX;          ///< X position
    int marioY;          ///< Y position
    bool gameOver;       ///< Game over flag
    int levelAmount;     ///< Total number of levels
    bool lose;           ///< Loss flag
    std::ofstream outputFile;  ///< Output log file
};
#endif
