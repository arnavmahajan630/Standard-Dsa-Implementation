#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e5 + 3;
vector<int>g[N];

void InputG( int m) {
    for(int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        if(u == v)continue;
        g[u].push_back(v);
    }
}

bool cycleDetectDfs(int r, vector<bool>&visited, vector<bool>&pviz) {
    visited[r] = true;
    pviz[r] = true;

    for(auto x : g[r]) {
        if(!visited[x]) {
            if(cycleDetectDfs(x, visited, pviz))return true;
        }
        else if(pviz[x])return true;
    }
    pviz[r] = false;
    return false;
}

bool DetectCycleBfs(vector<int>&indgr) {
    int n = indgr.size();
    int cnt = 0;
    queue<int>q;
    for(int i=0; i < n; ++i) {
        if(indgr[i] == 0) {
            q.push(i); // added all who had indegree of 0
        }
    }

    while(!q.empty()) {
        int f  = q.front();
        q.pop();
        cnt++;

        for(auto x : g[f]) {
            indgr[x]--;
            if(indgr[x] == 0) {
                q.push(x);
            }
        }
    }

    return cnt != n; // if all elements were not then we do have cycle 
}

int main() {
    int n, m;
    cin >> n >> m;
    InputG(m); // take input for graph in an adjecency list
    bool decectCycleDfs = false;
    vector<bool>visited(n, false);
    vector<bool>pviz(n, false);
    for(int i=0; i < n; ++i) {
        if(!visited[i]) {
            if(cycleDetectDfs(i, visited, pviz)) {
                decectCycleDfs = true;
                break;
            }
        }
    }
    cout << "Detection using DFS ressult is: " << decectCycleDfs << endl;

    vector<int>indgr(n, false);
    for(int i=0; i < n; ++i) {
        for(auto x : g[i]) {
            indgr[x]++;
        }
    } // counted the indegree for each node

    cout << "Dectection using the BFS (Topo Sort) is: " << DetectCycleBfs(indgr) << endl;


    return 0;
}