#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long solve(int i, int n, int k, string &s, int curr, int curr_size, vector<unordered_map<int, int>> &dp, int sum, vector<int> &count)
{
    if (i == n)
        return (curr_size == k && sum == 0);
    if (sum < 0)
        return 0;
    if (curr_size == k)
        return sum == 0;
    if (dp[i].find(curr) != dp[i].end())
        return dp[i][curr];
    long long take = 0, notTake = 0;
    notTake = solve(i + 1, n, k, s, curr, curr_size, dp, sum, count);
    bool taken = (curr & (1 << (s[i] - 'a')));
    if (!taken)
        take = solve(i + 1, n, k, s, (curr | (1 << (s[i] - 'a'))), curr_size + 1, dp, sum - count[s[i] - 'a'], count);
    return dp[i][curr] = (take + notTake) % mod;
}
int main()
{
    int k = 8;
    // cin >> n >> k;
    string s = "fpbavjsmppdt";
    int n = s.size();

    // cin >> s;
    vector<unordered_map<int, int>> dp(n);

    if (k > 26)
        cout << 0 << endl;
    vector<int> count(26, 0);
    for (int i = 0; i < n; i++)
    {
        count[s[i] - 'a']++;
    }
    // priority_queue<int> heap;

    // for (int i = 0; i < 26; i++)
    //     heap.push(count[i]);

    // int sum = 0;
    // // counting max_sum later will be use for comparison whether we have found the right subsequence or not
    // for (int i = 0; i < k; i++)
    // {
    //     sum += heap.top();
    //     heap.pop();
    // }
    int sum = 0;
    auto curr = count;
    sort(curr)
            cout
        << solve(0, n, k, s, 0, 0, dp, sum, count);
}