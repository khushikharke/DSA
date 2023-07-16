#include <bits/stdc++.h>

using namespace std;

int solution(const vector<int> &v, int x)
{
    vector<int> dp(2);
    for (int i = 1; i < v.size(); ++i)
    {
        dp = {max(abs(v[i] - v[i - 1]) + dp[0], abs(v[i] - (v[i - 1] ^ x)) + dp[1]),
              max(abs((v[i] ^ x) - v[i - 1]) + dp[0], abs((v[i] ^ x) - (v[i - 1] ^ x)) + dp[1])};
    }
    return max(dp[0], dp[1]);
}
int main()
{
    cout << solution({1, 2, 1}, 2) << endl;
    cout << solution({1, 1, 1}, 1) << endl;
    return 0;
}