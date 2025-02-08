#include <bits/stdc++.h>
using namespace std;

#define V 4

int find(vector<int> &parent, int i) {
    if (parent[i] == -1) {
        return i;
    }
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

void unite(vector<int> &parent, vector<int> &rank, int i, int j) {
    int s1 = find(parent, i);
    int s2 = find(parent, j);

    if (s1 != s2) {
        if (rank[s1] > rank[s2]) {
            parent[s2] = s1;
        } else if (rank[s1] < rank[s2]) {
            parent[s1] = s2;
        } else {
            parent[s2] = s1;
            rank[s1]++;
        }
    }
}

void kruskals(vector<vector<int>> &edgelist) {
    vector<int> parent(V,-1);
    vector<int> rank(V,1);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (vector<int> e : edgelist) {
        pq.push(e);
    }
    int mstCost = 0;
    int edgeCount = 0;

    while (!pq.empty()) {
        vector<int> edge = pq.top();
        pq.pop();

        int w = edge[0];
        int x = edge[1];
        int y = edge[2];

        if (find(parent, x) != find(parent, y)) {
            unite(parent, rank, x, y);
            mstCost += w;
            edgeCount++;

            cout << x << " -- " << y << " == " << w << endl;
        }

        if (edgeCount == V-1) {
            break;
        }
    }
   cout << "Minimum Cost Spanning Tree: " << mstCost << endl;
}


int main() {
    vector<vector<int>> edgelist;
    //w, src, dst
    edgelist.push_back({10, 0, 1});
    edgelist.push_back({15, 1, 3});
    edgelist.push_back({4, 2, 3});
    edgelist.push_back({6, 2, 0});
    edgelist.push_back({5, 0, 3});

    kruskals(edgelist);
}

