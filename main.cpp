#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Person.cpp"
#include "Helper.cpp"
#include "FileReader.cpp"
#include "Phonebook.cpp"
#include "Validator.cpp"
using namespace std;

void printf(Person **arr, int count) {
    for ( int i = 0; i < count; i++)  {
        cout << arr[i]->name;
        cout << arr[i]-> surname;
        cout << arr[i]->separator;
        cout << arr[i]->phoneNumber;
    }
}

void removeFile(string dir_name)
{
    int len = dir_name.length();

    char *fileName = (char *)malloc(len + 1);

    for (int i = 0; i < len; i++)
    {
        fileName[i] = dir_name[i];
        fileName[len] = '\0';
    }

    remove(fileName);
}

string openFile()
{
    const string OPEN = "Enter the file name to open: ";
    string fileName;
    cout << OPEN;
    cin >> fileName;

    return fileName;
}

int main()
{
    FileReader phoneBookFile;
    Helper sortFunc;
    Validator valid;
    Phonebook contact;
    string fileOutputName = openFile();

    int count = phoneBookFile.fileCountLine(fileOutputName);
    phoneBookFile.filePrintLine(fileOutputName);

    Person **arr = contact.fileAddContact(fileOutputName, count);

    sortFunc.sort(arr, count);

    const string FILE_NAME = "PhoneBook.txt";
    removeFile(FILE_NAME);
    contact.addContentFile(arr, FILE_NAME, count);
    phoneBookFile.filePrintLine(FILE_NAME);

    valid.arrValid(arr, count);

    return 0;
}
