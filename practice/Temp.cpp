#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, l;
    cin >> n >> m >> l;

    vector<vector<int>> dist(n + 1, vector<int>(l + 1, INT_MAX));
    vector<int> level(n + 1);
    vector<vector<pair<int, int>>> adj(n + 1);
    int st, fn;
    cin >> st >> fn;

    for (int i = 1; i <= n; i++) {
        cin >> level[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, st, 0});
    dist[st][0] = 0;

    while (!pq.empty()) {
        // auto [Time, City, Level] = pq.top();
        int Time = pq.top()[0];
        int City = pq.top()[1];
        int Level =  pq.top()[2];
        pq.pop();

        if (Time > dist[City][Level]) continue;

        for (auto [v, w] : adj[City]) {
            if (Level + 1 <= l && level[v] == Level + 1) {
                if (Time + w < dist[v][Level + 1]) {
                    dist[v][Level + 1] = Time + w;
                    pq.push({dist[v][Level + 1], v, Level + 1});
                }
            }

            if (Time + w < dist[v][Level]) {
                dist[v][Level] = Time + w;
                pq.push({dist[v][Level], v, Level});
            }
        }
    }

    if (dist[fn][l] != INT_MAX) {
        cout << dist[fn][l];
    } else {
        cout << -1;
    }

    return 0;
}
