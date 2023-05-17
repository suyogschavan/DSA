#include<iostream>
#include<string>

#define N 20

#define SERIOUS 10
#define NONSERIOUS 5
#define CHECKUP 1

using namespace std;
string Q[N];  //Size of Queue
int Pr[N];   //FOR CATAGORY OF Patient 
int r = -1,f = -1;
void enqueue(string name,int p)//Enqueue function to insert data and its priority in queue
{
	int i;
	if((f==0)&&(r==N-1)) //Check if Queue is full
		cout<<"Queue is full";
	else {
		if(f==-1) { //if Queue is empty
			f = r = 0;
			Q[r] = name;         //FIRST ENTRY
			Pr[r] = p;           //FIRST ENTRY

		}
	
		else {      //second patient onwards
			for(i = r;i>=f;i--) {
				if(p>Pr[i]) //if priority of the new patient is > exixting patient then shift the existing patient one place right
				{
					Q[i+1] = Q[i];
					Pr[i+1] = Pr[i];	
				}
				else break;
			}
			Q[i+1] = name;
			Pr[i+1] = p;
			r++;
		}	
	}

}
void print() { //print the data of Queue
	int i;
	for(i=f;i<=r;i++) {
		cout << "Patient's Name - "<<Q[i];
		switch(Pr[i]) {
			case 1: 
				cout << " Priority - 'Checkup' " << endl;
			break;
			case 5:
				cout << " Priority - 'Non-serious' " << endl;
			break;
			case 10:
				cout << " Priority - 'Serious' " << endl;
			break;
			default:
				cout << "Priority not found" << endl;
		}
	}
}

void dequeue() { //remove the data from front
	if(f == -1) {
		cout<<"Queue is Empty";
	}	
	else {
	cout<<"deleted Element ="<<Q[f]<<endl;
	cout<<"Its Priority = "<<Pr[f]<<endl;
		if(f==r) f = r = -1;
		else f++;
	}
}

int main() 
{
	string name;
	int opt,n,i,p;
	cout<<"Enter Your Choice:-"<<endl;
	do {
	cout << "Enter 1 for Inserting the Data in Queue" << endl << "Rnter 2 for showing the Data in Queue " << endl << "Enter 3 for Deleting the data from the Queue" 
		<< endl << "Enter 0 to Exit"<< endl;
	cin >> opt;
		switch(opt) 
		{
			case 1:
				cout << "Enter the number of patinent" << endl;
				cin >> n;
				i = 0;
				while(i < n) 
				{
					cout << "Enter your name of the patient : ";
					cin >> name;
					ifnotdoagain: 
						cout << "Enter your Prioritys (0: Serious, 1: Non-serious, 2: General checkup) : ";
						cin >> p;
						switch(p) {
							case 0: 
								enqueue(name,SERIOUS);
							break;
							case 1: 
								enqueue(name,NONSERIOUS);
							break;
							case 2: 
								enqueue(name,CHECKUP);
							break;
							default:
								goto ifnotdoagain;
						}
						
					i++;
				}
			break;
			case 2:
				print();
			break;
			case 3:
				 dequeue();
			break;
			case 0:
				cout << "Bye Bye !" << endl;
			break;
			default:
			cout<<"Incorrect Choice"<<endl;

		}
	}while(opt!=0);
        return 0;
}




