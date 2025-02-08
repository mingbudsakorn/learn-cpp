#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int curr) {
    cout << "current: " << curr << endl;
    visited[curr] = true;

    for (int u : adj[curr]) {
        if (!visited[u]) {
            dfs(adj, visited, u);
        }
    }
}

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int V = 5;

    vector<vector<int>> adj(V);

    //Create graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);
    //0 1 2 3 4 5

    vector<bool> visited(V, false);

    dfs(adj, visited, 0);
}