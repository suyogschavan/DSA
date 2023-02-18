#include<iostream>
// #include<deque>
using namespace std;

class Queue{
    int *arr;
    int front;
    int rear;
    int size;
    public:
        Queue(){
            size=10001;
            arr = new int[size];
            front = 0;
            rear = 0;
        }

        bool isEmpty(){
            if (front==0)
            {
                return true;
            }else
            {
                return false;
            }
        }

        void enqueue(int data){
            if (rear==size)
            {
                cout<<"Queue Overflow"<<endl;
            }else
            {
                arr[rear]=data;
                rear++;
            }
        }

        void dequeue(){
            if (front==rear)
            {
                cout<<"UnderFlow error."<<endl;
                return -1;
            }else
            {
                arr[front]=-1;
                front++;
                if (front==rear)
                {
                    front=0;
                    rear = 0;
                }
                
            }
            
            
        }
}
