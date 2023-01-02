#include <iostream>
#include <cstring>
#include <vector>
// include <>

using namespace std;
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
int main()
{
    khushi();
    char input[10000];
    cin.getline(input, 10000);
    char *token = strtok(input, " ");
    while (token != NULL)
    {
        cout << token << endl;
        token = strtok(NULL, " ");
    }

    return 0;
}