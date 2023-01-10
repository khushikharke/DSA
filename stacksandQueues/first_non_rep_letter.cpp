#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main()
{
    khushi();
    // queue telling the front char
    queue<char> q;
    // map of max 27 letters telling freq of each letter
    int freq[27] = {0};
    char ch;
    cin >> ch;
    while (ch != '.')
    {
        q.push(ch);
        freq[ch - 'a']++;
        while (!q.empty())
        {
            int idx = q.front() - 'a';
            if (freq[idx] > 1)
            {
                q.pop();
            }
            else
            {
                cout << q.front();
                break;
            }
        }
        if (q.empty())
        {
            cout << "-1";
        }
        cin >> ch;
    }

    return 0;
}