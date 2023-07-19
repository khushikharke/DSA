class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;

        int vis[n][m];
        int count_fresh = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else
                {
                    vis[i][j] = 0;
                }
                if (grid[i][j] == 1)
                {
                    count_fresh++;
                }
            }
        }

        int to = 0;
        int nrows[] = {-1, 0, 1, 0};
        int ncols[] = {0, 1, 0, -1};
        int cnt = 0;
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            to = max(to, t);
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int row = r + nrows[i];
                int col = c + ncols[i];
                if (row >= 0 and col >= 0 and col < m and row < n and !vis[row][col] and grid[row][col] == 1)
                {
                    q.push({{row, col}, t + 1});
                    vis[row][col] = 2;
                    cnt++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] != 2 and grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return to;
    }
};