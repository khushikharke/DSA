
#include <bits/stdc++.h>
using namespace std;

void khushi()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
//////////////////////////////////////////////

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
    {
        cin >> x;
    }
    sort(arr.begin(), arr.end());

    long long total = (n * (n + 1)) / 2;

    if (total == arr.back())
    {
        cout << "YES" << endl;
        return;
    }
    if (total < arr.back())
    {
        cout << "NO" << endl;
        return;
    }

    // arr.push_back(total);

    // vector<int> original(n);
    // original[0] = arr[0];
    // for (int i = 1; i < n; i++)
    // {
    //     original[i] = arr[i] - arr[i - 1];
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     if (original[i] != i + 1)
    //     {
    //         cout << "NO" << endl;
    //         return;
    //     }
    // }

    // cout << "YES" << endl;
}

int main()
{

    khushi();
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}