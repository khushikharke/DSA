class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int k = 0;
        while (k < n)
        {
            if (nums[k] == 0)
            {
                break;
            }
            else
            {
                k += 1;
            }
        }

        int i = k;
        int j = k + 1;
        while (i < n && j < n)
        {
            if (nums[j] != 0)
            {
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
    }
};