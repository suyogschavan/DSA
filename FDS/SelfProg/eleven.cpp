/*Queues are frequently used in computer programming, 
and a typical example is the creation of a job queue 
by an operating system. If the operating system does 
not use priorities, then the jobs are processed in the
 order they enter the system. 
 Write C++ program for simulating job queue. 
 Write functions to add job and delete job from queue.*/

 #include<iostream>
 #include<queue>
 using namespace std;

int main(){
    queue<string> job;
    int ch;
    do
    {
    cout<<"Enter the choice: "<<endl;
    cout<<"1. Add JOB"<<endl;
    cout<<"2. Delete JOB "<<endl;
    cout<<"3. View Last JOB "<<endl;
    cout<<"4. View First JOB "<<endl;
    cout<<"5. View all JOBs"<<endl;
    cout<<"6. EXIT"<<endl;
    cin>>ch;
        switch (ch)
        {
        case 1:
            {string j;
            cout<<"Enter the job to add: "<<endl;
            cin>>j;
            job.push(j);
            cout<<"JOB added to queue"<<endl;
            }
            break;
        
        case 2:
            {job.pop();
            cout<<"JOB deleted"<<endl;
            break;}

        case 3:
            {cout<<"Last JOB: "<<job.back()<<endl;
            break;}
        
        case 4:{cout<<"First JOB: "<<job.front()<<endl;
        break;}
        }
    } while (ch!=6);
    
    

}