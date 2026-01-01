#include "FileProcessor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Level.h"
#include "Mario.h"
#include "FileProcessor.h"

// Opens input file
FileProcessor::FileProcessor(const std::string &filename)
{
    std::ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        std::cerr << "Failed to open the file: " << filename << std::endl;
        return;
    }

    inputFile >> int1 >> int2 >> int3 >> int4 >> int5 >> int6 >> int7 >> int8;

    if (inputFile.fail())
    {
        std::cerr << "Error reading integers from the file." << std::endl;
    }

    inputFile.close();
}

// Reads each value in the input file
int FileProcessor::getInt1() const
{
    return int1;
}

int FileProcessor::getInt2() const
{
    return int2;
}

int FileProcessor::getInt3() const
{
    return int3;
}

int FileProcessor::getInt4() const
{
    return int4;
}

int FileProcessor::getInt5() const
{
    return int5;
}

int FileProcessor::getInt6() const
{
    return int6;
}

int FileProcessor::getInt7() const
{
    return int7;
}

int FileProcessor::getInt8() const
{
    return int8;
}
