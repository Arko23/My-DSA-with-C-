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
struct V
{
    vector<int> _edge;
    vector<int> weight;
};

V prims_algo(vector<vector<Edge>> &graph, int src, int nodes)
{
    vector<bool> visited(nodes, false);       // checking if the node is visited or not
    vector<int> weight_array(nodes, INT_MAX); // weight of all MST nodes
    vector<int> parent(nodes, -1);            // Mst

    priority_queue<Edge, vector<Edge>, compare> pq; // pq<edges,weight>

    pq.push({src, 0});
    visited[src] = true;
    weight_array[src] = 0;
    parent[src] = src;

    while (!pq.empty())
    {
        int u = pq.top().node;
        pq.pop();

        visited[u] = true;

        for (auto &x : graph[u])
        {
            if (visited[x.node] == false && x.weight < weight_array[x.node])
            {
                pq.push({x.node, x.weight});
                weight_array[x.node] = x.weight;
                parent[x.node] = u;
            }
        }
    }
    return {parent, weight_array};
    // return parent;
}
int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<Edge>> graph(nodes);
    for (int i = 0; i < edges; i++)
    {
        int u, v, w; // from-> to-> weight
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int src;
    cin >> src;

    V v = prims_algo(graph, src, nodes);
    // for (int i = 0; i < nodes; i++)
    //     cout << v[i] << " " << i << endl;

    for (int i = 1; i < nodes; i++)
        cout << v._edge.at(i) << " -> " << i << " :: weight :: " << v.weight.at(i) << endl;
}

/*
6 7
0 1 4
0 2 3
1 2 1
1 3 2
2 3 4
3 4 2
4 5 6
0
*/