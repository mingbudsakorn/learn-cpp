#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>


using namespace std;

int main() {
    //N = Number of City (1-N)
    //M = Number of Road (1-M)
    //L = Max level (0-L)
    int N,M,L;
    cin >> N >> M >> L;

    //dist[city][level]
    vector< vector<int> > dist(N+1, vector<int>(L+2, INT_MAX));
    vector<int> level(N+1);
    vector< vector< pair<int,int> > > adj(N+1);

    // u : {{v1,w1}, {v2,w2}}

    int s,t;
    cin >> s >> t;

    for (int i = 1; i <= N; i++) {
        cin >> level[i];
    }

    for (int i = 0; i < M; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v,w));
    }


    //time(dist[city][level]), city, level
    priority_queue< vector<int> , vector< vector<int> >, greater< vector<int> > > pq;
    dist[s][0] = 0;
    pq.push({0, s, 0});

    while (!pq.empty()) {
        // auto [time, c_city, c_level] = pq.top();
        int time = pq.top()[0];
        int c_city = pq.top()[1];
        int c_level =  pq.top()[2];
        pq.pop();

        if (time > dist[c_city][c_level]) continue;

        for (auto [v,w] : adj[c_city]) {
            //case1: can go to next level and have valid next_level
            // int v = vec[0];
            // int w = vec[1];
            if (c_level + 1 <= L && level[v] == c_level + 1) {
                if (time + w < dist[v][c_level + 1]) {
                    dist[v][c_level + 1] = time + w;
                    pq.push({dist[v][c_level + 1], v, c_level + 1});
                }
            }

            //case2: invalid next_level
            if (time + w < dist[v][c_level]) {
                dist[v][c_level] = time + w;
                pq.push({dist[v][c_level], v, c_level});
            }
        }
    }

    if (dist[t][L] != INT_MAX) {
        cout << dist[t][L];
    } else {
        cout << -1;
    }
    
}