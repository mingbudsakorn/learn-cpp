#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>>& adj, int s) {
    queue<int> q;
    vector<bool> visited(adj.size(), false);

    //visit source node
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << "current: " << curr << endl;

        for (int u : adj[curr]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
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

    bfs(adj, 0);
}