#include <iostream>
using namespace std;
#include <set>
#include <bits/stdc++.h>

int main() {
    //set
    //insert(), size(), empty(), clear(), swap()
    //count(), begin(), end()
    set<int> set1 = {1, 2, 3, 4 , 2};

    set<int,greater<int>> set2;

    set2.insert(1);
    set2.insert(3);
    set2.insert(20);
    set2.insert(8);

    set<int,greater<int>> set3 = {6,10,5,1,7};

    set<int,greater<int>> set4(set3);

    for (int e : set2) {
        cout << e << endl;
    }


    //unordered_set
    unordered_set<int> unset1 = {1, 2, 3, 7, 4 ,2};
    for (int e : unset1) {
        cout << e << endl;
    }

    return 0;
}
