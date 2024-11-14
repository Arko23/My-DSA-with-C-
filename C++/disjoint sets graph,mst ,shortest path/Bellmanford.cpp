#include <bits/stdc++.h>
using namespace std;

struct ed
{
    int src, des, w;
};

void bellman(vector<ed> &edge, int n, int s)
{
    vector<int> dist(n, INT_MAX);
    dist[s] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto &x : edge)
        {
            if (dist[x.src] != INT_MAX && dist[x.src] + x.w < dist[x.des])
            {
                dist[x.des] = dist[x.src] + x.w;
            }
        }
    }

    // Check for negative weight cycles after completing all iterations
    for (auto &x : edge)
    {
        if (dist[x.src] != INT_MAX && dist[x.src] + x.w < dist[x.des])
        {
            cout << "Negative weight cycle detected!" << endl;
            return;
        }
    }

    // If no negative cycle detected, print shortest distances
    cout << "Shortest distances from source " << s << ":\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Vertex " << i << ": " << dist[i] << endl;
    }
}

int main()
{
    int n, k, s;
    cout << "Number of nodes: ";
    cin >> n;
    cout << "Number of edges: ";
    cin >> k;
    vector<ed> edge(k);
    for (int i = 0; i < k; i++)
    {
        cout << "Enter edge " << i + 1 << " (source destination weight): ";
        cin >> edge[i].src >> edge[i].des >> edge[i].w;
    }
    cout << "Enter source vertex: ";
    cin >> s;
    bellman(edge, n, s);
    return 0;
}
// Enter number of vertices: 5
// Enter number of edges: 7
// Enter edge 1 (source destination weight): 0 1 -1
// Enter edge 2 (source destination weight): 0 2 4
// Enter edge 3 (source destination weight): 1 2 3
// Enter edge 4 (source destination weight): 1 3 2
// Enter edge 5 (source destination weight): 3 1 1
// Enter edge 6 (source destination weight): 2 3 5
// Enter edge 7 (source destination weight): 3 4 3
// Enter source vertex: 0

