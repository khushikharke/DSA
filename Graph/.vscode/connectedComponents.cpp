class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &isConnected)
    {
        vis[node] = 1;
        for (int i = 0; i < isConnected[node].size(); i++)
        {
            if (!vis[i] && isConnected[node][i] && i != node)
            {
                dfs(i, vis, isConnected);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            isConnected[i][i] = 0;
            if (!vis[i])
            {
                dfs(i, vis, isConnected);
                ans++;
            }
        }
        return ans;
    }
};