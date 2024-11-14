#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<int> adj[], int start, int n) {
    bool* visited = new bool[n+1];
    for(int i=0; i<=n; i++) {
        visited[i] = false;
    }
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while(!q.empty()) {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for(int i=0; i<adj[u].size(); i++) {
            int v = adj[u][i];
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    delete[] visited;
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
    int start;
    cin >> start; // starting vertex for BFS
    bfs(adj, start, n);
    return 0;
}
