
#include <iostream>
using namespace std;

#define MAX 100
#define INF 99999

int main()
{
    int n, cost[MAX][MAX];
    int key[MAX], parent[MAX];
    bool mstSet[MAX];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter cost adjacency matrix:\n";

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> cost[i][j];

    for(int i = 0; i < n; i++)
    {
        key[i] = INF;
        mstSet[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;

    for(int count = 0; count < n - 1; count++)
    {
        int u = -1;

        for(int i = 0; i < n; i++)
            if(!mstSet[i] && (u == -1 || key[i] < key[u]))
                u = i;

        mstSet[u] = true;

        for(int v = 0; v < n; v++)
        {
            if(cost[u][v] != 0 && !mstSet[v] &&
               cost[u][v] < key[v])
            {
                key[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;

    cout << "\nMinimum Spanning Tree:\n";

    for(int i = 1; i < n; i++)
    {
        cout << parent[i] << " - " << i
             << " : " << cost[i][parent[i]] << endl;

        total += cost[i][parent[i]];
    }

    cout << "Minimum Cost = " << total;

    return 0;
}
