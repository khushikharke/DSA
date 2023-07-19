class Solution
{
public:
    bool helper(string &s, unordered_set<string> &set, int start, vector<int> &dp)
    {

        if (start == s.size())
        {
            return true;
        }
        if (dp[start] != -1)
        {
            return dp[start];
        }
        for (int i = start; i < s.size(); i++)
        {
            if (set.count(s.substr(start, i + 1 - start)) && helper(s, set, i + 1, dp))
            {
                dp[i] = true;
                return true;
            }
        }
        return dp[start] = false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> dp(s.size(), -1);
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        return helper(s, set, 0, dp);
    }
};