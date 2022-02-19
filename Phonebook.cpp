#include "Phonebook.h"
#include "Person.h"
#include <fstream>
#include <sstream>

void Phonebook::addLineInArr(Person **arr, int count, fstream &myFile)
{
    for (int i = 0; i < count; i++)
    {
        myFile << arr[i]->name << " ";
        myFile << arr[i]->surname << " ";
        myFile << arr[i]->separator << " ";
        myFile << arr[i]->phoneNumber << " " << endl;
    }
}

void Phonebook::addContentFile(Person **arr, string fileName, int count)
{
    fstream myFile;
    myFile.open(fileName, ios::app);
    if (myFile.is_open())
    {
        string line;

        addLineInArr(arr, count, myFile);
        myFile.close();
    }
}

void Phonebook::addLineInObj(Person *obj, string line)
{
    stringstream ss(line);
    getline(ss, obj->name, ' ');
    getline(ss, obj->surname, ' ');
    getline(ss, obj->separator, ' ');
    getline(ss, obj->phoneNumber, ' ');
}

Person **Phonebook::fileAddContact(string fileName, int count)
{
    fstream myFile;
    Person **arr = new Person *[count];
    myFile.open(fileName, ios::in);

    string line;
    int i = 0;
    while (getline(myFile, line))
    {
        Person *obj = new Person("", "", "", "");
        addLineInObj(obj, line);

        arr[i] = obj;
        i++;
    }
    myFile.close();

    return arr;
}
