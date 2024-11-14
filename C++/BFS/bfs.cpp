#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<int> adj[], int s, int n)
{
    bool *visited = new bool[n + 1];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    delete[] visited;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s;
    cin >> s;
    BFS(adj, s, n);
}