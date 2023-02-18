#include<iostream>
using namespace std;

template<class T>
T selectionSort(){
    int size;
    cout<<"Enter the size of arr.: ";
    cin>>size;

    T arr[size];
    for (int i = 0; i <size; i++)
    {
        cout<<"Enter arr["<<i<<"] : ";
        cin>>arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <size; j++)
        {
            if (arr[i]<arr[j])
            {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            
        }
        
    }

    cout<<"Sorted Array: "<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<endl;
    }
    
    
    
}

int main(){
    int ch;
    do
    {
        cout<<"\nWhat you wan't to do?"<<endl;
        cout<<"1. To sort INT array by selection sort."<<endl;
        cout<<"2. To sort FLOAT array by selection sort."<<endl;
        cout<<"3. To Exit the program."<<endl;
        cin>>ch;

        switch (ch)
        {
        case 1:
            selectionSort<int>();
            break;
        case 2:
            selectionSort<float>();
            break;
        
        case 3:exit(0);
        default:
            break;
        }
    } while (ch!=3);
    
    selectionSort<int>();
}