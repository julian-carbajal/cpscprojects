#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <fstream>

class FileProcessor
{
private:
    int int1, int2, int3, int4, int5, int6, int7, int8;

public:
    FileProcessor(const std::string &filename);
    int getInt1() const;
    int getInt2() const;
    int getInt3() const;
    int getInt4() const;
    int getInt5() const;
    int getInt6() const;
    int getInt7() const;
    int getInt8() const;
    int getInteger(int) const;
};

#endif // FILEPROCESSOR_H
