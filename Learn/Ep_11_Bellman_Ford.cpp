//for Single source shortest path, can handle negative weight
// O(V*E)
#include <bits/stdc++.h>

using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src) {
     vector<int> dist(V, INT_MAX);
     dist[src] = 0;

     //find shortest path -> for-loop only (V-1) times
     for (int i = 0; i < V-1; i++) {
          for (auto e : edges) {
               int u = e[0];
               int v = e[1];
               int w = e[2];
               if (dist[u] != INT_MAX) {
                    dist[v] = min(dist[u] + w, dist[v]);
               }
               // if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
               //      dist[v] = dist[u] + w;
               // }
          }
     }

     //find negative cycle
     for (auto e : edges) {
          int u = e[0];
          int v = e[1];
          int w = e[2];
          if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
               //found negative cycle!!
               return vector<int>(0);
          }
     }
     return dist;
}

int main() {
     int V = 5;
     vector<vector<int>> edges = {{1, 3, 2}, {4, 3, -1}, {2, 4, 1}, 
                                 {1, 2, 1}, {0, 1, 5}};

     int src = 0;     

     vector<int> ans = bellmanFord(V, edges, src);
     for (int i  = 0; i < ans.size(); i++) {
          cout << i << ": " << ans[i] << endl;
     }

     // for (auto d : ans) {
     //      cout << d << endl
     // }
}