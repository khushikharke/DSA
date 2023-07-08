class Solution
{
public:
    int solve(vector<int> &nums, int i, int j, vector<vector<int>> &t)
    {
        int ans = INT_MIN;
        if (i > j)
            return 0;
        if (t[i][j] != -1)
            return t[i][j];
        for (int k = i; k <= j; k++)
        {
            int temp = (nums[i - 1] * nums[j + 1] * nums[k]) + solve(nums, i, k - 1, t) + solve(nums, k + 1, j, t);
            ans = max(ans, temp);
        }
        return t[i][j] = ans;
    }
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> t(n + 1, vector<int>(n + 1, -1));
        return solve(nums, 1, n, t);
    }
};