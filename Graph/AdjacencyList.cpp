#include <iostream>
#include <vector>
using namespace std;

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

    for (int i = 0; i < nodes; i++)
    {
        cout << i << ": ";
        for (auto &x : AdjacencyList[i])
            cout << x << " ";
        cout << endl;
    }

    return 0;
}