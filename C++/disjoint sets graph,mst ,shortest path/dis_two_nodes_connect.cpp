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

bool areConnected(int nodeA, int nodeB)
{
    return find(nodeA) == find(nodeB);
}

int main()
{
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    for (int i = 1; i <= numNodes; ++i)
    {
        make(i);
    }

    for (int i = 0; i < numEdges; ++i)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    int nodeA, nodeB;
    cin >> nodeA >> nodeB;

    if (areConnected(nodeA, nodeB))
    {
        cout << "There is a path between node " << nodeA << " and node " << nodeB << endl;
    }
    else
    {
        cout << "There is no path between node " << nodeA << " and node " << nodeB << endl;
    }

    return 0;
}
