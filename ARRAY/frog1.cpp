#include <bits/stdc++.h>
using namespace std;

void khushi()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int countCompleteSubarrays(std::vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    int left = 0;
    unordered_map<int, int> freqMap;

    for (int right = 0; right < n; ++right)
    {
        freqMap[nums[right]]++;

        while (freqMap.size() > right - left + 1)
        {
            freqMap[nums[left]]--;
            if (freqMap[nums[left]] == 0)
                freqMap.erase(nums[left]);
            left++;
        }
        if (freqMap.size() == freqMap.size())
            count++;
    }

    return count;
}

int main()
{
    khushi();
    vector<int> nums = {1, 3, 1, 2, 2};
    int result = countCompleteSubarrays(nums);
    std::cout << "Number of complete subarrays: " << result << std::endl;

    return 0;
}

// void solve()
// {
//     int n;
//     cin >> n;
//     vector<int> students(n);
//     int cnt = 0;

//     for (int i = 1; i <= n; i++)
//     {
//         cin >> students[i - 1];
//         if (students[i - 1] == i)
//         {
//             cnt++;
//         }
//     }
//     int d = cnt / 2;
//     if (cnt % 2 != 0)
//     {
//         d++;
//     }
//     cout << d << endl;
// }

// int main()
// {
//     khushi();
//     int tc;
//     cin >> tc;
//     while (tc--)
//     {
//         solve();
//     }
//     return 0;
// }
