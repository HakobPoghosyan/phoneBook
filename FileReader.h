#ifndef FILEREADER_H
#define FILEREADER_H
#include <string>

using namespace std;

class FileReader
{
public:
    const string structur = "File Structure:";

    int fileCountLine(string fileName);

    void filePrintLine(string fileName);
};

#endif