include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // A large value representing infinity

// Input variables
int n, m, t, st, en;
vector<vector<pair<int, int>>> g; // Graph: g[u] = {v, w}
vector<vector<int>> dis; // dis[city][level] = minimum time to reach (city, level)
vector<int> level; // Rank of each city

// Priority queue for Dijkstra (time, city, level)
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

int main() {
    // Input: Number of cities (n), roads (m), target rank (t), start (st), end (en)
    cin >> n >> m >> t >> st >> en;

    // Resize vectors based on input
    g.resize(n + 1);
    dis.resize(n + 1, vector<int>(t + 2, INF));
    level.resize(n + 1);

    // Input: Rank of each city (1-based index)
    for (int i = 1; i <= n; i++) {
        cin >> level[i];
    }

    // Input: Roads (u -> v with time w)
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
    }

    // Starting point: Distance to the starting city at level 0 is 0
    dis[st][0] = 0;
    pq.emplace(0, st, 0);

    // Modified Dijkstra's algorithm
    while (!pq.empty()) {
        auto [time, u, curr_level] = pq.top();
        pq.pop();

        // If already found a shorter path, skip
        if (time > dis[u][curr_level]) continue;

        // Explore all neighbors (v, travel time w)
        for (auto [v, w] : g[u]) {
            // Case 1: Move to the next level if the city matches the next required rank
            if (curr_level + 1 <= t && level[v] == curr_level + 1) {
                if (dis[v][curr_level + 1] > time + w) {
                    dis[v][curr_level + 1] = time + w;
                    pq.emplace(dis[v][curr_level + 1], v, curr_level + 1);
                }
            }

            // Case 2: Stay in the current level if the city is not the next rank
            if (dis[v][curr_level] > time + w) {
                dis[v][curr_level] = time + w;
                pq.emplace(dis[v][curr_level], v, curr_level);
            }
        }
    }

    // Output: Minimum time to reach the end city with rank t
    if (dis[en][t] == INF) cout << -1; // No valid path
    else cout << dis[en][t]; // Output the shortest time

    return 0;
}

////

// dist[city][level]

// dist[1][0] = 0
// dist[3][1] = 80 -> pq
// dist[2][0] = 20 -> pq

// time = 20
// city = 2
// level = 0

// dist[4][1] = 50 -> pq
// dist[5][0] = 35 -> pq
// .
// dist[6][0] = 80 -> pq
// .
// .
// dist[2][2] = 90 -> pq

// dist[6][3] ?

