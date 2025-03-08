#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> kList;
map<int,int> m;
int n,k;
int maxK = 0;

void bfs(int st ) {
    queue<pair<int,int>> q;
    vector<int> visited(n+1, false);
    q.push(make_pair(st,0));
    while (!q.empty()) {
        auto [u,d] = q.front();
        q.pop();
        if (visited[u]) continue;
        visited[u] = true;
        if (d == maxK) continue;
        for (int v : adj[u]) {
            if (!visited[v]) {
                int dist = d + 1;
                q.push(make_pair(v,dist));
                m[dist]++;
            }
        }
    }
}
int main() {
    cin >> n >> k;
    adj.resize(n + 1);
    kList.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> kList[i];
        if (kList[i] > maxK) {
            maxK = kList[i];
        }
    }

    for (int i = 0; i < n-1; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        bfs(i);
    }

    for (int kk: kList) {
        cout << m[kk] << endl;
    }
}