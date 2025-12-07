#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 1e5 + 3;
vector<int>g[N];

bool isBipartiteBfs(int r, vector<int>visited) {
    queue<int>q;
    q.push(r);
    while(!q.empty()) {
        int top = q.front(); q.pop();
        for(auto x : g[top]) {
            if(visited[x] == -1) {// if never visited
                visited[x] = visited[top]^1; // toggle the state
                q.push(x); // add it for further processing
            }  
            else if(visited[x] == visited[top]) { // this means we get 00 / 11
              return false;
            }  
        }
    }
    return true;
}

bool isBipartiteDfs(int r, vector<int>&visited) {
    for(auto x : g[r]) {
        if(visited[x] == -1) {
            visited[x] = visited[r]^1;
            if(!isBipartiteDfs(x, visited))return false;
        }
        else if(visited[x] == visited[r])return false;
    }
    return true;
}

int main() {

    int n,m;
    cin >> n >> m;

    for(int i=0; i< m; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        if(u != v)g[v].push_back(u);
    }

    vector<int>visited(n, -1); // not visited as -1

    for(int i=0; i < n; ++i) {
        if(!visited[i]) {
            visited[i] = 0; // marking every new connected component starting as 0
            bool st = isBipartiteBfs(i, visited);
            // bool st = isBipartiteDfs(i, visited);
        }
    }
}