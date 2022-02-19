#include "Helper.h"
#include "Person.h"
#include <iostream>
using namespace std;

const string ascending = "Ascending";
const string descending = "Descending";
const string orderSort = "Please choose an ordering to sort: 'Ascending' or 'Descending'.";
const string criteria = "Please choose criteria: 'Name', 'Surname' or 'PhoneNumberCode'.";
const string nameLitteral = "Name";
const string surnameLitteral = "Surname";
const string phoneNumberLitteral = "PhoneNumberCode";
const string error = "Not correct value. Sorting failed";

void Helper::swap(Person **arr, int i, int j)
{
    Person *elem = arr[j + 1];
    arr[j + 1] = arr[j];
    arr[j] = elem;
}

bool Helper::ascendingFunc(string inputAscDesc)
{
    return inputAscDesc == ascending;
}

bool Helper::descendingFunc(string inputAscDesc)
{
    return inputAscDesc == descending;
}

bool Helper::inputSurnameFunc(string inputParam)
{
    return inputParam == surnameLitteral;
}

bool Helper::inputPhoneNumberFunc(string inputParam)
{
    return inputParam == phoneNumberLitteral;
}

bool Helper::inputNameFunc(string inputParam)
{
    return inputParam == nameLitteral;
}

bool Helper::surnameAsc(Person *contact, Person *contact2)
{
    return contact->surname > contact2->surname;
}

bool Helper::nameAsc(Person *contact, Person *contact2)
{
    return contact->name > contact2->name;
}

bool Helper::surnameDesc(Person *contact, Person *contact2)
{
    return contact->surname < contact2->surname;
}

bool Helper::nameDesc(Person *contact, Person *contact2)
{
    return contact->name < contact2->name;
}

bool Helper::phoneNumberAsc(Person *contact, Person *contact2)
{
    return contact->phoneNumber > contact2->phoneNumber;
}

bool Helper::phoneNumberDesc(Person *contact, Person *contact2)
{
    return contact->phoneNumber < contact2->phoneNumber;
}

Person **Helper::sortNameSurnameNumber(Person **arr, string inputAscDesc, string inputParam, int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            bool AllowChanges;
            if (ascendingFunc(inputAscDesc))
            {
                if (inputSurnameFunc(inputParam))
                {
                    AllowChanges = surnameAsc(arr[j], arr[j + 1]);
                }
                else if (inputPhoneNumberFunc(inputParam))
                {
                    AllowChanges = phoneNumberAsc(arr[j], arr[j + 1]);
                }
                else if (inputNameFunc(inputParam))
                {
                    AllowChanges = nameAsc(arr[j], arr[j + 1]);
                }
            }
            else if (descendingFunc(inputAscDesc))
            {
                if (inputSurnameFunc(inputParam))
                {
                    AllowChanges = surnameDesc(arr[j], arr[j + 1]);
                }
                else if (inputPhoneNumberFunc(inputParam))
                {
                    AllowChanges = phoneNumberDesc(arr[j], arr[j + 1]);
                }
                else if (inputNameFunc(inputParam))
                {
                    AllowChanges = nameDesc(arr[j], arr[j + 1]);
                }
            }
            if (AllowChanges)
            {
                swap(arr, i, j);
            }
        }
    }
    return arr;
}

void Helper::sort(Person **arr, int count)
{
    string inputAscDesc;
    string inputParam;

    cout << orderSort << endl;
    cin >> inputAscDesc;
    if (inputAscDesc != ascending && inputAscDesc != descending)
    {
        cout << endl
             << error << endl;
        cout << endl;
    }
    else
    {
        cout << criteria << endl;
        cin >> inputParam;
        cout << endl;
        if (inputParam == nameLitteral || inputParam == surnameLitteral || inputParam == phoneNumberLitteral)
        {
            sortNameSurnameNumber(arr, inputAscDesc, inputParam, count);
        }
        else
        {
            cout << endl
                 << error << endl;
            cout << endl;
        }
    }
}
