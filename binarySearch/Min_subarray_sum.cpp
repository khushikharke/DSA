class Solution
{
public:
    bool window(int size, vector<int> &nums, int target)
    {
        int sum = 0, i = 0, j = 0;
        int n = nums.size();
        int mx = INT_MIN;
        while (j < n)
        {
            sum += nums[j];
            if (j - i + 1 == size)
            {
                mx = max(mx, sum);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        if (mx >= target)
            return true;
        return false;
    }
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int start = 1;
        int end = nums.size();
        int len = 0;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (window(mid, nums, target))
            {
                end = mid - 1;
                len = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        return len;
    }
};