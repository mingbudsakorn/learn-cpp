#include <bits/stdc++.h>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    vector<int> v = {1,5,8,0,15,14,16};


    vector<pair<int,int>> v2;
    v2.push_back(make_pair(1,3));
    v2.push_back(make_pair(1,2));
    v2.push_back(make_pair(2,1));

    // sort(v.begin(), v.end());
    // sort(v.begin(), v.end(), [] (int a, int b) {return a < b;});
    // sort(v.begin(), v.end(), compare);
    //(2,1) (1,2) (1,3) 
    sort(v2.begin(), v2.end(), [] (pair<int,int> a, pair<int,int> b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    });
    // for (auto e : v) {
    //     cout << e << " ";
    // }

    for (auto p : v2) {
        cout << "(" << p.first << "," << p.second << ")" << " ";
    }
}