#include <iostream>
#include <climits>
using namespace std;

#define V 4

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool visited[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int min = INT_MAX;
        int u = -1;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && key[v] < min)
            {
                min = key[v];
                u = v;
            }
        }

        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalCost = 0;

    cout << "Roads selected for MST:\n";
    cout << "Road\tCost\n";

    for (int i = 1; i < V; i++)
    {
        cout << parent[i] + 1 << " - "
             << i + 1 << "\t"
             << graph[i][parent[i]] << endl;

        totalCost += graph[i][parent[i]];
    }

    cout << "Minimum construction cost = "
         << totalCost << endl;
}

int main()
{
    int graph[V][V] = {
        {0, 10, 6, 5},
        {10, 0, 0, 15},
        {6, 0, 0, 4},
        {5, 15, 4, 0}
    };

    primMST(graph);

    return 0;
}
