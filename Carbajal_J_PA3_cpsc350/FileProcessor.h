#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>
#include <iostream>

using namespace std;

class FileProcessor
{
public:
    FileProcessor();
    FileProcessor(std::string fileName);
    std::string processFile();
    int getNumberofLines();
    virtual ~FileProcessor();
    

private:
    std::string m_inputfileName;
};

#endif