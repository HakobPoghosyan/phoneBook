#ifndef VALIDATOR_H
#define VALIDATOR_H

class Validator
{
public:
    const string valid = "Validation:";
    const string sLine = "line ";
    const string valError1 = ": phone number should be with 9 digits, the separator should be `:` or `-`.";
    const string valError2 = ": separator should be `:` or `-`.";
    const string valError3 = ": phone number should be 9 digits.";
    const string valSucces = "Validation is successful";
    string sep1 = ":";
    string sep2 = "-";

    const int phoneNumberLength = 9;

    bool validSepAndNumber(Person *contact);

    bool validSeparator(Person *contact);

    bool validPhoneNumber(Person *contact);

    void arrValid(Person **arr, int count);
};

#endif