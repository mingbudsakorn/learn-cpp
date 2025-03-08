#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<bool> result;

bool dfs(int curr) {
    visited[curr] = true;
    for (int next: adj[curr]) {
        if (!visited[next]) {
            if (dfs(next)) return true;
        } else if (visited[next]) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    adj.resize(n+1);
    for (int i=1;i<=n;i++) {
        int k;
        cin >> k;
        for (int j=1;j<=k;j++) {
            int temp;
            cin >> temp;
            adj[i].push_back(temp);
        }
    }

    for (int i=1;i<=n;i++) {
        visited = vector<bool>(n+1,false);
        if (!dfs(i)) {
            cout << "NO" <<endl;
        } else {
            cout << "YES" << endl;
        }
    }

}

