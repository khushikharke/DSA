#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
int ans = 0;
int countMInSwaps(vector<int> arr)
{
    int n = arr.size();
    pair<int, int> ap[n];
    for (int i = 0; i < n; i++)
    {
        ap[i].first = arr[i];
        ap[i].second = i;
        // 5 4 3 2 1
        // 0 1 2 3 4
    }
    sort(ap, ap + n);
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        // if element is visited or is in right position simply ignore
        int old = ap[i].second;
        if (visited[i] == true or old == i)
        {
            continue;
        }

        // if visiting item for first time then swap
        int node = i;
        int cycle = 1;
        while (!visited[node])
        {
            visited[node] = true;
            int next = ap[node].second;
            node = next;
            cycle += 1;
        }
        ans += (cycle - 1);
    }
    return ans;
}

int main()
{
    khushi();
    vector<int> arr{5, 4, 3, 2, 1};
    cout << countMInSwaps(arr) << endl;
    return 0;
}
