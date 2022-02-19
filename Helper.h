#ifndef HELPER_H
#define HELPER_H
#include <string>

using namespace std;

class Helper
{
public:
    const string ascending = "Ascending";
    const string descending = "Descending";
    const string orderSort = "Please choose an ordering to sort: 'Ascending' or 'Descending'.";
    const string criteria = "Please choose criteria: 'Name', 'Surname' or 'PhoneNumberCode'.";
    const string sName = "Name";
    const string sSurname = "Surname";
    const string sPhoneNumberCode = "PhoneNumberCode";
    const string error = "Not correct value. Sorting failed";

    void swap(Person **arr, int i, int j);

    bool ascendingFunc(string inputAscDesc);

    bool descendingFunc(string inputAscDesc);

    bool inputSurnameFunc(string inputParam);

    bool inputPhoneNumberFunc(string inputParam);

    bool inputNameFunc(string inputParam);

    bool surnameAsc(Person *contact, Person *contact2);

    bool nameAsc(Person *contact, Person *contact2);

    bool surnameDesc(Person *contact, Person *contact2);

    bool nameDesc(Person *contact, Person *contact2);

    bool phoneNumberAsc(Person *contact, Person *contact2);

    bool phoneNumberDesc(Person *contact, Person *contact2);

    Person **sortNameSurnameNumber(Person **arr, string inputAscDesc, string inputParam, int count);

    void sort(Person **arr, int count);
};

#endif