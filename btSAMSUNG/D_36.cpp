
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge {
    int src, dest, weight;


    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

class Graph {


public:
    int V, E;
    vector<Edge> edges;
    Graph(int vertices, int edgesCount) : V(vertices), E(edgesCount) {}

    void addEdge(int src, int dest, int weight) {
        edges.push_back(Edge(src, dest, weight));
    }


    vector<int> bellmanFord(int sourceVertex) {
        vector<int> distances(V, numeric_limits<int>::max());
        distances[sourceVertex] = 0;

        for (int i = 0; i < V - 1; ++i) {
            for (const Edge& edge : edges) {
                int u = edge.src;
                int v = edge.dest;
                int w = edge.weight;

                if (distances[u] != numeric_limits<int>::max() && distances[u] + w < distances[v]) {
                    distances[v] = distances[u] + w;
                }
            }
        }

        return distances;
    }

    Edge findCriticalEdge(int sourceVertex, int targetVertex) {
        vector<int> originalDistances = bellmanFord(sourceVertex);

        Edge criticalEdge(-1, -1, numeric_limits<int>::min());

        for (Edge& edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            int w = edge.weight;


            edge.weight = numeric_limits<int>::max();

            vector<int> newDistances = bellmanFord(sourceVertex);

            if (newDistances[targetVertex] > originalDistances[targetVertex] && newDistances[targetVertex] > criticalEdge.weight) {
                criticalEdge = edge;
            }


            edge.weight = w;
        }

        return criticalEdge;
    }
};

int main() {
    int V = 4;
    int E = 5;

    Graph graph(V, E);

    graph.addEdge(0, 1, 2);
    graph.addEdge(1, 2, 3);
    graph.addEdge(2, 3, 1);
    graph.addEdge(0, 2, 5);
    graph.addEdge(1, 3, 4);

    int sourceVertex = 0;
    int targetVertex = 3;


    Edge criticalEdge = graph.findCriticalEdge(sourceVertex, targetVertex);

    cout << "Critical Edge: (" << criticalEdge.src << ", " << criticalEdge.dest << ") with weight " << criticalEdge.weight << endl;

    return 0;
}
