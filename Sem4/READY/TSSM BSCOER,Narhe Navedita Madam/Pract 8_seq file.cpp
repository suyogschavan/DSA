
/* Group E - Assignment No. 23
Problem Statement- 
Department maintains a student information. The file contains roll number, name, division
and address. Allow user to add, delete information of student. Display information of
particular student. If record of student does not exist an appropriate message is displayed.
If it is, then the system displays the student details. Use sequential file to main the data.

*/

#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<iomanip>


using namespace std;

class student
{

string name,div,address;
int roll;
public:
 void getdata();
 void displayAll();
 void insert_record();
 void delete_record();
 void search_record();
};


void student::getdata()
{
 cout<<"\nEnter Roll No, Division, Name and Address of Student= ";
 cin>>roll>>div>>name>>address;
 
} 
void student::insert_record()
{
	fstream out;
	student *s1;
	s1=new student;
	out.open("Record11.txt",ios::app|ios::binary);
	
	s1->getdata();
	out.write((char *)&s1,sizeof(s1));
	
	out.close();
}

void student::displayAll()
{
	fstream out;
	student *s2;
	s2=new student;
	out.open("Record11.txt",ios::in|ios::binary);
	
	cout<<"\nThe Contents of file are.......\n\n";
	cout<<"\nROLL"<<setw(15)<<"Division"<<setw(15)<<"NAME"<<setw(15)<<"ADDRESS\n";
	
	while(out.read((char*)&s2,sizeof(s2)))
	{
		cout<<"\n"<<s2->roll<<setw(15)<<s2->div<<setw(15)<<s2->name<<setw(15)<<s2->address;
	}
	cout<<"\n";
	out.close();
}
void student::delete_record()
{
	fstream out,temp;
	student *s2;
	int item;
	s2=new student;
	out.open("Record11.txt",ios::in|ios::binary);
	temp.open("temp.txt",ios::out|ios::binary);
	cout<<"\nEnter Roll_No :";
	cin>>item;
	while(out.read((char*)&s2,sizeof(s2)))
	{
		    if(s2->roll!=item)
			{
				temp.write((char *)&s2,sizeof(s2));
			}
	}
	out.close();
	temp.close();
	
	remove("Record11.txt");
	rename("temp.txt","Record11.txt");
	
	
}
void student::search_record()
{
	int item,flag=0;
	student *s2;
	fstream out;
	out.open("Record11.txt",ios::in|ios::binary);
	s2=new student;
	cout<<"\nEnter Roll_No :";
	cin>>item;
	
	while(out.read((char*)&s2,sizeof(s2)))
	{
			if(s2->roll==item)
			{
				cout<<"\n Record is Present in the File....\n ";
				cout<<"\n"<<s2->roll<<"\t"<<s2->div<<"\t"<<s2->name<<"\t"<<s2->address;
				flag=1;
				break;
			}
		
	}
	if(flag==0)
	cout<<endl<<"Sorry .No such Record Present"<<endl;
	out.close();
}

int main()
{
	student t1;
	int ch;
    fstream out;
	out.open("Record11.txt",ios::out);
	out.close();
	while(1)
	{
		cout<<"\n*******  SEQUENTIAL ACCESS FILE PROGRAM USING C++ ********** \n\n";
		cout<<"\n1.INSERT RECORD\n2.DISPLAY All Records \n3.SEARCH\n4.Delete\n5.EXIT.";
		cout<<"\nEnter UR Choice : ";
		cin >> ch;
		switch(ch)
		{
		case 1:
			
 			t1.insert_record();
 	
			cout<<"\n\nRecord is Inserted..\n\n";
			break;
		case 2:
			t1.displayAll();
			break;
		case 3:
			t1.search_record();
			break;
		case 4:
			t1.delete_record();
			break;
		case 5:
			exit(0);
		}
	}
	return 0;
}

