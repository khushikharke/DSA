#include <bits/stdc++.h>
int helper(int r, int c, vector<vector<int>> &grid, int alicei, int alicej, int bobi, int bobj, vector<vector<vector<int>>> &dp)
{

    if (alicei == r || bobi == r || alicej < 0 || bobj < 0 || alicej > c - 1 || bobj > c - 1)
    {

        return 0;
    }

    int alicetemp = grid[alicei][alicej];

    int bobtemp = grid[bobi][bobj];

    if (alicei == r - 1 && bobi == r - 1)
    {

        if (alicej != bobj)
        {

            return alicetemp + bobtemp;
        }

        return alicetemp;
    }

    if (dp[alicei][alicej][bobj] != -1)
    {

        return dp[alicei][alicej][bobj];
    }

    int choco = INT_MIN;

    for (int i = -1; i < 2; i++)
    {

        for (int j = -1; j < 2; j++)
        {

            choco = max(choco, helper(r, c, grid, alicei + 1, alicej + i, bobi + 1, bobj + j, dp));
        }
    }

    if (alicej != bobj)
    {

        return dp[alicei][alicej][bobj] = alicetemp + bobtemp + choco;
    }

    return dp[alicei][alicej][bobj] = alicetemp + choco;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{

    // Write your code here.

    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

    return helper(r, c, grid, 0, 0, 0, c - 1, dp);
}