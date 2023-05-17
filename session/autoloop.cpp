#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<int, string>mp;
    mp.insert({7, "Suyog"});
    mp.insert({6, "Suyash"});
    mp.insert({4, "Third"});
    mp[5]="Soul";

    for(auto it:mp){
        cout<<it.first<<" , "<<it.second<<endl;
    }
}