#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Person
{
public:
    string name;
    string surname;
    string separator;
    string phoneNumber;
};

class Helper
{
public:
    Person **sortName(Person **arr, string sign, string elem, int count)
    {
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count - 1 - i; j++)
            {
                bool tmp;
                if (sign == "Ascending")
                {
                    if (elem == "Surname")
                    {
                        tmp = arr[j]->surname[0] > arr[j + 1]->surname[0];
                    }
                    else
                    {
                        tmp = arr[j]->name[0] > arr[j + 1]->name[0];
                    }
                }
                else if (sign == "Descending")
                {
                    if (elem == "Surname")
                    {
                        tmp = arr[j]->surname[0] < arr[j + 1]->surname[0];
                    }
                    else
                    {
                        tmp = arr[j]->name[0] < arr[j + 1]->name[0];
                    }
                }
                else
                {
                    cout << "Error";
                }
                if (tmp)
                {
                    Person *x = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = x;
                }
            }
        }
        return arr;
    }

    Person **sortPhoneNumber(Person **arr, string sign, int count)
    {
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count - 1 - i; j++)
            {
                bool tmp;
                if (sign == "Ascending")
                {
                    tmp = arr[j]->phoneNumber[0] > arr[j + 1]->phoneNumber[0] ||
                          arr[j]->phoneNumber[1] > arr[j + 1]->phoneNumber[1] ||
                          arr[j]->phoneNumber[2] > arr[j + 1]->phoneNumber[2];
                }
                else if (sign == "Descending")
                {
                    tmp = arr[j]->phoneNumber[0] < arr[j + 1]->phoneNumber[0] ||
                          arr[j]->phoneNumber[1] < arr[j + 1]->phoneNumber[1] ||
                          arr[j]->phoneNumber[2] < arr[j + 1]->phoneNumber[2];
                }
                if (tmp)
                {
                    Person *x = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = x;
                }
            }
        }
        return arr;
    }

    void sort(Person **arr, int count)
    {
        string x;
        string y;
        cout << "Please choose an ordering to sort: 'Ascending' or 'Descending'." << endl;
        cin >> x;
        if (x == "Ascending" || x == "Descending")
        {
            cout << "Please choose criteria: 'Name', 'Surname' or 'PhoneNumberCode'." << endl;
            cin >> y;
            cout << endl;
            if (y == "Name" || y == "Surname")
            {
                sortName(arr, x, y, count);
            }
            else if (y == "PhoneNumberCode")
            {
                sortPhoneNumber(arr, x, count);
            }
            else
            {
                cout << endl
                     << "Sorting failed" << endl;
                cout << endl;
            }
        }
        else
        {
            cout << endl
                 << "Sorting failed" << endl;
            cout << endl;
        }
    }
};

class File : public Helper
{
public:
    int fileLine(string fileName)
    {
        fstream myFile;
        int count = 0;
        string line;

        myFile.open(fileName, ios::in);
        if (myFile.is_open())
        {
            while (getline(myFile, line))
            {
                count++;
            }
        }
        myFile.close();
        return count;
    }

    void readfile(string fileName)
    {
        fstream myFile;
        cout << "File Structure:" << endl;
        myFile.open(fileName, ios::in);
        if (myFile.is_open())
        {
            string line;
            while (getline(myFile, line))
            {
                cout << line << endl;
            }
            myFile.close();
        }
        cout << endl;
    }

    void addFile(Person **arr, string fileName, int count)
    {
        fstream myFile;
        myFile.open(fileName, ios::app);
        if (myFile.is_open())
        {
            string line;
            for (int i = 0; i < count; i++)
            {
                myFile << arr[i]->name << " ";
                myFile << arr[i]->surname << " ";
                myFile << arr[i]->separator << " ";
                myFile << arr[i]->phoneNumber << " " << endl;
            }
            myFile.close();
        }
    }
};

Person *person(string name, string surname, string separator, string phoneNumber)
{
    Person *obj = new Person();
    obj->name = name;
    obj->surname = surname;
    obj->separator = separator;
    obj->phoneNumber = phoneNumber;
    return obj;
}

void validation(Person **arr, int count)
{
    cout << "Validation:" << endl;
    for (int i = 0; i < count; i++)
    {
        if ((arr[i]->separator != ":" && arr[i]->separator != "-") && arr[i]->phoneNumber.length() != 9)
        {
            cout << "line " << i + 1 << ": phone number should be with 9 digits, the separator should be `:` or `-`." << endl;
        }
        else if (arr[i]->separator != ":" && arr[i]->separator != "-")
        {
            cout << "line " << i + 1 << ": separator should be `:` or `-`." << endl;
        }
        else if (arr[i]->phoneNumber.length() != 9)
        {
            cout << "line " << i + 1 << ": phone number should be 9 digits." << endl;
        }
    }
}

Person **fileOutputText(string fileName)
{
    fstream myFile;
    Person **arr = new Person *[12];
    myFile.open(fileName, ios::in);

    string line;
    static int i = 0;
    while (getline(myFile, line))
    {
        Person *obj = new Person();
        stringstream ss(line);
        getline(ss, obj->name, ' ');
        getline(ss, obj->surname, ' ');
        getline(ss, obj->separator, ' ');
        getline(ss, obj->phoneNumber, ' ');

        arr[i] = obj;
        i++;
    }
    myFile.close();

    return arr;
}

void removeFile()
{
    char fileName[] = "PhoneNumber.txt";
    remove(fileName);
}

string openFile(){
    string fileName;
    cout << "Enter the file name to open: ";
    cin >> fileName;

    return fileName;
}

int main()
{
    File sample;
    int count;
    string fileOutputName;

    fileOutputName = openFile();
    
    count = sample.fileLine(fileOutputName);
    sample.readfile(fileOutputName);

    Person **arr = fileOutputText(fileOutputName);

    sample.sort(arr, count);

    removeFile();
    string fileName = "PhoneNumber.txt";
    sample.addFile(arr, fileName, count);
    sample.readfile(fileName);

    validation(arr, count);
    return 0;
}
