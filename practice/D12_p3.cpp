#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,q;
    cin >> n >> m >> q;
    vector <vector<long long>> matrix(n, vector<vector<long long> >(n, LLONG_MAX));
    for(int i=0; i<m; i++){
        int t1,t2,t3;
        cin >> t1 >> t2 >> t3;
        matrix[t1][t2] = min(mt3,matrix[t1][t2]);
        matrix[t2][t1] = t3;
    }
    for(int i=0; i<n; i++){}
}