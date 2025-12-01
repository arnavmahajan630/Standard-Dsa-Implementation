#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

const int N = 1e5 + 3;
vector<int>graph[N];

void TopoSort_dfs(int r, vector<bool>&visited, stack<int>&s) {
    visited[r] = true;

    for(auto x : graph[r]) {
        if(!visited[x])TopoSort_dfs(x, visited, s);
    }
    // the neighbours for a specific node are put first. so we can gaurentee that if there is an edge 
    // the v is always ahead of u. Stack ensures that for us.
    s.push(r);
}


vector<int> TopoSort_bfs( vector<int>&indegree) {
    queue<int>q;
    vector<int>ans;
    int n = indegree.size();
    for(int i=0; i < n; ++i) {
        if(indegree[i] == 0)q.push(i);
    }
    // get all nodes with indegree 0 i.e no one can visited them. so safe at start
    while(!q.empty()) {
        int f = q.front();
        q.pop();
        ans.push_back(f); // push the safe node
        // for each neighbour we traverse
        for(auto x : graph[f]) {
            indegree[x]--; // we delink i.e since it's parent was 0 we reduced it's indegree
            if(indegree[x] == 0)q.push(x); // now if it has indegree of 0 we push him
        }
    }

    return ans;
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
        if(!visited[i])TopoSort_dfs(i, visited, s);
    }

    cout << "One of the possible Topo sort is as follows: " << endl;
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;

    // Kahn's Algorithm
    // we need to trace indegree. whenever we visit any neighbour we incrase it's indegree since we are visitng it from unique node
    vector<int>indegree(n, false);
     for(int i=0; i < n; ++i) {
        for(auto x : graph[i]) {
            indegree[x]++;
        }
    }
    // we now have indegree array similar to freq array for tracing indegrees
    cout << "A Possible Topo Sort BFS:" << endl;
    vector<int>ans = TopoSort_bfs(indegree);
    for(auto x : ans) {
        cout << x << endl;
    }


    return ;
}