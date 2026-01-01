
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "FileProcessor.h"
#include "MonoStack.h"
#include <iostream>
#include <stdexcept>     
#include "SpeakerView.h" 



int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Usage: " << argv[0] << " <input file path> <monotonic direction ('d' for descending)>" << std::endl;
        return 1;
    }

    std::string inputFilePath = argv[1];
    char monotonicDirection = argv[2][0];

   
    if (monotonicDirection != 'd')
    {
        std::cerr << "Invalid monotonic direction. Currently, only 'd' for descending is supported." << std::endl;
        return 1;
    }

    try
    {
        SpeakerView sv(inputFilePath, monotonicDirection);
        sv.processHeights(); 
        
        
        
    }
    catch (const std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
