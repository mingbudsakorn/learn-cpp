#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string,int> mp = {{"a",10},{"b",3},{"c",4}};
    mp["one"] = 1;
    mp["two"] = 2;
    mp["three"] = 3;

    for(pair<string,int> p : mp){
        cout << p.first << " " << p.second << endl;
    }

}