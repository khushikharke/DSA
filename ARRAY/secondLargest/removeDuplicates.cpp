class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int nonr = 0;
        for (int repeat = 1; repeat < nums.size(); repeat++)
        {
            if (nums[nonr] != nums[repeat])
            {
                nonr++;
                nums[nonr] = nums[repeat];
            }
        }
        return nonr + 1;
    }
};