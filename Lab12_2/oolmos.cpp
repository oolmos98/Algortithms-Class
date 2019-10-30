#include <iostream>
#include <vector>
#include <queue>
#include "limits.h"
#include <utility>

using namespace std;
//Used Lab 12 pseudocode provided and the textbook for references.
//The pseudocode states to use a min priority_queue, which is a MinHeap, so i reused Lab9 as a setup.

/*References:
For the pair STL: https://www.geeksforgeeks.org/pair-in-cpp-stl/
As a guide: https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
-> https://www.technical-recipes.com/2011/priority-queues-and-min-priority-queues-in-c/
*/
void minimumSpanningTree(int vertices, vector<pair<int, int> > Graph[])
{   //pseudocode variables: parents,key,Q.
    vector<int> parent, key;
    vector<bool> visited(vertices, false);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >Q;

    Q.push(pair<int, int>(0,0));

    //for all u∈V do
    for(int i = 0; i < vertices; i++)
    {
        key.push_back(INT_MAX);
        parent.push_back(0);
        
    }
    
    while(Q.empty() != true){
        int u = Q.top().second;
        Q.pop();

        visited[u] = true;
        for(int i=0; i < Graph[u].size(); i++)
        {
            int v = Graph[u][i].first;
            int w = Graph[u][i].second;
            
            if(!visited[v] && key[v]>w)
            {
                key[v] = Graph[u][i].second;
                Q.push(pair<int, int>(w, v));
                parent[v] = u;
            }
        }
        
    }
    //Print the parents of each vertices
    for(int i = 1; i < vertices; i++)
        cout << parent[i] << endl;
    
    
}

int main(int argc, char const *argv[])
{   
    int vertices, edges, u, v, weight;
    
    cin >> vertices >> edges;
    vector<pair<int, int> > Graph[edges];

    for(int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weight;
        Graph[u].push_back(make_pair(v, weight));
        Graph[v].push_back(make_pair(u, weight));
    }
    
    minimumSpanningTree(vertices, Graph);

    return 0;
}