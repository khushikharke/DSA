#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
int main()
{
    string input;
    getline(cin, input);

    stringstream ss(input);

    string token;
    vector<string> tokens;
    while (getline(ss, token, ' '))
    {
        tokens.push_back(token);
    }
    for (auto token : tokens)
    {
        cout << token << ",";
    }
    return 0;
}