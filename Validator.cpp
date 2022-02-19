#include "Validator.h"
#include "Person.h"
#include <iostream>
using namespace std;

const string valid = "Validation:";
const string sLine = "line ";
const string valError1 = ": phone number should be with 9 digits, the separator should be `:` or `-`.";
const string valError2 = ": separator should be `:` or `-`.";
const string valError3 = ": phone number should be 9 digits.";
const string valSucces = "Validation is successful";
string sep1 = ":";
string sep2 = "-";
string strArr[2] = {sep1, sep2};
int arrLen = sizeof(strArr) / sizeof(strArr[0]);

const int phoneNumberLength = 9;

bool Validator::validSepAndNumber(Person *contact)
{
    return validSeparator(contact) && validPhoneNumber(contact);
}

bool Validator::validSeparator(Person *contact)
{
    for (int j = 0; j < arrLen; j++)
    {
        return (contact->separator != strArr[j] && contact->separator != strArr[j + 1]);
    }
}

bool Validator::validPhoneNumber(Person *contact)
{
    return (contact->phoneNumber.length() != phoneNumberLength);
}

void Validator::arrValid(Person **arr, int count)
{
    cout << valid << endl;
    int check = 0;
    for (int i = 0; i < count; i++)
    {
        if (validSepAndNumber(arr[i]))
        {
            cout << sLine << i + 1 << valError1 << endl;
        }
        else if (validSeparator(arr[i]))
        {
            cout << sLine << i + 1 << valError2 << endl;
        }
        else if (validPhoneNumber(arr[i]))
        {
            cout << sLine << i + 1 << valError3 << endl;
        }
        else
        {
            check++;
        }
    }
    if (check == count)
    {
        cout << valSucces << endl;
    }
}
