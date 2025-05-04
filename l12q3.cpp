#include <iostream>
using namespace std;
#define MAX 50
#define INF 99999

class graph {
private:
    int mat[MAX][MAX];
    int vertice;

    struct Edge {
        int u, v, w;
    } edges[MAX * MAX];

    int edgeCount;

public:
    graph(int v) {
        vertice = v;
        edgeCount = 0;
        for (int i = 0; i < vertice; i++)
            for (int j = 0; j < vertice; j++)
                mat[i][j] = 0;
    }

    bool isvalid(int v) {
        return (v >= 0 && v < vertice);
    }

    void ins(int v, int u, int w) {
        if (isvalid(v) && isvalid(u)) {
            mat[v][u] = w;
            mat[u][v] = w;
            edges[edgeCount++] = {v, u, w};
        } else {
            cout << "Invalid vertices\n";
        }
    }

    void display() {
        for (int i = 0; i < vertice; i++) {
            for (int j = 0; j < vertice; j++) {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void prim() {
        int parent[MAX], key[MAX];
        bool visited[MAX];

        for (int i = 0; i < vertice; i++) {
            key[i] = INF;
            visited[i] = false;
        }

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < vertice - 1; count++) {
            int min = INF, u = -1;

            for (int v = 0; v < vertice; v++) {
                if (!visited[v] && key[v] < min) {
                    min = key[v];
                    u = v;
                }
            }

            visited[u] = true;

            for (int v = 0; v < vertice; v++) {
                if (mat[u][v] && !visited[v] && mat[u][v] < key[v]) {
                    key[v] = mat[u][v];
                    parent[v] = u;
                }
            }
        }

        cout << "Prim's MST:\n";
        for (int i = 1; i < vertice; i++) {
            cout << parent[i] << " - " << i << " (" << mat[i][parent[i]] << ")\n";
        }
    }

    void sortEdges() {
        for (int i = 0; i < edgeCount - 1; i++) {
            for (int j = i + 1; j < edgeCount; j++) {
                if (edges[i].w > edges[j].w) {
                    Edge temp = edges[i];
                    edges[i] = edges[j];
                    edges[j] = temp;
                }
            }
        }
    }

    int find(int parent[], int i) {
        if (parent[i] == i)
            return i;
        return find(parent, parent[i]);
    }

    void unionSet(int parent[], int rank[], int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);

        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    void kruskal() {
        int parent[MAX], rank[MAX];
        for (int i = 0; i < vertice; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        sortEdges();

        cout << "Kruskal's MST:\n";
        for (int i = 0; i < edgeCount; i++) {
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].w;

            int setU = find(parent, u);
            int setV = find(parent, v);

            if (setU != setV) {
                cout << u << " - " << v << " (" << w << ")\n";
                unionSet(parent, rank, setU, setV);
            }
        }
    }

    void dijkstra(int src) {
        int dist[MAX];
        bool visited[MAX];

        for (int i = 0; i < vertice; i++) {
            dist[i] = INF;
            visited[i] = false;
        }

        dist[src] = 0;

        for (int count = 0; count < vertice - 1; count++) {
            int min = INF, u = -1;
            for (int i = 0; i < vertice; i++) {
                if (!visited[i] && dist[i] < min) {
                    min = dist[i];
                    u = i;
                }
            }

            visited[u] = true;

            for (int v = 0; v < vertice; v++) {
                if (!visited[v] && mat[u][v] && dist[u] + mat[u][v] < dist[v]) {
                    dist[v] = dist[u] + mat[u][v];
                }
            }
        }

        cout << "Dijkstra's Shortest Path from " << src << ":\n";
        for (int i = 0; i < vertice; i++) {
            cout << "To " << i << ": ";
            if (dist[i] == INF)
                cout << "INF";
            else
                cout << dist[i];
            cout << "\n";
        }
    }
};

int main() {
    int choice, v, u, w, vertice, src;

    cout << "Enter number of vertices (max " << MAX << "): ";
    cin >> vertice;

    if (vertice <= 0 || vertice > MAX) {
        cout << "Invalid number of vertices. Exiting...\n";
        return 0;
    }

    graph g(vertice);

    while (1) {
        cout << "\n---- Graph Algorithm Menu ----\n";
        cout << "1. Insert Edge\n";
        cout << "2. Display Adjacency Matrix\n";
        cout << "3. Prim's MST\n";
        cout << "4. Kruskal's MST\n";
        cout << "5. Dijkstra's Algorithm\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter source, destination, and weight: ";
                cin >> v >> u >> w;
                g.ins(v, u, w);
                break;
            case 2:
                g.display();
                break;
            case 3:
                g.prim();
                break;
            case 4:
                g.kruskal();
                break;
            case 5:
                cout << "Enter source vertex: ";
                cin >> src;
                if (src >= 0 && src < vertice)
                    g.dijkstra(src);
                else
                    cout << "Invalid source vertex\n";
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
