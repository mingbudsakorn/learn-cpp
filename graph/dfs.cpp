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
 
    // Prints DFS traversal from a given source s
    void DFS(int s,vector<bool> &visited,vector<int> &from);
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
 
void Graph::DFS(int s,vector<bool> &visited,vector<int> &from)
{
    visited[s] = true;
    cout << s << " ";
    for(int a : adj[s]){
        if(visited[a] == false){
            from[a] = s;
            DFS(a,visited,from);
        }
    }
    
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
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
 
    // Function call
    vector<bool> visited(6,false);
    vector<int> from(6,-1);
    g.DFS(2,visited,from);
    return 0;
}