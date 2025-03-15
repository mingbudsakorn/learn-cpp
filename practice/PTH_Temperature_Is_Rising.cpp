#include <bits/stdc++.h>
using namespace std;

int max_temp = -10;
int M;
vector<vector<bool>> visited;
vector<vector<int>> g;

void dfs(int row, int col,int prev_temp) {
    if (row <= 0 || row > M || col <=0 || col > M) {
        return;
    }
    int curr_temp = g[row][col];
    if (visited[row][col] || curr_temp == 100 || curr_temp <= prev_temp) {
        return;
    }
    visited[row][col] = true;
    if (curr_temp > max_temp) {
        max_temp = curr_temp;
    }
    //up -> row-1, col
    dfs(row-1,col,curr_temp);
    
    //bottom -> row+1, col
    dfs(row+1,col,curr_temp);

    //left -> row, col-1
    dfs(row,col-1,curr_temp);

    //right -> row, col+1
    dfs(row,col+1,curr_temp);
}

int main() {
    //x->column, y->row
    int X, Y;
    cin >> M >> X >> Y;
    visited = vector<vector<bool>>(M+1,vector<bool>(M+1,false));
    g = vector<vector<int>>(M+1,vector<int>(M+1));
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> g[i][j];
        }
    }
    dfs(Y,X,max_temp);
    cout << max_temp;
}