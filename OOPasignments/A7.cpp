#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main()
{
	typedef map<string,int> mapType;
	mapType populationMap;
	
	populationMap.insert(pair<string, float>("Maharashtra", 125));
	populationMap.insert(pair<string, float>("Gujrat", 225));
	populationMap.insert(mapType::value_type("Bihar", 120)); 
	
	mapType::iterator iter = --populationMap.end();
	populationMap.erase(iter);
	
	char c;
	do
	{
		string state;
		cout<<"\nEnter that state you want to know the population of: ";
		cin>>state;
		iter = populationMap.find(state);
		if( iter != populationMap.end() ) 
		    cout << state <<"'s populations is "
		        << iter->second << " million\n";
		else
		    cout << "State is not in populationMap" << '\n';
		    
		cout<<"Do you wish to continue?(y/n):";
		cin>>c;
	}while(c=='y'||c=='Y');
	 
	populationMap.clear();
	
	return 0;
}

