#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> adj[], bool visited[], int u) {
    visited[u] = true;
    cout << u << " ";
    for(int i=0; i<adj[u].size(); i++) {
        int v = adj[u][i];
        if(!visited[v]) {
            dfs(adj, visited, v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; // n is number of vertices, m is number of edges
    vector<int> adj[n+1];
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // for undirected graph
    }
    bool* visited = new bool[n+1];
    for(int i=0; i<=n; i++) {
        visited[i] = false;
    }
    int start;
    cin >> start; // starting vertex for DFS
    dfs(adj, visited, start);
    return 0;
}
