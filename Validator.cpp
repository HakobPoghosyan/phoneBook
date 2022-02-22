#include "Validator.h"
#include "Person.h"
#include <iostream>
using namespace std;

const string VALIDATION = "Validations:";
const string LINE = "line ";
const string VAL_ERROR_1 = ": phone number should be with 9 digits, the separator should be `:` or `-`.";
const string VAL_ERROR_2 = ": separator should be `:` or `-`.";
const string VAL_ERROR_3 = ": phone number should be 9 digits.";
const string VAL_SUCCES = "Validation is successful";
const string VALID = "File is no valid";
const string NO_VALID = "File is valid";
string sep1 = ":";
string sep2 = "-";
string strArr[2] = {sep1, sep2};
int arrLen = sizeof(strArr) / sizeof(strArr[0]);
const int PHONE_NUMBER_LENGTH = 9;

bool Validator::validSepAndNumber(Person *contact)
{
    return validSeparator(contact) && validPhoneNumber(contact);
}

bool Validator::validSeparator(Person *contact)
{
    bool boolSep;

    for (int j = 0; j < arrLen; j++)
    {
        if (contact->separator != strArr[j])
        {
            boolSep = true;
        }
        else
        {
            boolSep = false;
            break;
        }
    }
    return boolSep;
}

bool Validator::validPhoneNumber(Person *contact)
{
    return (contact->phoneNumber.length() != PHONE_NUMBER_LENGTH);
}

bool Validator::isValid(Person **arr, int count)
{
    bool boolCheck;
    cout << VALIDATION << endl;
    for (int i = 0; i < count; i++)
    {
        if (validSepAndNumber(arr[i]))
        {
            cout << LINE << i + 1 << VAL_ERROR_1 << endl;
            boolCheck = true;
        }
        else if (validSeparator(arr[i]))
        {
            cout << LINE << i + 1 << VAL_ERROR_2 << endl;
            boolCheck = true;
        }
        else if (validPhoneNumber(arr[i]))
        {
            cout << LINE << i + 1 << VAL_ERROR_3 << endl;
            boolCheck = true;
        }
        else
        {
            boolCheck = false;
        }
    }
    return boolCheck;
}

void Validator::arrValid(Person **arr, int count)
{
    if (isValid(arr, count))
    {
        cout << NO_VALID << endl;
    }
    else
    {
        cout << VALID << endl;
    }
}
