// C++ code to print BFS traversal from a given
// source vertex
 
#include <bits/stdc++.h>
using namespace std;
 
// This class represents a directed graph using
// adjacency list representation
class Graph {
 
    // No. of vertices
    int V;
 
    // Pointer to an array containing adjacency lists
    vector<list<int> > adj;
 
public:
    // Constructor
    Graph(int V);
 
    // Function to add an edge to graph
    void addEdge(int v, int w);
 
    // Prints BFS traversal from a given source s
    void BFS(int s,int p);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}
 
void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
}
 
void Graph::BFS(int s, int p)
{
    vector<int> dist;
    vector<int> path;
    dist.resize(V,-1);
    path.resize(V,-1);

    queue<int> Q;
    Q.push(s);
    dist[s] = 0;
    

    while(Q.size()){
        int u = Q.front();
        cout << u << " ";
        Q.pop();
        
        for(int a : adj[u]){
            if(dist[a]== -1){
                dist[a] = dist[u] + 1;
                path[a] = u;
                Q.push(a);
            }    
        }
    }
    cout << "\n" << "Distance: " << s << " -> " << p << " : " << dist[p];
    cout << "\n" << "Path: ";
    stack<int> pathOut;
    while(p!=-1){
        pathOut.push(p);
        p = path[p];
    }
    while(pathOut.size()){
        cout << pathOut.top() << " ";
        pathOut.pop();
    }
    
    // // Mark all the vertices as not visited
    // vector<bool> visited;
    // visited.resize(V, false);
 
    // // Create a queue for BFS
    // list<int> queue;
 
    // // Mark the current node as visited and enqueue it
    // visited[s] = true;
    // queue.push_back(s);
 
    // while (!queue.empty()) {
 
    //     // Dequeue a vertex from queue and print it
    //     s = queue.front();
    //     cout << s << " ";
    //     queue.pop_front();
 
    //     // Get all adjacent vertices of the dequeued
    //     // vertex s.
    //     // If an adjacent has not been visited,
    //     // then mark it visited and enqueue it
    //     for (auto adjacent : adj[s]) {
    //         if (!visited[adjacent]) {
    //             visited[adjacent] = true;
    //             queue.push_back(adjacent);
    //         }
    //     }
    // }
}
 
// Driver code
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 2);
    g.addEdge(2, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 5);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 1) \n";
    g.BFS(1,5);
 
    return 0;
}