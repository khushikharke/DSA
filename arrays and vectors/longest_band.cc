#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int largest_band(vector<int> arr)
{
    unordered_set<int> s;
    int n = arr.size();
    for (int x : arr)
    {
        s.insert(x);
    }
    int largestlen = 1;
    for (int element : s)
    {
        int parent = element - 1;
        if (s.find(parent) == s.end())
        {
            // nhi h parent toh vhi element start hua
            // series bnaao

            int next = element + 1;
            int cnt = 1;

            while (s.find(next) != s.end())
            {
                // next  element dhoondh rhe h
                next++;
                cnt++;
            }
            if (cnt > largestlen)
            {
                largestlen = cnt;
            }
        }
    }
    return largestlen;
}
//
int main()
{
    khushi();
    vector<int> arr = {1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
    cout << largest_band << endl;
    return 0;
}