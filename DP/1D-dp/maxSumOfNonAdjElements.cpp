#include <bits/stdc++.h>
int solve(vector<int> &nums, int i, vector<int> &dp)
{
    if (i == 0)
        return nums[i];
    if (i < 0)
        return 0;
    if (dp[i] != -1)
    {
        return dp[i];
    }
    // int mx=INT_MIN;
    int taken = nums[i] + solve(nums, i - 2, dp);
    int nottaken = 0 + solve(nums, i - 1, dp);
    return dp[i] = max(taken, nottaken);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(nums, n - 1, dp);
}