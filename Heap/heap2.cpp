#include<iostream>
using namespace std;

void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

class heap{
    public:
    int *marks, *minHeap, *maxHeap;
    int capacity;
    int no_of_marks;

    heap(int cap){
        capacity = cap;
        no_of_marks = 0;
        marks = new int[cap];
    }
    void getData(){ 
        cout<<"Enter the marks"<<endl;
        for (int i = 0; i < capacity; i++)
        {
            no_of_marks++;
            cin>>marks[i];
        }
    }
    void convert_min(){
        minHeap = new int[capacity];
            for (int j = 0; j < capacity; j++)
            {
                minHeap[j]=marks[j];
                int i = j;
                while (i!=0 && minHeap[i]<minHeap[parent(i)])
                {
                    swap(minHeap[i], minHeap[parent(i)]);
                    i = parent(i);
                }
                
            }
        
    }
    void printHeap(){
        cout<<"MinHeap"<<endl;
        for (int i = 0; i < capacity; i++)
        {
            cout<<minHeap[i]<<" ";
        }
        cout<<endl;
        for (int i = 0; i < capacity; i++)
        {
            cout<<maxHeap[i]<<" ";
        }

        
    }
    void convert_max(){
        maxHeap = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            maxHeap[i]=marks[i];
            int i1 = i;
            while (i1!=0 && maxHeap[i1]>maxHeap[parent(i1)])
            {
                swap(maxHeap[i1], maxHeap[parent(i1)]);
                i1 = parent(i1);
            }
            
        }
        
    }
    int parent(int i){
        return (i-1)/2;
    }
    int minimumMarks(){
        return minHeap[0];
    }
    int maximumMarks(){
        return maxHeap[0];
    }

};

int main(){

    int n;
    cout<<"Enter the number of students: ";
    cin>>n;

    heap obj(n);
    obj.getData();
    obj.convert_min();
    obj.convert_max();
    obj.printHeap(); 
    cout<<" \nMinimum Marks : "<<obj.minimumMarks()<<endl;
    cout<<" \nMaximum Marks : "<<obj.maximumMarks()<<endl;

}