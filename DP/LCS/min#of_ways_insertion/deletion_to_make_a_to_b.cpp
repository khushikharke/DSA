class solution
{
public:
    int minOperations(string str1, string str2)
    {
        // Your code goes here
        int n = str1.size();
        int m = str2.size();
        int t[n + 1][m + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                if (i == 0 || j == 0)
                {
                    t[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    t[i][j] = 1 + t[i - 1][j - 1];
                }
                else
                {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }
        int len_lcs = t[n][m];
        int ans = (n - len_lcs) + (m - len_lcs);

        return ans;
    }
};