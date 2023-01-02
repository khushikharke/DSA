#include <iostream>
using namespace std;
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int countWays(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }

    return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
}
int main()
{
    khushi();
    int n;
    cin >> n;
    cout << countWays(n) << endl;
    return 0;
}