class Solution
{
public:
    int mod = 1e9 + 7;
    long long solve(int n, vector<int> &dp)
    {
        if (n < 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = (solve(n - 1, dp) + solve(n - 2, dp)) % mod;
    }
    // Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
