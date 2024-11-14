#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int par[N];
int sz[N];

void make(int v)
{
    par[v] = v;
    sz[v] = 1;
}

int find(int v)
{
    if (v == par[v])
        return v;
    return par[v] = find(par[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }
        par[b] = a;     // Update parent of b to be a
        sz[a] += sz[b]; // Update size of a
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < k; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    int totalcost = 0;
    for (auto &x : edges)
    {
        int w = x.first;
        int u = x.second.first;
        int v = x.second.second;
        if (find(u) == find(v))   //if(find(u)!=find(v)){ Union(u,v); totalcost+=w; cout<<u<<""<<v<<endl;}
            continue;
        Union(u, v);
        totalcost += w;
        cout << u << " " << v << endl;
    }
    cout << totalcost << endl;
    return 0;
}
// 5 7
// 1 2 1
// 1 3 2
// 2 3 3
// 2 4 4
// 3 4 5
// 4 5 6
// 1 5 7
