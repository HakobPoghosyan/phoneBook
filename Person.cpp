#include "Person.h"
#include <string>

using namespace std;


Person::Person(string name, string surname, string separator, string phoneNumber)
{
    this->name = name;
    this->surname = surname;
    this->separator = separator;
    this->phoneNumber = phoneNumber;
}
