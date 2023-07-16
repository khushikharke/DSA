#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
// int ans;
int lcs(string s, int k, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        // dp[0][j] = 0;

        dp[i][0] = 1;
    }

    for (int i = 1; i < n + 1; i++)
    {
        unordered_set<char> included;
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (included.find(s[i - 1]) == included.end())
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]);
                included.insert(s[i - 1]);
            }
        }
    }
    return dp[n - 1][k - 1];
}

int main()
{
    int tc = 1;
    int k = 4;
    int n = 5;
    string s = "cppbg";
    cout << lcs(s, k, n) << endl;
}