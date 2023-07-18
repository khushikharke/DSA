#include <bits/stdc++.h>
#include <vector>
#include <cmath>

using namespace std;
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

string canVikaEscape(int n, int m, int k, int x, int y, vector<pair<int, int>> &friends)
{
    // Check if any friend can reach Vika's position in one move
    for (const auto &friendPos : friends)
    {
        int dirx = [ +1, 0, -1, 0 ];
        int diry = [ 0, -1, 0, +1 ];
        for (auto &i : dirx)
        {
            for (auto &j : diry)
            {
                int dx = x + i;
                int dy = y + j;
                if (abs(friendPos.first - dx) + abs(friendPos.second - dy) <= 1)
                {
                    return "NO";
                }
            }
        }
    }

    return "YES";
}

int main()
{
    khushi();
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        int x, y;
        cin >> x >> y;

        vector<pair<int, int>> friends(k);
        for (int i = 0; i < k; i++)
        {
            cin >> friends[i].first >> friends[i].second;
        }

        string result = canVikaEscape(n, m, k, x, y, friends);
        cout << result << endl;
    }

    return 0;
}
