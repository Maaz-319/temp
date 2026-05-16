#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> Graph(int vertices, vector<vector<int>> &edges)
{
    vector<vector<int>> matrix(vertices, vector<int>(vertices, 0));

    for (auto &x : edges)
    {
        matrix[x[0]][x[1]] = 1;
        matrix[x[1]][x[0]] = 1; // added for undirected graph
    }

    return matrix;
}

int main()
{
    int nodes = 5;

    vector<vector<int>> edges = {{0, 1}, {0, 2}, {4, 3}, {2, 4}, {3, 0}};

    vector<vector<int>> AdjacencyMatrix = Graph(nodes, edges);

    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
            cout << AdjacencyMatrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}