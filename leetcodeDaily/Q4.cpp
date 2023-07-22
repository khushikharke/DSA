#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinRemovedProblems(vector<int> &arr, int k)
{
    const int n = arr.size();
    if (n == 1)
        return 0;
    sort(arr.begin(), arr.end());
    int count = 1, mx = 1;
    vector<int> diff(n - 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        diff[i] = abs(arr[i] - arr[i + 1]);
        if (diff[i] <= k)
        {
            count++;
        }
        else
        {
            count = 1;
        }
        mx = max(mx, count);
    }

    return mx;
}
// bbccbbzz
string solve(string s)
{
    string ans = "";
    char curr = s[0];
    int freq = 1;
    const int n = s.size();
    for (int i = 1; i < n; i++)
    {
        if (s[i] == curr)
        {
            freq++;
        }
        else
        {
            ans += curr + to_string(freq);
            freq = 1;
            curr = s[i];
        }
    }

    ans += curr + to_string(freq);
    return ans;
}

void fileio()
{
    freopen("input.txt", "r", stdin);
}

int main()
{
    fileio();
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     int n, k;
    //     cin >> n >> k;
    //     vector<int> problems(n);
    //     for (int i = 0; i < n; i++)
    //     {
    //         cin >> problems[i];
    //     }
    //     cout << findMinRemovedProblems(problems, k) << endl;
    // }

    cout << solve("bbccbbzz");
    return 0;
}
