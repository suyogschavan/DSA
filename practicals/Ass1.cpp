#include <iostream>
using namespace std;
class Record
{
private:
    string name;
    string phoneNo;

public:
    Record()
    {
        name = " ";
        phoneNo = " ";
    }
    Record(string name, string phoneNo)
    {
        this->name = name;
        this->phoneNo = phoneNo;
    }
    friend class TelephoneBook;
};
class TelephoneBook
{
private:
    Record hashTable[100];

    int hashingFunction(string &name)
    {
        int count = 0;
        int len = name.length();
        for (int i = 0; i < len; i++)
        {
            name[i] = char(tolower(name[i]));
            count += (name[i] - 'a');
        }

        return (count % 100);
    }

public:
    TelephoneBook()
    {
        for (int i = 0; i < 100; i++)
        {
            hashTable[i].name = " ";
            hashTable[i].phoneNo = " ";
        }
    }

    void insert_without_replacement(string &name, string &phoneNo)
    {
        int key = hashingFunction(name);
        while (key < 100)
        {
            if (hashTable[key].name == " ")
            {
                hashTable[key].name = name;
                hashTable[key].phoneNo = phoneNo;
                cout << " Record inserted Successfully in the Telephone Book Database !!! " << endl;
                return;
            }

            if(hashTable[key].name==name)
            {
                cout<<" Record of "<<name<<" already exist in the Telephone Book Database. "<<endl;
                char ch='n';
                cout<<" Do you want to update the Phone-Number ? (y/n) : ";
                cin>>ch;
                if(ch=='y')
                {
                    hashTable[key].phoneNo = phoneNo;
                    cout << " Record inserted Successfully in the Telephone Book Database !!! " << endl;
                    return;
                }
            }

            key++;
            if (key == 100)
            {
                key = key % 100;
            }
        }
    }

    void insert_with_replacement(string &name, string &phoneNo)
    {
        int key = hashingFunction(name);

        if (hashTable[key].name == " ")
        {
            hashTable[key].name = name;
            hashTable[key].phoneNo = phoneNo;
            cout << " Record inserted Successfully in the Telephone Book Database !!! " << endl;
            return;
        }
        else
        {
            int newKey = hashingFunction(hashTable[key].name);
            if (newKey = key)
            {
                insert_without_replacement(name, phoneNo);
            }
            else
            {
                string tempName = hashTable[key].name;
                string tempPhoneNo = hashTable[key].phoneNo;
                hashTable[key].name = name;
                hashTable[key].phoneNo = phoneNo;

                insert_without_replacement(tempName, tempPhoneNo);
            }
        }
    }

    void searchRecord(string &name)
    {
        int key = hashingFunction(name);
        if (hashTable[key].name == " ")
        {
            cout << " The Record of " << name << " doesn't exist in Telephone Book Database. " << endl;
            return;
        }

        int comparisons_count = 0;
        int index = key;
        while ((key < 100) && (comparisons_count!=100))
        {
            comparisons_count++;
            if (hashTable[key].name == name)
            {
                cout << " The Phone-Number of " << name << " is : " << hashTable[key].phoneNo << endl;
                cout << " Number of comparisons made to search " << name << " is : " << comparisons_count << endl;
                return;
            }

            key++;
            if (key == 100)
            {
                key = key % 100;
            }
        }

        cout << " Record not Found in the Telephone Book Database. " << endl;
    }
};
int main()
{
    TelephoneBook obj;
    int option;
    cout << " ---------------- Menu ---------------- " << endl;
    cout << " 1. Linear probing without replacement " << endl;
    cout << " 2. Linear probing with repalcement " << endl;
    cout << "Enter the option : ";
    cin >> option;
    string name;
    string phoneNo;
    if (option == 1)
    {
        do
        {
            cout << endl;
            cout << " ---------------- Menu ---------------- " << endl;
            cout << " 1. Insert the Name and Phone-Number in the Telephone Book Database " << endl;
            cout << " 2. Search the Phone-Number in the Telephone Book Database " << endl;
            cout << " 3. Exit " << endl;
            cout << "Enter the option : ";
            cin >> option;
            switch (option)
            {
            case 1:
                cout << " Enter the Name : ";
                cin >> name;
                cout << " Enter the Phone-Number of " << name << " : ";
                cin >> phoneNo;
                obj.insert_without_replacement(name, phoneNo);
                break;
            case 2:
                cout << " Enter the Name : ";
                cin >> name;
                obj.searchRecord(name);
                break;
            case 3:
                exit(0);
            }
            cout << endl;
        } while (option >= 1 && option <= 2);
    }
    else if (option == 2)
    {
        do
        {
            cout << endl;
            cout << " ---------------- Menu ---------------- " << endl;
            cout << " 1. Insert the Name and Phone-Number in the Telephone Book Database " << endl;
            cout << " 2. Search the Phone-Number in the Telephone Book Database " << endl;
            cout << " 3. Exit " << endl;
            cout << "Enter the option : ";
            cin >> option;
            switch (option)
            {
            case 1:
                cout << " Enter the Name : ";
                cin >> name;
                cout << " Enter the Phone-Number of " << name << " : ";
                cin >> phoneNo;
                obj.insert_with_replacement(name, phoneNo);
                break;
            case 2:
                cout << " Enter the Name : ";
                cin >> name;
                obj.searchRecord(name);
                break;
            case 3:
                exit(0);
            }
            cout << endl;
        } while (option >= 1 && option <= 2);
    }
    else
    {
        cout << " Invalid option " << endl;
    }
    return 0;
}