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
