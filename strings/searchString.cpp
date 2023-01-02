#include <iostream>
#include <string>
#include <vector>

using namespace std;
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
vector<int> Searchstr(string big, string small)
{
    vector<int> result;
    int index = big.find(small);
    while (index != -1)
    {
        result.push_back(index);
        index = big.find(small, index + 1);
    }
    return result;
}

int main(int argc, char const *argv[])
{
    khushi();
    string big = "geeks for geeks";
    string small = "geeks";
    Searchstr(big, small);
    return 0;
}
