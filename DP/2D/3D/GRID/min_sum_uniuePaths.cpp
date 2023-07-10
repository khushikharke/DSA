class Solution
{
public:
    int paths(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (m == 0 and n == 0)
            return grid[0][0];

        if (m < 0 or n < 0)
            return 1e9;

        if (dp[m][n] != -1)
            return dp[m][n];

        int up = grid[m][n] + paths(m - 1, n, grid, dp);
        int left = grid[m][n] + paths(m, n - 1, grid, dp);

        return dp[m][n] = min(up, left);
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return paths(m - 1, n - 1, grid, dp);
    }
};