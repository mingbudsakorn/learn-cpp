#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

struct State {
    int city, rank, time;
    bool operator>(const State& other) const {
        return time > other.time;
    }
};

int N, M, L, s, t;
vector<pair<int, int>> graph[50005];
int cityRank[50005];
int dist[50005][35];

void dijkstra() {
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({s, 0, 0});
    dist[s][0] = 0;

    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();

        int u = cur.city, rank = cur.rank, time = cur.time;

        if (u == t && rank == L) {
            cout << time << "\n";
            return;
        }

        if (time > dist[u][rank]) continue;

        for (auto [v, w] : graph[u]) {
            int nextRank = rank;

            if (cityRank[v] == rank + 1) nextRank++;
            if (cityRank[v] > L + 1 || (cityRank[v] != nextRank && cityRank[v] <= L)) continue;

            if (time + w < dist[v][nextRank]) {
                dist[v][nextRank] = time + w;
                pq.push({v, nextRank, time + w});
            }
        }
    }

    cout << -1 << "\n"; // No valid path found
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> L;
    cin >> s >> t;

    for (int i = 1; i <= N; i++) {
        cin >> cityRank[i];
    }

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].emplace_back(B, C);
    }

    // Initialize distances
    for (int i = 0; i <= N; i++) {
        fill(dist[i], dist[i] + (L + 2), INF);
    }

    dijkstra();
    return 0;
}
