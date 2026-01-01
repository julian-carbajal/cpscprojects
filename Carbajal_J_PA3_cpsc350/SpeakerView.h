#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include "MonoStack.h"
#include "FileProcessor.h"

using namespace std;

class SpeakerView
{
public:
    SpeakerView();
    SpeakerView(std::string inputFileName, char descendingOrder);
    virtual ~SpeakerView();
    int processSpaces(const string &str);
    void processHeights();

private:
    FileProcessor *fp;
    MonoStack<double> *stack;
    std::string m_speakerstring;
    int m_col;
    int m_row;
    char m_dOrder;
    bool isDescending;
    double **seats;
    static const int MAX_ROW = 25;
    static const int MAX_COL = 25;
};

#endif