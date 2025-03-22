#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x = 2 * n;
    vector<pair<int, int>> adj[x + 1];
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= x; j++) {
            int a;
            cin >> a;
            if (a != 0) {
                adj[i].push_back({j, a});
            }
        }
    }
    vector<bool> visited(x + 1, false);
    vector<int> dist(x + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[x] = 0;
    pq.push({0, x});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (auto [v, w] : adj[u]) {
            if (!visited[v]) {
                dist[v] = min(dist[v], w + d);
                pq.push({dist[v], v});
            }
        }
    }
    cout << dist[2];
}