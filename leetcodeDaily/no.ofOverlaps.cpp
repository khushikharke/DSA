class Solution
{
public:
    static bool comp(vector<int> &first, vector<int> &second)
    {
        return first[1] < second[1];
    }

    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), comp);
        int prev = 0;
        int ans = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[prev][1] > intervals[i][0])
            {
                ans++;
            }
            else
            {
                prev = i;
            }
        }
        return ans;
    }
};