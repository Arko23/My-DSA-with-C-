#include <bits/stdc++.h>
using namespace std;

struct DisjointSet
{
    vector<int> parent, rank;

    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
        {
            return;
        }
        if (rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

int main()
{
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;
    vector<pair<int, int>> edges;

    DisjointSet dsu(n);

    cout << "Enter " << m << " edges in the format (node1 node2):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    for (auto edge : edges)
    {
        dsu.unite(edge.first, edge.second);
    }

    cout << "Parent array after union operations:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dsu.find(i) << endl;
    }

    return 0;
}
