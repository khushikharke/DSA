#include <iostream>
#include <deque>
#include <vector>
#include <string>
using namespace std;
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
void maxSubArrayK(vector<int> a, int n, int k)
{
    int i;
    // algorithm
    // 1.process only k elements
    deque<int> Q(k);
    for (int i = 0; i < k; i++)
    {
        while (!Q.empty() and a[i] > a[Q.back()])
        {
            Q.pop_back();
        }
        Q.push_back(i);
    }
    // 2. process remaining
    for (int i = k; i <= a.size(); i++)
    {
        // remove element from left
        cout << a[Q.front()] << " ";
        // remove elements from the left (lies outside of window)
        while (!Q.empty() and Q.front() <= i - k)
        {
            Q.pop_front();
        }
        while (!Q.empty() and a[i] >= a[Q.back()])
        {
            Q.pop_back();
        }

        Q.push_back(i);
    }
    // for the laast window
    // cout << a[Q.front()];
}
int main()
{
    khushi();
    vector<int> arr{1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    int n = 9;
    maxSubArrayK(arr, n, k);

    return 0;
}