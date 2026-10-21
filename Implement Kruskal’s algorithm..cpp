#include <iostream>
using namespace std;

int main()
{
    int n, e;
    int u[50], v[50], w[50];
    int parent[50];
    int i, j, temp;
    int minCost = 0, count = 0;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    for (i = 0; i < e; i++)
    {
        cout << "Enter source, destination and weight: ";
        cin >> u[i] >> v[i] >> w[i];
    }

    // Initialize parent array
    for (i = 0; i < n; i++)
        parent[i] = i;

    // Sort edges by weight using bubble sort
    for (i = 0; i < e - 1; i++)
    {
        for (j = 0; j < e - i - 1; j++)
        {
            if (w[j] > w[j + 1])
            {
                temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;

                temp = u[j];
                u[j] = u[j + 1];
                u[j + 1] = temp;

                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }

    cout << "\nEdges in Minimum Spanning Tree:\n";

    // Kruskal's algorithm
    for (i = 0; i < e; i++)
    {
        int a = u[i];
        int b = v[i];

        while (parent[a] != a)
            a = parent[a];

        while (parent[b] != b)
            b = parent[b];

        if (a != b)
        {
            cout << u[i] << " - " << v[i]
                 << " : " << w[i] << endl;

            minCost += w[i];
            parent[a] = b;
            count++;

            if (count == n - 1)
                break;
        }
    }

    if (count == n - 1)
        cout << "Minimum cost = " << minCost << endl;
    else
        cout << "Minimum Spanning Tree is not possible.\n";

    return 0;
}
