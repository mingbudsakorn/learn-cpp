#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> vec;
    for (int i = 0; i < n; i++) {
        vector<int> tempVec;
        for(int j = 0; j < n; j++) {
        int input;
        cin >> input;
        tempVec.push_back(input);

        }
        vec.push_back(tempVec);
        
    }
    int max = -1;
    for(int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                vec[i][j] = min(vec[i][j],vec[i][k]+vec[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (vec[i][j]>max) {
                    max = vec[i][j];
                }
            }
        }
    cout << "output: " << max;
    
}