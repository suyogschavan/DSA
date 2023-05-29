#include<iostream>
using namespace std;

class heap{
    public:
    int size;
    int *marks, *min_heap;

    heap(){
        int s;
        cout<<"Enter the number of students : ";
        cin>>s;
        size = s;
        marks = new int[size];
        cout<<"Enter the marks: "<<endl;
        for (int i = 0; i < size; i++)
        {
            cin>>marks[i];
        }
    }

    // lower than the child
    void generateHeap();
    int maxinHeap();
    int mininHeap();
    void display(){
        for (int i = 0; i < size; i++)
        {
            cout<<min_heap[i]<<" ";
        }
        
    }
};

int parent(int d){
    return (d-1)/2;
}

void swap(int a, int b){
    int temp;
    temp = a;
    a=b;
    b=temp;
}


void heap::generateHeap(){
    min_heap = new int[size];
    for (int i = 0; i < size; i++)
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





// Maximum value
int heap::maxinHeap(){
    return min_heap[size-1];
}

// Minimum Value
int heap::mininHeap(){
    return min_heap[0];
}


int main(){
    heap obj;
    obj.generateHeap();
    obj.display();
    cout<<"Minimum of them all: ";
    cout<<obj.mininHeap();
    
}

