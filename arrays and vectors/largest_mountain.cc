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
int highest_pahad(vector<int> arr)
{
    int n = arr.size();
    int largest = 0;
    for (int i = 1; i < n - 2;)
    {
        // largest=arr[i];
        if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1]) // peak
        {
            int count = 1;
            int j = i;
            // count backwards//to check length
            while (j >= 1 and arr[j] > arr[j - 1])
            {
                j--;
                count++;
            }
            // count forward//to check length
            while (i <= n - 2 and arr[i] > arr[i + 1])
            {
                // skip
                i++;
                count++;
            }
            largest = max(largest, count); // count=sum of frwd+bckwrd
        }
        else // not a peak simply skip++

        {
            i++;
        }
    }
    return largest;
}
int main()
{
    khushi();
    vector<int> arr{5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    cout << highest_pahad(arr);
}