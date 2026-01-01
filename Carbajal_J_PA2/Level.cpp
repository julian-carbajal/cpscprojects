#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Level.h"

Level::Level() : levelData(nullptr), arraySize(0) {}

Level::Level(int arrSize) : levelData(nullptr), arraySize(arrSize) {}

// Function to create and fill a 2D array with random values
int **Level::GenerateLevel(int arrSize, int coins, int goombas, int mushroom, int nothing, int koopas, int warpPipe)
{
    int **my2DArr = new int *[arrSize];

    // Determines how many spaces have each entity
    int maxSpaces = arrSize * arrSize;
    int coinAmount = (coins * maxSpaces) / 100;
    int goombaAmount = (goombas * maxSpaces) / 100;
    int mushroomAmount = (mushroom * maxSpaces) / 100;
    int koopaAmount = (koopas * maxSpaces) / 100;
    int nothingAmount = (nothing * maxSpaces) / 100;
    int bossAmount = 1;
    int warpPipeAmount = warpPipe;
    arraySize = arrSize;
    int totalAmount = coinAmount + goombaAmount + mushroomAmount + koopaAmount + nothingAmount + bossAmount + warpPipeAmount;

    // Makes sure there are no more or no less entities placed than the maximum amount of spaces in the level
    while (totalAmount < maxSpaces)
    {
        nothingAmount++;
        totalAmount++;
    }

    while (totalAmount > maxSpaces)
    {
        nothingAmount--;
        totalAmount--;
    }

    int placeholder = 0;
    int iterations = 0;

    // Places each entity randomly in the level
    for (int i = 0; i < arrSize; i++)
    {

        my2DArr[i] = new int[arrSize];

        for (int j = 0; j < arrSize; j++)
        {

            iterations = 0;

            while (iterations < 1)
            {

                placeholder = (std::rand() % 7) + 1;

                switch (placeholder)
                {

                case 1:
                    if (coinAmount > 0)
                    {
                        coinAmount--;
                        my2DArr[i][j] = placeholder;
                        iterations++;
                    }
                    break;

                case 2:
                    if (goombaAmount > 0)
                    {
                        goombaAmount--;
                        my2DArr[i][j] = placeholder;
                        iterations++;
                    }
                    break;

                case 3:
                    if (mushroomAmount > 0)
                    {
                        mushroomAmount--;
                        my2DArr[i][j] = placeholder;
                        iterations++;
                    }
                    break;

                case 4:
                    if (koopaAmount > 0)
                    {
                        koopaAmount--;
                        my2DArr[i][j] = placeholder;
                        iterations++;
                    }
                    break;

                case 5:
                    if (nothingAmount > 0)
                    {
                        nothingAmount--;
                        my2DArr[i][j] = placeholder;
                        iterations++;
                    }
                    break;

                case 6:
                    if (bossAmount > 0)
                    {
                        bossAmount--;
                        my2DArr[i][j] = placeholder;
                        iterations++;
                    }
                    break;

                case 7:
                    if (warpPipeAmount > 0)
                    {
                        warpPipeAmount--;
                        my2DArr[i][j] = placeholder;
                        iterations++;
                    }
                    break;
                }
            }
        }
    }

    return my2DArr;
}

// Function to free the memory of the 2D array
void Level::DeleteArray(int **arr)
{
    if (arr == nullptr) {
        // It's safe to return if the array is nullptr, 
        // as we don't need to delete anything
        return;
    }

    for (int i = 0; i < arraySize; i++) {
        if (arr[i] != nullptr) {
            delete[] arr[i];
        }
    }

    delete[] arr;
}

int Level::getArraySize() const
{
    return arraySize;
}
int Level::getAtIndex(int **currentLevel, int currentX, int currentY) const
{
    return currentLevel[currentX][currentY];
}

Level::~Level(){
    DeleteArray(levelData);
}
