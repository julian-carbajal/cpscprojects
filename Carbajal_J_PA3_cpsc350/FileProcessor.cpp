#include "FileProcessor.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;



FileProcessor::FileProcessor() : m_inputfileName("") {}

FileProcessor::FileProcessor(std::string fileName)
{
    if (fileName.empty())
    {
        throw std::invalid_argument("Error: fileName is empty.");
    }
    m_inputfileName = fileName;
}

FileProcessor::~FileProcessor() {}

std::string FileProcessor::processFile()
{
    std::ifstream inputFile(m_inputfileName);
    if (!inputFile)
    {
        throw std::runtime_error("Error: Unable to open the file.");
    }

    std::string text, line;
    while (std::getline(inputFile, line))
    {
        text += line + '\n';
    }

    if (!inputFile.eof())
    {
        throw std::runtime_error("Error: Unable to read the file.");
    }

    inputFile.close();
    return text;
}

int FileProcessor::getNumberofLines()
{
    std::ifstream file(m_inputfileName);
    if (!file.is_open())
    {
        throw std::runtime_error("Error: Unable to open the file.");
    }

    int lineCount = 0;
    std::string line;
    while (getline(file, line))
    {
        ++lineCount;
    }

    file.close();
    return lineCount; 
}

