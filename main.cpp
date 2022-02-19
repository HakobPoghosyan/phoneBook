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

Person *person(string name, string surname, string separator, string phoneNumber)
{
    Person *obj = new Person("", "", "", "");
    return obj;
}

void removeFile(string dir_name)
{
    char *fileName;
    int len = dir_name.length();

    fileName = (char *)malloc(len + 1);

    for (int i = 0; i < len; i++)
    {
        fileName[i] = dir_name[i];
        fileName[len] = '\0';
    }

    remove(fileName);
}

string openFile()
{
    const string open = "Enter the file name to open: ";
    string fileName;
    cout << open;
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

    const string fileName = "PhoneBook.txt";
    removeFile(fileName);
    contact.addContentFile(arr, fileName, count);
    phoneBookFile.filePrintLine(fileName);

    valid.arrValid(arr, count);

    return 0;
}
