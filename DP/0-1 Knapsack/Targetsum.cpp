
class Solution
{
public:
    int findTargetSumWays(vector<int> &A, int target)
    {
        // Your code here
        int n = A.size();
        int range = 0;
        for (int i = 0; i < n; i++)
        {
            range += A[i];
        }
        if (range - target < 0 or ((target + range) % 2))
        {
            return 0;
        }
        int sum = (range + target) / 2;

        int t[n + 1][sum + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                    t[i][j] = 0;
                if (j == 0)
                    t[i][j] = 1;
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (A[i - 1] <= j)
                {
                    t[i][j] = t[i - 1][j - A[i - 1]] + t[i - 1][j];
                }
                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return t[n][sum];
    }
};