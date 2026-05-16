#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &adjList, int s, vector<bool> &visited)
{
    visited[s] = true;
    cout << s<< " ";

    for (int i : adjList[s])
        if (!visited[i])
            dfs(adjList, i, visited);
}

vector<vector<int>> Graph(int vertices, vector<vector<int>> &edges)
{
    vector<vector<int>> List(vertices);

    for (auto &x : edges)
    {
        List[x[0]].push_back(x[1]);
        List[x[1]].push_back(x[0]); // added for undirected graph
    }

    return List;
}

int main()
{
    int nodes = 5;

    vector<vector<int>> edges = {{0, 1}, {0, 2}, {4, 3}, {2, 4}, {3, 0}};
    vector<vector<int>> AdjacencyList = Graph(nodes, edges);
    vector<bool> visited(nodes, false);
    vector<int> res(nodes);

    for (int i = 0; i < nodes; i++)
    {
        cout << i << ": ";
        for (auto &x : AdjacencyList[i])
            cout << x << " ";
        cout << endl;
    }

    cout << "\n\nDFS:\n";
    dfs(edges, 0, visited);

    return 0;
}