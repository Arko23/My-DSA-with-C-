#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int parent[N];
int size[N];

void make(int v)
{
    parent[v] = v;
    size[v] = 1;
}

int find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (size[a] < size[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

bool hasCycle(vector<pair<int, int>> &edges)
{
    for (int i = 1; i <= N; ++i)
    {
        make(i);
    }

    for (auto &edge : edges)
    {
        int u = edge.first;
        int v = edge.second;

        if (find(u) == find(v))
        {
            return true; // Cycle detected
        }

        Union(u, v);
    }

    return false; // No cycle detected
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    if (hasCycle(edges))
    {
        cout << "The graph contains a cycle." << endl;
    }
    else
    {
        cout << "The graph is acyclic." << endl;
    }

    return 0;
}
