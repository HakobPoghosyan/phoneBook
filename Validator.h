#ifndef VALIDATOR_H
#define VALIDATOR_H

class Validator
{
public:
    const int phoneNumberLength = 9;

    bool validSepAndNumber(Person *contact);

    bool validSeparator(Person *contact);

    bool validPhoneNumber(Person *contact);

    bool isValid(Person **arr, int count);

    void arrValid(Person **arr, int count);
};

#endif
