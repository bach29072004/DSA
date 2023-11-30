#include <bits/stdc++.h>
using namespace std;
int main() {
    int edge;
    cin >> edge;
    bool isEuler = true;
    bool isHalminton = true;
    vector<int> degree(edge, 0);
    for (int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }
    for (int i = 0; i < edge; i++) {
        if (degree[i] % 2 != 0) {
            isEuler = false;
        }
    }
    if (isEuler) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
