#include "SpeakerView.h"
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <algorithm> 


SpeakerView::SpeakerView()
{
  m_col = 0;
  m_row = 0;
  m_speakerstring = "";
}



SpeakerView::SpeakerView(std::string fileName, char descendingOrder)
{
   
    if (fileName.empty()) {
        throw std::invalid_argument("Error: Input file name is empty");
    }

    
    fp = new FileProcessor(fileName);
    if (fp == nullptr) {
        throw std::runtime_error("Error: Failed to create FileProcessor object");
    }

    
    m_speakerstring = fp->processFile();
    if (m_speakerstring.empty()) {
        throw std::runtime_error("Error: Failed to process the input file");
    }

    
    m_row = fp->getNumberofLines();
    if (m_row <= 0) {
        throw std::runtime_error("Error: Invalid number of lines");
    }

   
    istringstream text(m_speakerstring);
    string line;
    if (getline(text, line)) {
       
        m_col = processSpaces(line) + 1;
        if (m_col <= 0) {
            throw std::runtime_error("Error: Invalid number of columns");
        }
    } else {
        throw std::runtime_error("Error: Failed to read the line from the input file");
    }

    
    m_dOrder = descendingOrder;
}


int SpeakerView::processSpaces(const std::string& str)
{
    int count = 0;

    if (str.empty()) {
        return count;
    }

    for (size_t i = 0; i < str.length(); ++i) {
        if (i >= str.length()) {
            break; 
        }
        if (str.at(i) == ' ') {
            ++count;
        }
    }

    return count;
}


SpeakerView::~SpeakerView()
{
    delete fp;
}

void SpeakerView::processHeights()
{
    try
    {
        if (m_speakerstring.empty())
        {
            throw std::runtime_error("Error: speakerstring is empty.");
        }

        
        double heights[MAX_ROW][MAX_COL] = {0}; 
        int actualRowCount = 0;

        std::istringstream text(m_speakerstring);
        std::string token;
        int row = 0, col = 0;

        
        while (text >> token)
        {
            if (col >= MAX_COL || row >= MAX_ROW)
            {
                throw std::runtime_error("Error: Row or column limit exceeded.");
            }

            heights[row][col] = std::stod(token);
            col++;
            if (col == m_col)
            {
                col = 0;
                row++;
            }
        }
        actualRowCount = row; 

        bool isDescending = (m_dOrder == 'D' || m_dOrder == 'd'); 

        
        // For each column, determine who can see the speaker
        // People in the BACK rows need to see over people in FRONT rows
        // Row 0 is closest to speaker (front), higher rows are further back
        for (int currCol = 0; currCol < m_col; ++currCol)
        {
            double visibleHeights[MAX_ROW] = {0.0};
            int visibleCount = 0;
            double maxHeightSoFar = 0.0;  // Track tallest person in front

            // Process from front (row 0) to back
            for (int i = 0; i < actualRowCount; ++i)
            {
                double currentHeight = heights[i][currCol];
                
                // Person can see if they're taller than everyone in front of them
                if (i == 0 || currentHeight > maxHeightSoFar)
                {
                    visibleHeights[visibleCount++] = currentHeight;
                }
                
                // Update max height for people behind this row
                if (currentHeight > maxHeightSoFar)
                {
                    maxHeightSoFar = currentHeight;
                }
            }

            std::cout << "In column " << currCol << " there are " << visibleCount << " person(s) who can see. Their heights are: ";
            for (int i = 0; i < visibleCount; ++i)
            {
                std::cout << visibleHeights[i] << (i < visibleCount - 1 ? ", " : ".\n");
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
