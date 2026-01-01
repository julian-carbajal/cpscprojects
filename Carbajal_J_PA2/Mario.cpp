#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Level.h"
#include "Mario.h"

Mario::Mario(int startingLives, int totalLevelCount, const std::string& outputFilePath)
    : lives(startingLives), levelAmount(totalLevelCount), coins(0), powerLevel(0), 
      killStreak(0), marioX(0), marioY(0), gameOver(false), lose(false)
{
    outputFile.open(outputFilePath);
    if (!outputFile) {
        throw std::runtime_error("Failed to open output file.");
    }
}

// Checks what's at Mario's current space
int Mario::getPositionType(int **currentLevel)
{
    return level.getAtIndex(currentLevel, marioX, marioY);
}



void Mario::move(Level &currentLevel)
{
    // move implementation
    int direction = randomDirection();


}

int Mario::randomDirection()
{
    return rand() % 4;  // 0=up, 1=down, 2=left, 3=right
}

int Mario::getLives()
{
    return lives;
}
int Mario::getCoins()
{
    return coins;
}
int Mario::getPowerLevel()
{
    return powerLevel;
}

void Mario::collectCoin(int **currentLevel)
{
    coins++;
    if (coins >= 20)
    {
        coins -= 20;
        gainLife();
    }
    currentLevel[marioX][marioY] = 5;
}

void Mario::gainLife()
{
    lives++;
}

void Mario::loseLife() {
    lives--;
    if (lives == 0) {
        gameOver = true;
    }
    outputFile << "Mario lost a life!" << (lives == 0 ? " Mario died!" : "") << std::endl;
}

void Mario::getMushroom(int **currentLevel)
{
    if (powerLevel < 2)
    {
        powerLevel++;
    }
    currentLevel[marioX][marioY] = 5;
}

void Mario::decreasePowerLevel()
{
    if (powerLevel > 0)
    {
        powerLevel--;
        outputFile << "Mario took damage!" << std::endl;
    }
}

void Mario::takeDamage()
{
    if (powerLevel > 0)
    {
        decreasePowerLevel();
    }
    else
    {
        loseLife();
    }
}


void Mario::initializeRandomPosition()
{
    int randomX = rand() % level.getArraySize();
    int randomY = rand() % level.getArraySize();
    marioX = randomX;
    marioY = randomY;
}

void Mario::increaseStreak()
{
    killStreak++;
    if (killStreak == 7)
    {
        endStreak();
        gainLife();
        outputFile << "Mario reached a 7 kill streak and earned an extra life!" << std::endl;
    }
}

void Mario::endStreak()
{
    killStreak = 0;
}

void Mario::fightGoomba(int **currentLevel)
{
    if (((std::rand() % 100) + 1) >= 21)
    {
        increaseStreak();
        outputFile << "Mario killed the goomba!" << std::endl;
        currentLevel[marioX][marioY] = 5;
    }
    else
    {
        takeDamage();
        endStreak();
    }
}

// Prints all the info on current Mario
void Mario::printMarioStatus(int currentLevel)
{
    outputFile << "Level: " << currentLevel << "|| Mario is at position: (" << marioX << "," << marioY << "). Mario is at power level " << Mario::getPowerLevel() << ". Mario has " << Mario::getLives() << " lives left. Mario has " << Mario::getCoins() << " coins. ";
}

void Mario::warpPipe()
{
    gameOver = true;
}

void Mario::printLevel(int **levels, int size, int levelNum)
{
    // Ensure that there is a corresponding function or array that maps level integers to characters
    const std::string symbols = "cgmkbw.";
    // c = coin, g = goomba, m = mushroom, k = koopa, b = boss, w = warp pipe, . = nothing

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == marioY && j == marioX)
            {
                outputFile << "H ";
            }
            else
            {
                int symbolIndex = levels[j][i]; // Get the integer representing the entity at this position
                // Make sure the index is valid before accessing the symbols string
                if (symbolIndex >= 0 && symbolIndex < symbols.size())
                {
                    outputFile << symbols[symbolIndex] << ' ';
                }
                else
                {
                    outputFile << ". "; // If it's an invalid index, print a placeholder symbol
                }
            }
        }
        outputFile << '\n';
    }
    outputFile << "==========" << '\n';
    printMarioStatus(levelNum); // Make sure this function is defined
}

void Mario::fightKoopa(int **level)
{
    int koopaKillChance = (std::rand() % 100) + 1;
    if (koopaKillChance >= 36)
    {
        increaseStreak();
        level[marioX][marioY] = 5;
        outputFile << "Mario killed the koopa!\n";
    }
    else
    {
        takeDamage();
        endStreak();
    }
}

void Mario::fightBoss()
{
    if (((std::rand() % 100) + 1) >= 51)
    {
        increaseStreak();
        outputFile << "Mario killed the boss!" << std::endl;
        gameOver = true;
    }
    else
    {
        takeDamage();
        takeDamage();
        endStreak();
    }
}



void Mario::runGame(std::string filename) {
    // TODO: Implement game loop
    // This would read the level configuration and run the simulation
    outputFile << "Starting Mario game..." << std::endl;
}

Mario::~Mario()
{
    outputFile.close();
}
