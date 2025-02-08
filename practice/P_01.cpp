#include <bits/stdc++.h>

using namespace std;
int main() {
    //mode or max

    // 6
    // 1 8 1 8 66 2
    // return max 66

    // 2 1 6 7
    //return max 7

    // 6
    // 1 8 1 8 66 8
    // return mode 8
    int n, temp, max, mode;
    int cMax = 0;

    map<int, int> m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        m[temp]++;

        if (i == 0) {
            max = temp;
        } 
        if (temp > max) {
            max = temp;
        }
        if (m[temp] > cMax) {
            cMax = m[temp];
            mode = temp;
        }
    }
    int countCMax = 0;
    for (auto p : m) {
        // cout << p.first << ": " << p.second << endl;
        if (p.second == cMax) {
            countCMax++;
        }
    }

    if (countCMax > 1) {
        cout << "max: " << max << endl;
    } else { 

        cout << "mode: " << mode << endl;
    }

    
}