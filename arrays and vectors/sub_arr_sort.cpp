#include <iostream>
#include <vector>
#include <algorithm>
// tough h
using namespace std;
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
bool outOfOrder(vector<int> arr, int i)
{
    int x = arr[i];
    if (i == 0) // first element
    {
        return x > arr[i];
    }
    if (i == arr.size() - 1) // last element
    {
        return x < arr[i - 1];
    }
    return x > arr[i] or x < arr[i]; // arr
}
pair<int, int> subarraySort(vector<int> arr)
{
    int smallest = INT_FAST64_MIN;
    int largest = INT_FAST32_MAX;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        if (outOfOrder(arr, i))
        {
            smallest = min(smallest, x);
            largest = max(largest, x);
        }
    }
    // next step is to find the actual index where smallest and largest needs to be placed
    if (smallest == INT_FAST16_MIN)
    {
        return {-1, -1};
    }
    int left = 0;
    while (smallest >= arr[left])
    {
        left++;
    }
    int right = arr.size() - 1;
    while (largest <= arr[right])
    {
        right--;
    }
    return {left, right};
}

int main()
{
    khushi();
    vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    auto p = subarraySort(arr);
    cout << p.first << " " << p.second << endl;
    return 0;
}
