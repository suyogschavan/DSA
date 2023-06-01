#include<iostream>
using namespace std;

class heap{
    public:
    int *marks, *max_heapp;
    int capacity;

    void getData(){
        cout<<"Enter the number of students: ";
        cin>>capacity;
        marks = new int[capacity];
        cout<<"Enter the marks: "<<endl;
        for (int i = 0; i < capacity; i++)
        {
            cin>>marks[i];
        }
    }

    int parent(int a){
        return (a-1)/2;
    }

    void swap(int a, int b){
        int temp;
        temp = a;
        a = b; 
        b = temp;
    }
    void gererate(){
        max_heapp = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            max_heapp[i] = marks[i];
            int j = i;
            while(j!=0 && max_heapp[j]>max_heapp[parent(j)]){
                swap(max_heapp[j], max_heapp[parent(j)]);
                j = parent(j);
            }
        }
        
    }

    void display(){
        for (int i = 0; i < capacity; i++)
        {
            cout<<max_heapp[i]<< " ";
        }
        
    }
};

int main(){
    heap h;
    h.getData();
    h.gererate();
    h.display();
}