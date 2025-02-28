#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int k, n, m;
    cin >> k >> n >> m;
    vector< vector<int> > e(n + 1);
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        e[a].push_back(b);
    }

    //currentLevel, pow
    queue< pair<int,int> > q;
    vector<int> visited(n+1, false);

    q.push(make_pair(1,k));

    int maxLevel = 1;
    while(!q.empty()) {
        auto [curr,pow] = q.front();
        q.pop();
        if (curr > maxLevel) {
            maxLevel = curr;
        }
        if (pow == 0) continue;
        for (int v: e[curr]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(make_pair(v,pow-1));
            }
        }
    }
    cout << maxLevel;
}