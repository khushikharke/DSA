#include <bits/stdc++.h>
// #include <iostream>
using namespace std;

const int maxn = 100005;
unordered_map<int, int> weight[maxn];
vector<int> adj[maxn];
int depth[maxn];
int parent[maxn];

// void khushi()
// {
//     freopen("input1.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// }
void dfs(int node, int par, int d)
{
    depth[node] = d;
    parent[node] = par;

    for (int child : adj[node])
    {
        if (child != par)
        {
            dfs(child, node, d + 1);
        }
    }
}

int main()
{
    // khushi();
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        weight[u][v] = w;
        weight[v][u] = w;
    }
    dfs(1, 0, 0);
    int Q;
    cin >> Q;
    while (Q--)
    {
        int u, v;
        cin >> u >> v;
        int opr = 0;
        while (u != v)
        {
            if (weight[u][v] != weight[v][u])
            {
                if (depth[u] > depth[v])
                {
                    opr += abs(weight[u][v] - weight[v][u]);
                    weight[u][v] = weight[v][u];
                    u = parent[u];
                }
                else
                {
                    opr += abs(weight[v][u] - weight[u][v]);
                    weight[v][u = weight[u][v]];
                    v = parent[v];
                }
            }
            else
            {
                u = parent[u];
                v = parent[v];
            }
        }
        cout << opr << " ";
    }
    return 0;
}