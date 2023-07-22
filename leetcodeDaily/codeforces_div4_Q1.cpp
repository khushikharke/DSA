#include <iostream>
using namespace std;
// void khushi()
// {
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// }

int main()
{
    // khushi();
    int tc;
    cin >> tc;

    while (tc--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if ((a + b >= 10) || (a + c >= 10) || (b + c >= 10))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}