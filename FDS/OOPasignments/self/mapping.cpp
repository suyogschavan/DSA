#include <iostream>
#include <map>
#include <string>
using namespace std;

void allwork(map<string, int> m)
{
    string state;
    cout << "Enter the name of state: ";
    cin >> state;
    map<string, int>::iterator itr;
    for (itr = m.begin(); itr != m.end(); itr++)
    {
        if ((*itr).first == state)
        {
            cout << "Population of " << state << " is: " << (*itr).second << endl;
        }
    }
}
int main()
{
    map<string, int> m;
    m["Maharashtra"] = 1000000000;
    m["Gujrat"] = 30330303;
    m["Tamil Nadu"] = 30330303;
    m["Karnataka"] = 30330303;
    m["Kerala"] = 30330303;
    m["Zarkhand"] = 30330303;
    m["Odisa"] = 30330303;
    int ch;
    do
    {
        cout << "\n-----------population checker----------" << endl;
        allwork(m);
        cout << "You wan't to continue? (1 for Yes & 0 for No)" << endl;
        cin >> ch;
    } while (ch != 0 );
}