#include <bits/stdc++.h>
#include <string>
using namespace std;
// void khushi()
// {
//     freopen("input.txt", "r", stdin);
//     freopne("output.txt", "w", stdout);
// }
string longestPalindromicSubstring(string s)
{
    // code here
    string temp =””;
    Int idx = 0;
    Int mx = INT_MIN;
    for (int i = 0; i < s.size(); i++)
    {
        string sub = s.substr(i + 1 - idx);
        int l = sub.size();
        l = max(l, mx);
        lrev = reverse(l.begin(), l.end());
        if (l == lrev)
            temp = l;
    }
    return temp;
}

int main()
{
    // void khushi();
    string x = "babad";
    cout << longestPalindromicSubstring(x);
    return 0;
}
