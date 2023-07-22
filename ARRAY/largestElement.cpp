#include <bits/stdc++.h>
int m = INT_MIN;
int largestElement(vector<int> &arr, int n)
{
    // Write your code here.

    for (int i = 0; i < n; i++)
    {
        m = max(m, arr[i]);
    }
    return m;
}