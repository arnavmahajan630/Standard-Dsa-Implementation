#include <iostream>
#include <vector>
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

int main() {
    int n, m;
    cin >> n >> m;
    InputG(m); // take input for graph in an adjecency list
    cout << boolalpha;
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

    return 0;
}