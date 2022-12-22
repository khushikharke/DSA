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

vector<vector<int>> triplet(vector<int> arr, int target_sum)
{
    // unordered_set<int> s;
    int n = arr.size();
    vector<vector<int>> result;

    sort(arr.begin(), arr.end());
    // pick one and find pair sum for remaining part
    for (int i = 0; i < n - 3; i++)
    {
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int currentSum = arr[i];
            currentSum += arr[j];
            currentSum += arr[k];
            if (currentSum == target_sum)
            {
                result.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
            }
            else if (currentSum > target_sum)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return result;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "r", stdout);'
    khushi();
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int sum = 18;

    auto result = triplet(arr, sum);
    for (auto x : result)
    {
        for (auto y : x)
        {
            cout << y << ",";
        }
        cout << endl;
    }
    return 0;
}
