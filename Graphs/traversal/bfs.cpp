#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int N = 1e5 + 3;

void bfs(int r, vector<bool>&visited) {
    queue<int>q;
    visited[r] = true;
    q.push(r);

    while(!q.empty()) {
        int top = q.front(); q.pop();
        for(auto x : g[top]) {
            if(!visited[x]) {
                visited[x] = true; // visited now
                q.push(x); // add for neighbour processing
            }
        }
    }
}

void dfs(int r, vector<bool>&visited) {
    visited[r] = true;

    for(auto x : g[r]) {
        if(!visited[x]) {
            visited[r]=  true;
            dfs(x, visited);
        }
    }
}

vector<int>g[N];
int main() {
    int n,m;
    cin >> n >> m;
    for(int i=0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        if(u!= v)g[v].push_back(u); // undirected graph
    }
    return 0;
}