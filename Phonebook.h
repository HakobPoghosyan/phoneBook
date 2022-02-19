#ifndef PHONEBOOK_H
#define PHONEBOOK_H

class Phonebook
{
public:
    void addLineInArr(Person **arr, int count, fstream &myFile);

    void addContentFile(Person **arr, string fileName, int count);

    void addLineInObj(Person *obj, string line);

    Person **fileAddContact(string fileName, int count);
};

#endif