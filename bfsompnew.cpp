#include <iostream>
#include <vector>
#include <queue>
#include <omp.h>

using namespace std;

void parallelBFS(vector<vector<int>>& graph, int start, int n) {

    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        cout << node << " ";

        #pragma omp parallel for
        for (int i = 0; i < graph[node].size(); i++) {

            int neighbor = graph[node][i];

            #pragma omp critical
            {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    cout << endl;
}

int main() {

    int n, e;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> graph(n);

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;

    cout << "Enter starting node: ";
    cin >> start;

    parallelBFS(graph, start, n);

    return 0;
}
