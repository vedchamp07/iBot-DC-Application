#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void recursion(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &path)
    {
        visited[s] = true;
        path.push_back(s);
        for (int i : adj[s])
        {
            if (visited[i] == false)
            {
                recursion(adj, visited, i, path);
            }
        }
    }
    vector<int> dfs(vector<vector<int>> &adj)
    {
        vector<bool> visited(adj.size(), false);
        vector<int> path;
        recursion(adj, visited, 0, path);
        return path;
    }
};