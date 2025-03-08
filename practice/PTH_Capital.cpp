#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<bool> visited(n+1, false);
    for (int i = 0; i < n-1; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v,w));
        adj[u].push_back(make_pair(v,w));
    }

    int maxDist = 0;
    queue<pair<int,int>> q;
    q.push(make_pair(1,0));
    while(!q.empty()) {
        auto [u,d] = q.front();
        q.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (auto [v,w] : adj[u]) {
            if (!visited[v]) {
                int dist = d + w;
                q.push(make_pair(v,dist));
                if (dist > maxDist) {
                    maxDist = dist;
                }
            }
        }
    }
    cout << maxDist;

}