#include <iostream>
#include <cstring>
using namespace std;
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
void replace(char *str)
{
    int spaces = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
            spaces += 1;
    }

    int idx = strlen(str) + 2 * spaces;
    str[idx] = '\0';

    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            str[idx - 1] = '0';
            str[idx - 2] = '2';
            str[idx - 3] = '%';
            idx = idx - 3;
        }
        else
        {
            str[idx - 1] = str[i];
            idx--;
        }
    }
}
int main()
{
    khushi();
    char input[10000];
    cin.getline(input, 1000);
    replace(input);
    cout << input << endl;
    return 0;
}