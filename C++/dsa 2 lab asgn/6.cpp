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
        return (parent[x] == x) ? x : (parent[x] = find(parent[x]));
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x != y)
        {
            if (rank[x] < rank[y])
            {
                swap(x, y);
            }
            parent[y] = x;
            if (rank[x] == rank[y])
            {
                rank[x]++;
            }
        }
    }
};

struct Edge
{
    int src, dest, weight;
};

vector<Edge> kruskalMST(vector<Edge> &edges, int vertices)
{
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.weight < b.weight; });

    DisjointSet dsu(vertices);
    vector<Edge> mst;

    for (Edge e : edges)
    {
        int srcRoot = dsu.find(e.src);
        int destRoot = dsu.find(e.dest);
        if (srcRoot != destRoot)
        {
            mst.push_back(e);
            dsu.unite(srcRoot, destRoot);
        }
    }

    return mst;
}

int main()
{
    int vertices, edgesCount;
    cin >> vertices >> edgesCount;
    vector<Edge> edges(edgesCount);

    for (int i = 0; i < edgesCount; i++)
    {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    vector<Edge> mst = kruskalMST(edges, vertices);

    cout << "Minimum Spanning Tree Edges:" << endl;
    for (Edge e : mst)
    {
        cout << e.src << " " << e.dest << " " << e.weight << endl;
    }

    return 0;
}
