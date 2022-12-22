#include <iostream>
#include <vector>
// #include <unordered_set>

using namespace std;
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
int saved_water(vector<int> heights)
{
    int n = heights.size();
    if (n <= 2)
    {
        return 0;
    }
    // left initialised with 0's for an arr of n size
    vector<int> left(n, 0);
    // right initialised with 0's for an arr of n size
    vector<int> right(n, 0);
    // initialise first elements
    left[0] = heights[0];
    right[n - 1] = heights[n - 1];

    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], heights[i]);
        right[n - i - 1] = max(right[n - i], heights[n - i - 1]);
    }
    // water
    int saved = 0;
    for (int i = 0; i < n; i++)
    {
        saved += min(left[i], right[i]) - heights[i];
    }
    return saved;
}

int main()
{
    khushi();
    vector<int> water = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << saved_water(water) << endl;
    return 0;
}