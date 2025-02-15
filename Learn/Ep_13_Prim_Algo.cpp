//Similar with dijkstra's but have different def of d[v]

#include <bits/stdc++.h>
using namespace std;

// vector<int> dist;

vector<int> parent;

int prim(int V, int E, vector<vector<int>> &edges) {
    // Create an adjacency list representation of the graph
    vector<vector<vector<int>>> adj(V);
    
    // Fill the adjacency list with edges and their weights
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<bool> visited(V, false);

    int mstCost = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    //weight, index
    pq.push({0,0});

    while(!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        mstCost += w;

        for (auto v : adj[u]) {
            cout << visited[v[0]] << endl; 
            if (!visited[v[0]]) {
                pq.push({v[1], v[0]});
            }
        }
    }

    return mstCost;
}

int main() {

    vector<vector<int>> graph = {{0, 1, 5},
                                  {1, 2, 3},
                                  {0, 2, 1}};

    cout << prim(3,3,graph) << endl;
    return 0;
}