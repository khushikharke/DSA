
class Solution
{
public:
    int solve(vector<vector<int>> &t, int arr[], int i, int j)
    {

        if (i >= j)
            return 0;
        if (t[i][j] != -1)
        {
            return t[i][j];
        }
        int mn = INT_MAX;

        for (int k = i; k <= j - 1; k++)
        {
            int temp = solve(t, arr, i, k) + solve(t, arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
            if (temp < mn)
            {
                mn = temp;
            }
        }
        return t[i][j] = mn;
    }

    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> t(N, vector<int>(N, -1));
        // memset(t,-1,sizeof(t));
        return solve(t, arr, 1, N - 1);
    }
};