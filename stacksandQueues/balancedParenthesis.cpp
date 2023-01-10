#include <iostream>
#include <stack>
#include <string>
using namespace std;
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

bool isBalanced(string input)
{
    stack<char> s;
    for (auto ch : input)
    {
        switch (ch)
        {
        case '(':
        case '{':
        case '[':
            s.push(ch);
            break;

        case ')':
            if (!s.empty() and s.top() == '(')
            {
                s.pop();
            }
            else
            {
                return false;
            }
            break;
        case '}':
            if (!s.empty() and s.top() == '{')
            {
                s.pop();
            }
            else
            {
                return false;
            }
            break;
        case ']':
            if (!s.empty() and s.top() == '[')
            {
                s.pop();
            }
            else
            {
                return false;
            }
            break;
        default:
            continue;
        }
    }
    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    khushi();
    string s = " ((a+b+c) + [d]}";
    if (isBalanced(s))
    {
        cout << "Balanced!" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }
    return 0;
}