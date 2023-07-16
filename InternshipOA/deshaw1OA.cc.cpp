#include <bits/stdc++.h>
using namespace std;
void khushi()
{
    freopen("input1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
int solve(int n, vector<int> arr, long long k)
{
    int left = 1;
    int right = n;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        long long sum = 0;
        priority_queue<long> pq;
        for (int i = 1; i <= n; i++)
        {
            int temp = i * mid + arr[i - 1];
            sum += temp;
            pq.push(temp);
            if (pq.size() > mid)
            {
                sum -= pq.top();
                pq.pop();
            }
        }

        if (sum <= k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left - 1;
}
int main()
{
    khushi();
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
    }
    long long k;
    cin >> k;
    int ans = solve(4, {4, 3, 2, 1}, 33);
    cout << ans << endl;
    return 0;
}