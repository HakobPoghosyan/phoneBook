#ifndef HELPER_H
#define HELPER_H
#include <string>

using namespace std;

class Helper
{
public:
    void swap(Person **arr, int j);

    bool isAscOrDesc(string inputAscDesc);

    bool personProperty(Person *person1, Person *person2, string inputAscDesc, string propertyName);

    Person **personSorting(Person **arr, string inputAscDesc, string propertyName, int count);

    Person **sortNameSurnameNumber(Person **arr, string inputAscDesc, string inputParam, int count);

    void sort(Person **arr, int count);
};

#endif
