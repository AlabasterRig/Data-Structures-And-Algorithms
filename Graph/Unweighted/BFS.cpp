#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void BFS(vector<vector<int>>& Adj, int S, vector<bool>& Visited)
{
    queue<int> Q;
    Visited[S] = true;
    Q.push(S);

    while(!Q.empty())
    {
        int curr = Q.front();
        Q.pop();
        cout << curr << " ";

        for(int i : Adj[curr])
        {
            if(!Visited[i])
            {
                Visited[i] = true;
                Q.push(i);
            }
        }
    }
}

void AddEdge(vector<vector<int>>& Adj, int u, int v)
{
    Adj[u].push_back(v);
    Adj[v].push_back(u);
}

int main()
{
    int n = 9;
    vector<vector<int>> Adj(n);

    AddEdge(Adj, 0, 1);
    AddEdge(Adj, 1, 3);
    AddEdge(Adj, 3, 8);
    AddEdge(Adj, 2, 5);
    AddEdge(Adj, 0, 2);
    AddEdge(Adj, 1, 4);
    AddEdge(Adj, 2, 6);
    AddEdge(Adj, 3, 7);

    vector<bool> Visited(n, false);

    BFS(Adj, 0, Visited);
}