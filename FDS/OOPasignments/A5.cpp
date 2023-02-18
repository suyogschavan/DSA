#include <iostream>
#include <limits>
using namespace std;

template <class T>

T selection_sort() // Template function
{
    T a[10];
    T temp;
    for (int i = 0; i < 7; i++) // Accepting elements
    {
        cout << "a[" << i << "]=";
        cin >> a[i];
    }

    for (int i = 0; i < 7; i++) // Sorting logic
    {
        for (int j = i + 1; j < 7; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for (int i = 0; i < 7; i++) // Displaying logic
    {
        cout << a[i] << "\n";
    }
}

int main()
{

    cout << "Enter 6 elements for Integer sorting...\n";

    selection_sort<int>();

    cout << "Enter 6 elements for Floating sorting...\n";

    selection_sort<float>();
}
