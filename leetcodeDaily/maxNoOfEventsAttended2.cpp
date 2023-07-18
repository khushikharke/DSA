class Solution
{
public:
    int dfs(int curr, int count, int prevend, vector<vector<int>> &events, int k, vector<vector<int>> &dp)
    {
        if (curr == events.size() or count == k)
        {
            return 0;
        }
        if (prevend >= events[curr][0])
        {
            return dfs(curr + 1, count, prevend, events, k, dp);
        }

        if (dp[count][curr] != -1)
        {
            return dp[count][curr];
        }
        int ans = max(dfs(curr + 1, count, prevend, events, k, dp), dfs(curr + 1, count + 1, events[curr][1], events, k, dp) + events[curr][2]);
        dp[count][curr] = ans;
        return ans;
    }

    int maxValue(vector<vector<int>> &events, int k)
    {
        sort(events.begin(), events.end(), [](const vector<int> &a, const vector<int> &b)
             {
                 return a[0] < b[0];
                 // start time se sort
             });

        int n = events.size();
        vector<vector<int>> dp(k + 1, vector<int>(n, -1));
        return dfs(0, 0, -1, events, k, dp);
    }
};