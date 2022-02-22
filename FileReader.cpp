#include "FileReader.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string STRUCTUR = "File Structure:";

int FileReader::fileCountLine(string fileName)
{
    fstream myFile;
    int count = 0;
    string line;

    myFile.open(fileName, ios::in);
    if (myFile.is_open())
    {
        while (getline(myFile, line))
        {
            count++;
        }
    }
    myFile.close();
    return count;
}

void FileReader::filePrintLine(string fileName)
{
    fstream myFile;
    const string FILE_ERROR = "There is no file found";

    myFile.open(fileName, ios::in);
    if (myFile.is_open() == false)
    {
        cout << FILE_ERROR;
    }
    else
    {
        string line;
        cout << STRUCTUR << endl;
        while (getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
    }
    cout << endl;
}
