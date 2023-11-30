#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;

    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

class Graph {
private:
    int V;
    vector<Edge> edges;

public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(int src, int dest, int weight) {
        edges.push_back(Edge(src, dest, weight));
    }


    void vyssotskyMST() {
        vector<int> parent(V, -1);
        vector<int> rank(V, 0);


        sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
            return a.weight < b.weight;
        });

        for (const Edge &edge : edges) {
            int x = find(parent, edge.src);
            int y = find(parent, edge.dest);


            if (x != y) {
                cout << "Add edge: " << edge.src << " - " << edge.dest << "   Weight: " << edge.weight << "\n";
                unionSets(parent, rank, x, y);
            }
        }
    }


    int find(vector<int> &parent, int u) {
        if (parent[u] == -1)
            return u;
        return find(parent, parent[u]);
    }

    void unionSets(vector<int> &parent, vector<int> &rank, int x, int y) {
        int xRoot = find(parent, x);
        int yRoot = find(parent, y);

        if (rank[xRoot] < rank[yRoot])
            parent[xRoot] = yRoot;
        else if (rank[xRoot] > rank[yRoot])
            parent[yRoot] = xRoot;
        else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};

int main() {

    Graph g(4);
    g.addEdge(0, 1, 20);
    g.addEdge(0, 2,14);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 3, 12);
    g.addEdge(2, 3, 9);


    g.vyssotskyMST();

    return 0;
}
