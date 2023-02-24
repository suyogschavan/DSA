/* ================================================== 
 Description     : Maximum frequency count (HASHMAP)
 Author          : Suyog Chavan
 Reach me here   : https://suyogschavan.github.io 
 Date of creation: Saturday, 18 Feb 2023 
 Copyright       : ©suyogschavan03@gmail.com
================================================== */

#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){

    // Creation
    unordered_map<string, int> m;
// --------------------------------------------------

    // Insertion

        // way1
        pair<string,int> p = make_pair("Zoro", 3);
        m.insert(p);

        // way2
        pair<string,int> pair2("Kakashi", 2);
        m.insert(pair2);

        // way3
        m["Livi"] = 3;

// --------------------------------------------------
    // Display
        
        // single element by key
        cout<<m["Livi"]<<endl;

        // for all elements -- for loop

        // display size of map
        cout<<m.size()<<endl;
        
    // Find
    if (m["unknown"]!=0)
        cout<<"Present"<<endl;
    else
        cout<<"NOT present"<<endl;
    
// --------------------------------------------------
    // Delete
    m.erase("Zoro");
    cout<<m["Zoro"]<<endl; // returns zero coz the key dosen't exists now
    


    return 0;
}