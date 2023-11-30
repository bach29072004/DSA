#include <iostream>
#include <vector>
#include <tuple>

using namespace std;


struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    vector<Edge> edges;


    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }


    void addEdge(int src, int dest, int weight) {
        Edge edge = {src, dest, weight};
        edges.push_back(edge);
    }
};
struct Subset {
    int parent, rank;
};

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}


void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}


void boruvkaMST(Graph& graph) {
    int V = graph.V, E = graph.E;
    Edge *edges = graph.edges.data();
    Subset *subsets = new Subset[V];

    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int numTrees = V;
    int MSTweight = 0;

    vector<Edge> cheapest(V);


    while (numTrees > 1) {

        for (int v = 0; v < V; ++v) {
            cheapest[v] = {-1, -1, INT_MAX};
        }

        for (int i = 0; i < E; i++) {
            int set1 = find(subsets, edges[i].src);
            int set2 = find(subsets, edges[i].dest);

            if (set1 != set2) {
                if (cheapest[set1].weight > edges[i].weight)
                    cheapest[set1] = edges[i];
                if (cheapest[set2].weight > edges[i].weight)
                    cheapest[set2] = edges[i];
            }
        }

        for (int i = 0; i < V; i++) {
            Edge edge = cheapest[i];
            if (edge.src != -1) {
                int set1 = find(subsets, edge.src);
                int set2 = find(subsets, edge.dest);

                if (set1 != set2) {
                    MSTweight += edge.weight;
                    cout << "Edge " << edge.src << " - " << edge.dest << " weight: " << edge.weight << endl;
                    Union(subsets, set1, set2);
                    numTrees--;
                }
            }
        }
    }

    cout << "Weight of MST is " << MSTweight << endl;

    delete[] subsets;
}
int main() {
    int V = 4;  // Số đỉnh
    int E = 5;  // Số cạnh
    Graph graph(V, E);

    // Thêm cạnh
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    boruvkaMST(graph);

    return 0;
}
