#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Level.h"
#include "Mario.h"
#include "FileProcessor.h"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Need arguments for input file and output file" << std::endl;
        return 1; // Exit with an error code
    }

    std::string filename = argv[1];

    // Create a FileProcessor instance with the input file "input.txt"
    FileProcessor fileProcessor(filename);

    // Check if the file was opened successfully
    if (!fileProcessor.getInt1())
    {
        std::cerr << "File processing failed. Exiting..." << std::endl;
        return 1;
    }

    // Collects values from input file
    int levels = fileProcessor.getInt1();
    int size = fileProcessor.getInt2();
    int lives = fileProcessor.getInt3();
    int coins = fileProcessor.getInt4();
    int nothing = fileProcessor.getInt5();
    int goombas = fileProcessor.getInt6();
    int koopas = fileProcessor.getInt7();
    int mushrooms = fileProcessor.getInt8();

    Mario marioGame(lives, levels, argv[2]);

    // Makes sure the percentages add to 100 before running the game
    if ((coins + nothing + goombas + koopas + mushrooms) == 100)
    {
        marioGame.runGame(filename);
    }

    return 0;
}
