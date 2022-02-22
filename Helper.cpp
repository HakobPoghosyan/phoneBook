#include "Helper.h"
#include "Person.h"
#include <iostream>
using namespace std;

const string ASCENDING = "Ascending";
const string DESCENDING = "Descending";
const string ORDER_SORT = "Please choose an ordering to sort: 'Ascending' or 'Descending'.";
const string CRITERIA = "Please choose criteria: 'Name', 'Surname' or 'PhoneNumberCode'.";
const string NAME_LITTERAL = "Name";
const string SURNAME_LITTERAL = "Surname";
const string PHONE_NUMBER_LITTERAL = "PhoneNumberCode";
const string ERROR = "Not correct value. Sorting failed";

void Helper::swap(Person **arr, int j)
{
    Person *elem = arr[j + 1];
    arr[j + 1] = arr[j];
    arr[j] = elem;
}

bool Helper::isAscOrDesc(string inputAscDesc)
{
    if (true)
    {
        return inputAscDesc == ASCENDING;
    }
    else
    {
        return inputAscDesc == DESCENDING;
    }
}

bool Helper::personProperty(Person *person1, Person *person2, string inputAscDesc, string propertyName)
{
    const bool ASC = isAscOrDesc(inputAscDesc);

    if (propertyName == NAME_LITTERAL)
    {
        return ASC ? person1->name > person2->name : person1->name < person2->name;
    }
    else if (propertyName == SURNAME_LITTERAL)
    {
        return ASC ? person1->surname > person2->surname : person1->surname < person2->surname;
    }
    else if (propertyName == PHONE_NUMBER_LITTERAL)
    {
        return ASC ? person1->phoneNumber > person2->phoneNumber : person1->phoneNumber < person2->phoneNumber;
    }
}

Person **Helper::personSorting(Person **arr, string inputAscDesc, string propertyName, int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (personProperty(arr[j], arr[j + 1], inputAscDesc, propertyName))
            {
                swap(arr, j);
            }
        }
    }
    return arr;
}

void Helper::sort(Person **arr, int count)
{
    string inputAscDesc;
    string propertyName;

    cout << ORDER_SORT << endl;
    cin >> inputAscDesc;
    if (inputAscDesc != ASCENDING && inputAscDesc != DESCENDING)
    {
        cout << endl
             << ERROR << endl;
        cout << endl;
    }
    else
    {
        cout << CRITERIA << endl;
        cin >> propertyName;
        cout << endl;
        if (propertyName == NAME_LITTERAL || propertyName == SURNAME_LITTERAL || propertyName == PHONE_NUMBER_LITTERAL)
        {
            personSorting(arr, inputAscDesc, propertyName, count);
        }
        else
        {
            cout << endl
                 << ERROR << endl;
            cout << endl;
        }
    }
}
