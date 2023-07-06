
class Solution
{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> t(N, vector<int>(N));

        for (int i = 1; i < N; i++)
        {
            t[i][i] = 0;
        }

        for (int i = N - 1; i >= 1; i--)
        {
            for (int j = i + 1; j < N; j++)
            {
                int mn = INT_MAX;

                for (int k = i; k < j; k++)
                {
                    int temp = t[i][k] + t[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);
                    mn = min(mn, temp);
                }
                t[i][j] = mn;
            }
        }

        return t[1][N - 1];
        // memset(t,-1,sizeof(t));
        // return solve(t,N,arr,1,N-1);
    }
};