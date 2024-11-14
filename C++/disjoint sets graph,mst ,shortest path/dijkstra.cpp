#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int node;
    int weight;
};
struct compare
{
    bool operator()(Edge a, Edge b)
    {
        return a.weight > b.weight;
    }
};
void addEdge(vector<Edge> adj[], int u, int v, int wt)
{
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
}

void shortestPath(vector<Edge> adj[], int V, int src)
{
    priority_queue<Edge, vector<Edge>, compare> pq; // pq<edge,weight>
    vector<int> dist(V, INT_MAX);                   // cost of path
    vector<int> parent(V, -1);                      // containing shortest path

    pq.push({src, 0}); // push(source node,path cost)
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().node;
        pq.pop();

        for (auto x : adj[u]) // visiting every neighbour node
        {
            int v = x.node;
            int weight = x.weight;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({v, dist[v]});
                parent[v] = u;
            }
        }
    }

    for (int i = 0; i < V; ++i)
    {
        cout << "Cost from " << src << " to " << i << ": " << dist[i] << endl;
        cout << "Path: ";
        for (int v = i; v != -1; v = parent[v]) // This loop is used to print the shortest path from the source node to the current node i.
        {
            cout << v << ' ';
        }
        cout << endl;
    }
}

int main()
{
    int node, edge;
    cin >> node >> edge;

    vector<Edge> adj[node];

    for (int i = 0; i < edge; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        addEdge(adj, u, v, wt);
    }

    int src;
    cin >> src;
    shortestPath(adj, node, src);

    //  int V = 9;
    // vector<Edge> adj[V];

    // addEdge(adj, 0, 1, 4);
    // addEdge(adj, 0, 7, 8);
    // addEdge(adj, 1, 2, 8);
    // addEdge(adj, 1, 7, 11);
    // addEdge(adj, 2, 3, 7);
    // addEdge(adj, 2, 8, 2);
    // addEdge(adj, 2, 5, 4);
    // addEdge(adj, 3, 4, 9);
    // addEdge(adj, 3, 5, 14);
    // addEdge(adj, 4, 5, 10);
    // addEdge(adj, 5, 6, 2);
    // addEdge(adj, 6, 7, 1);
    // addEdge(adj, 6, 8, 6);
    // addEdge(adj, 7, 8, 7);

    // shortestPath(adj, V, 0);

    return 0;
}
