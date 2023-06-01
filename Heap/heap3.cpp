#include<iostream>
using namespace std;
/*
Heap
minHeap: root always less than chlid
maxHeap: viceversa
parent = (child-1)/2
lchild = (parent*2)+1
rchild = (parent*2)+2
representation can be done by either ll or arr

*/
class heap{
    int *marks, *min_heap, *max_heap;
    int capacity;

    public:
    void get_marks(){
        int n;
        cout<<"Enter the number of students: ";
        cin>>n;
        capacity = n;
        marks = new int[n];
        cout<<"Enter the marks"<<endl;
        for (int i = 0; i < capacity; i++)
        {
            cin>>marks[i];
        }
    }

    int parent(int a){
        return (a-1)/2;
    }

    void swap(int &a, int &b){
        int temp;
        temp = a;
        a = b;
        b = temp;
    }

    void build_min(){
        min_heap = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            min_heap[i]=marks[i];
            int j = i;
            while (j!=0 && min_heap[j]<min_heap[parent(j)])
            {
                swap(min_heap[j], min_heap[parent(j)]);
                j = parent(j);
            }
        }   
    }
    void display(){
        for (int i = 0; i < capacity; i++)
        {
            cout<<min_heap[i]<< " ";
        }
        
    }


};

int main(){
    heap h;
    h.get_marks();
    h.build_min();
    h.display();
}