#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int N = 1e5 + 3;
vector<int>graph[N];

void TopoSort(int r, vector<bool>&visited, stack<int>&s) {
    visited[r] = true;

    for(auto x : graph[r]) {
        if(!visited[x])TopoSort(x, visited, s);
    }
    // the neighbours for a specific node are put first. so we can gaurentee that if there is an edge 
    // the v is always ahead of u. Stack ensures that for us.
    s.push(r);
}


void inputG(int m) {
    for(int i=0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        if(u == v)continue;
    }

}
int main() {
    cout << "Ensure you enter Directed Acyclic Graph" << endl;
    cout << "Enter the number of vertices and edges: " << endl;
    int n, m;
    cin >> n >> m;

    cout << "For next m lines enter the nodes where edge is present: \n" << endl;
    inputG(m);

    vector<bool>visited(n, false);
    stack<int>s;
    for(int i=0; i < n; ++i) {
        if(!visited[i])TopoSort(i, visited, s);
    }

    cout << "One of the possible Topo sort is as follows: " << endl;
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return ;
}