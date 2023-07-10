class Solution
{
public:
    int paths(int m, int n, vector<vector<int>> &dp)
    {
        if (m < 0 or n < 0)
        {
            return 0;
        }
        if (m == 0 or n == 0)
        {
            return 1;
        }
        if (dp[m][n] != -1)
            return dp[m][n];

        int count = paths(m - 1, n, dp) + paths(m, n - 1, dp);
        return dp[m][n] = count;
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return paths(m - 1, n - 1, dp);
    }
};