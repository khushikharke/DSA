int countPartitions(int n, int d, vector<int> &arr)
{
    // Code here
    int mod = 1e9 + 7;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if ((sum + d) % 2 != 0)
    {
        return 0;
    }
    int s1 = (sum + d) / 2;
    vector<vector<int>> t(n + 1, vector<int>(s1 + 1));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < s1 + 1; j++)
        {
            if (i == 0)
                t[i][j] = 0;
            if (j == 0)
                t[i][j] = 1;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < s1 + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = (t[i - 1][j - arr[i - 1]]) % mod + (t[i - 1][j]) % mod;
            }
            else
            {
                t[i][j] = (t[i - 1][j]) % mod;
            }
        }
    }
    return t[n][s1] % mod;
}