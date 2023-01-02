#include <iostream>
using namespace std;
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
void printkeyPadOutput(string input, string output, int i = 0)
{
    // base case
    if (input[i] == '\0')
    {
        cout << output << endl;
        return;
    }
    // rec case
    int curr = input[i] - '0'; // int milega
    if (curr == 0 or curr == 1)
    {
        printkeyPadOutput(input, output, i + 1);
    }
    // keypad
    // iterating over the keypad[curr]
    for (int k = 0; k < keypad[curr].size(); k++)
    {
        printkeyPadOutput(input, output + keypad[curr][k], i + 1);
    }
    return;
}
int main()
{
    khushi();
    string input;
    cin >> input;

    string output;
    printkeyPadOutput(input, output);
    return 0;
}