class Solution
{
public:
    bool isSubsetSum(vector<int> nums, int sum)
    {
        // code here
        int n = nums.size();
        int t[n + 1][sum + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                {
                    t[i][j] = false;
                }
                if (j == 0)
                {
                    t[i][j] = true;
                }
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (nums[i - 1] <= j)
                {
                    t[i][j] = t[i - 1][j - nums[i - 1]] or t[i - 1][j];
                }
                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        return t[n][sum];
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2 != 0)
        {
            return false;
        }

        return isSubsetSum(nums, sum / 2);
    }
};