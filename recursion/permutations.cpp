#include <iostream>
#include <vector>
#include <set>
using namespace std;

void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
void permutation(set<string> &ret, string s, int idx = 0)
{
    if (idx == s.size())
    {
        ret.insert(s);
        return;
    }

    for (int i = idx; i < s.size(); i++)
    {
        swap(s[idx], s[i]);
        permutation(ret, s, idx + 1);
        swap(s[idx], s[i]);
    }
    return;
}
// helper function for testcases
vector<string> findSortedPerm(string s)
{
    vector<string> ret;
    set<string> ans;
    permutation(ans, s);
    for (auto x : ans)
    {
        ret.push_back(x);
    }
    return ret;
}
int main()
{
    khushi();
    string s = "abc";
    findSortedPerm(s);
    return 0;
}