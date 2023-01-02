#include <iostream>
using namespace std;
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
void generateBrackets(string output, int n, int opening, int closing, int i)
{
    // base case
    if (i == 2 * n)
    {
        cout << output << endl;
        return;
    }
    // open
    if (opening < n)
    {
        generateBrackets(output + '(', n, opening + 1, closing, i + 1);
    }

    // close
    if (closing < opening)
    {
        generateBrackets(output + ')', n, opening, closing + 1, i + 1);
    }
}
int main()
{
    khushi();
    string output;
    int n;
    cin >> n;
    generateBrackets(output, n, 0, 0, 0);
    return 0;
}