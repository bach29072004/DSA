#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> graph;
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);

        indegree[v]++;
    }
    // BFS
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    vector<int> topo;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v : graph[u]) {
            indegree[v]--;

            if (indegree[v] == 0) q.push(v);
        }
    }
    if (topo.size() == n) {
        for (int u : topo) cout << u << " ";
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}
