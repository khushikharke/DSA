#include <iostream>
#include <stack>
#include <string>

using namespace std;
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

bool isRedundant(string input)
{
    stack<char> s;
    for (auto ch : input)
    {
        if (ch != ')')
        {
            s.push(ch); // a,b,-,+,*,/
        }
        else
        {
            //()
            bool operator_found = false;
            while (!s.empty() and s.top() != '(')
            {
                char top = s.top();
                if (top == '+' or top == '-' or top == '*' or top == '/')
                {
                    operator_found = true;
                }
                s.pop();
            }
            s.pop(); // for the opening bracket after the loop is over

            if (operator_found == false)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    khushi();
    string input = " (((a+b) + c))";
    if (isRedundant(input))
    {
        cout << "Contains Redundant Parenthesis!" << endl;
    }
    else
    {
        cout << "Doesn't contain Redundant Parenthesis" << endl;
    }
    return 0;
}