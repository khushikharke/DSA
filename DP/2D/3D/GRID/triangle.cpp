class Solution
{
public:
    int paths(int m, int n, int &size, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if (dp[m][n] != -1)
            return dp[m][n];
        if (m == size)
        {
            return triangle[m][n];
        }
        int down = triangle[m][n] + paths(m + 1, n, size, triangle, dp);
        int diagonal = triangle[m][n] + paths(m + 1, n + 1, size, triangle, dp);
        return dp[m][n] = min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int size = triangle.size() - 1;
        int n = triangle.size();
        // int m =triangle[0].size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return paths(0, 0, size, triangle, dp);
    }
};