#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj)
    {
        // Code here
        int V = adj.size();
        vector<bool> visited(V, false);
        vector<int> path;

        queue<int> q;

        int src = 0;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            path.push_back(current);
            for (int x : adj[current])
            {
                if (!visited[x])
                {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        return path;
    }
};
