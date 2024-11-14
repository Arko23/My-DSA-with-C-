#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

bool shortestPathBellman(vector<Edge> edges, int vertices)
{
    int dist[vertices];
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    for (int i = 1; i < vertices - 1; i++)
    {
        for (Edge e : edges)
        {
            if (dist[e.dest] > dist[e.src] + e.weight)
            {
                dist[e.dest] = dist[e.src] + e.weight;
            }
        }
    }
    for (Edge e : edges)
    {
        if (dist[e.dest] > dist[e.src] + e.weight)
        {
            cout << "No solution";
            return false;
        }
    }
    cout << "------Shortest Path-----" << endl;
    for (int i = 0; i < vertices; i++)
    {
        cout << i << " " << dist[i] << endl;
    }
    return true;
}

int main()
{
    int vertices, edgesCount;
    cin >> vertices >> edgesCount;
    vector<Edge> edges;
    for (int i = 0; i < edgesCount; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    shortestPathBellman(edges, vertices);
    return 0;
}
