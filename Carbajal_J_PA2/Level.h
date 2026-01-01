/**
 * @file Level.h
 * @brief Represents a single level in the Mario game simulation.
 * 
 * ARCHITECTURE:
 *   Level (You are here) - Generates and manages a 2D grid level
 *       ^
 *       |
 *   Mario - Uses Level to navigate and interact with entities
 *       ^
 *       |
 *   main.cpp - Entry point
 * 
 * LEVEL ENTITIES (represented as integers):
 *   1 = Coin (c)
 *   2 = Goomba (g)
 *   3 = Mushroom (m)
 *   4 = Koopa (k)
 *   5 = Nothing/Empty (.)
 *   6 = Boss (b)
 *   7 = Warp Pipe (w)
 * 
 * @author Julian Carbajal
 * @date Spring 2024
 */

#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>

/**
 * @class Level
 * @brief Manages a 2D grid level with randomly placed entities.
 */
class Level
{
public:
    /** @brief Default constructor. */
    Level();
    
    /** @brief Constructor with array size. @param arrSize Grid dimension (arrSize x arrSize). */
    Level(int arrSize);
    
    /** @brief Destructor - frees level data. */
    ~Level();
    
    /** @brief Generate a level with specified entity percentages. @return 2D array of entity codes. */
    int **GenerateLevel(int arrSize, int coins, int goombas, int mushroom, int nothing, int koopas, int warpPipe);
    
    /** @brief Free memory for a 2D array. @param arr Array to delete. */
    void DeleteArray(int **arr);
    
    /** @brief Get entity at position. @return Entity code at (currentX, currentY). */
    int getAtIndex(int **currentLevel, int currentX, int currentY) const;
    
    /** @brief Get the grid size. @return Array dimension. */
    int getArraySize() const;
    
    /** @brief Get the level data array. @return Pointer to 2D array. */
    int** getLevelData() const;
    
    /** @brief Remove entity at position (set to empty). */
    void removeEntityAt(int x, int y);

private:
    int **levelData;   ///< 2D array storing entity codes
    int arraySize;     ///< Dimension of the grid
};

#endif
