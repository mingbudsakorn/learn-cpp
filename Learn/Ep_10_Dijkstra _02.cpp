#include <bits/stdc++.h>

using namespace std;

#define V 9

typedef pair<int,int> pii;

int minDistance(vector<int>& dist,vector<bool>& sptSet) {
     int min = INT_MAX, minIndex;
     for (int i = 0; i < V; i++) {
          if (!sptSet[i] && dist[i] < min) {
               min = dist[i];
               minIndex = i;
          }
     }
     return minIndex;
}
void dijkstra(int graph[V][V], int src) {
     //set all dist to inf
     vector<int> dist(V, INT_MAX);
     //set sptSet to empty
     vector<bool> sptSet(V, false);

     dist[src] = 0;
     priority_queue<pii, vector<pii>, greater<pii>> pq;
     //distance, index
     pq.push(make_pair(dist[src],0));
     //loop until all in sptSet is true
     
     while (!pq.empty()) {
          //pick u -> min dist and sptSet[u] = false
          pii p = pq.top();
          pq.pop();
          int u = p.second;
          if (sptSet[u]) continue;
          sptSet[u] = true;
          //for adj(u)
          for (int v = 0; v < V; v++) {
               if (graph[u][v] != 0 && !sptSet[v]) {
                    dist[v] = min(dist[u] + graph[u][v], dist[v]);
                    pq.push(make_pair(dist[v], v));
               }
          }    
     }

     for (int u = 0; u < V; u++) {
          cout << u << " : " << dist[u] << endl;
     }
}

int main() {
     int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
     dijkstra(graph, 0);
}