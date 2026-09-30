#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[10];
bool visited[10];

void DFS(int vertex)
{
    cout << vertex << " ";
    visited[vertex] = true;

    for (int next : graph[vertex])
    {
        if (!visited[next])
            DFS(next);
    }
}

void BFS(int start)
{
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();

        cout << vertex << " ";

        for (int next : graph[vertex])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    int n, edges, u, v, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges:\n";

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    for (int i = 0; i < n; i++)
        visited[i] = false;

    cout << "DFS: ";
    DFS(start);

    for (int i = 0; i < n; i++)
        visited[i] = false;

    cout << "\nBFS: ";
    BFS(start);

    return 0;
}