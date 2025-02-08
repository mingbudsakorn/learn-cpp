#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; i<n; i++){
            int temp;
            cin >> temp;
            matrix[i][j] = temp;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; i<n; j++){
            for(int k=0; k<n; k++){
                matrix[j][k] = min(matrix[j][k], matrix[j][i]+matrix[i][k]);
            }
        }
    }
    int max = -99999;
    for(int i=0; i<n; i++){
        for(int j=0; i<n; j++){
            if(max < matrix[i][j]){
                max = matrix[i][j];
            }
        }
    }
    cout << max;
}
