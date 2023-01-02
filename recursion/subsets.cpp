#include <iostream>
#include <vector>
using namespace std;
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int subset(vector<int> arr, int n, int i, int sum)
{
    if (i == n)
    {
        if (sum == 0)
        {
            return 1;
        }
        return 0;
    }
    int inc = subset(arr, n, i + 1, sum - arr[i]);
    int exc = subset(arr, n, i + 1, sum);
    return inc + exc;
}
int main()
{
    khushi();
    vector<int> arr{1, 2, 3, 4, 5};
    int sum = 6;
    cout << subset(arr, arr.size(), 0, sum) << endl;

    return 0;
}