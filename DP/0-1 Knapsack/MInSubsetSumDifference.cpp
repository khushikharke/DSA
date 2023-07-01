class solution
{
public:
    int minDifference(int arr[], int n)
    {
        // Your code goes here
        int sum = 0;
        int mn = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            sum = sum + arr[i];
        }

        int t[n + 1][sum + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                {
                    t[i][j] = 0;
                }
                if (j == 0)
                {
                    t[i][j] = 1;
                }
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (arr[i - 1] <= j)
                {
                    t[i][j] = t[i - 1][j - arr[i - 1]] or t[i - 1][j];
                }
                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        for (int k = 0; k < sum + 1; k++)
        {
            if (t[n][k] == 1)
            {
                mn = min(mn, abs(sum - 2 * k));
            }
        }
        return mn;
    }
};
git