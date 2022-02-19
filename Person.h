#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person
{
public:
    string name;
    string surname;
    string separator;
    string phoneNumber;

    Person(string name, string surname, string separator, string phoneNumber);
};

#endif