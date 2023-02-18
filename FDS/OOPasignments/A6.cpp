#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Item
{
public:
    char name[100];
    int quantity;
    int cost;
    int code;
    bool operator==(const Item &i1)
    {
        return (code == i1.code);
    }
    bool operator<(const Item &i1)
    {
        return (code < i1.code);
    }
};
vector<Item> o1;
void print(Item &i1);
void display();
void insert();
void search();
bool compare(const Item &i1, const Item &i2)
{
    return i1.cost < i2.cost;
}
int main()
{
    int ch;
    do
    {
        cout << "\n*** Menu ***";
        cout << "\n1.Insert";
        cout << "\n2.Display";
        cout << "\n3.Search";
        cout << "\n4.Sort";
        cout << "\n5.Exit";
        cout << "\nEnter your choice:";
        cin >> ch;

        switch (ch)
        {
        case 1:
            insert();
            break;

        case 2:
            display();
            break;

        case 3:
            search();
            break;

        case 4:
            sort(o1.begin(), o1.end(), compare);
            cout << "\n\n Sorted on Cost";
            display();
            break;

        case 5:
            exit(0);
            break;
        }

    } while (ch != 6);
    return 0;
}
void insert()
{
    Item i1;
    cout << "\nEnter Item Name:";
    cin >> i1.name;
    cout << "\nEnter Item Quantity:";
    cin >> i1.quantity;
    cout << "\nEnter Item Cost:";
    cin >> i1.cost;
    cout << "\nEnter Item Code:";
    cin >> i1.code;
    o1.push_back(i1);
}
void display()
{
    for_each(o1.begin(), o1.end(), print);
}
void print(Item &i1)
{
    cout << "\n";
    cout << "\nItem Name:" << i1.name;
    cout << "\nItem Quantity:" << i1.quantity;
    cout << "\nItem Cost:" << i1.cost;
    cout << "\nItem Code:" << i1.code;
}
void search()
{
    vector<Item>::iterator p;
    Item i1;
    cout << "\nEnter Item Code to search:";
    cin >> i1.code;
    p = find(o1.begin(), o1.end(), i1);
    if (p == o1.end())
    {
        cout << "\nNot found.";
    }
    else
    {
        cout << "\nFound." << endl;
        cout << "Item Name : " << p->name << endl;
        cout << "Item Quantity : " << p->quantity << endl;
        cout << "Item Cost : " << p->cost << endl;
        cout << "Item Code: " << p->code << endl;
    }
}