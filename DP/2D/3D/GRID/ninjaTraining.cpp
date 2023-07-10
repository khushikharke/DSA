#include <bits/stdc++.h>
using namespace std;

int f(int day, int prev, vector<vector<int>> &points, vector<vector<int>> &dp)
{

    if (day < 0)
        return 0;
    if (dp[day][prev] != -1)
        return dp[day][prev];

    int maxi = 0;
    for (int i = 0; i < points[day].size(); i++)
    {
        if (i != prev)
        {
            int pnts = points[day][i] + f(day - 1, i, points, dp);
            maxi = max(maxi, pnts);
        }
    }
    return dp[day][prev] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(n - 1, 3, points, dp);

    // Write your code here.
}