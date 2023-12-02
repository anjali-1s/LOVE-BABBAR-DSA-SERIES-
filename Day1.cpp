#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;


int main() {
              
              // creation
              unordered_map <string,int> m;
              

              // way of insertion
              // 1---->>
              pair <string,int> p = make_pair("Anjali",2);
              m.insert (p);

              // 2--->>
              pair<string,int>pair2 ("Anjali",3);
              m.insert(pair2);

              // 3---->>
              m["Divya"] = 1;

             // What will happen ?
              m["Divya"] = 2;

             // searching ways 
             // 1---->>>
             cout << m["Anjali"] <<endl;

             // 2---->>>
             cout << m.at("Divya") <<endl;

             //cout << m.at("unknownkey") <<endl;
             cout << m ["unknownkey"] <<endl;
             //cout << m.at("unknownkey") <<endl;

             // size
             cout <<m.size() <<endl;

            // check presence
            cout <<m.count("Anjali") <<endl;
            cout <<m.count("Damon") <<endl;

            // Erase
             m.erase("Anjali");
             cout <<m.size() <<endl;

             // Access map
             for (auto i : m) 
             cout <<i.first <<" " << i.second << endl;

             // Iterators 
             unordered_map <string,int> :: iterator it = m.begin();

             while (it != m.end()) {
               cout << it -> first <<" " << it->second <<endl;
               it++;
             }


             return 0;
}
