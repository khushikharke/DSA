#include <iostream>
// for higher i/p this code will not run the complexity is huge
// max upto 13 maybe
using namespace std;
void khushi()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
void printBoard(int n, int board[20][20])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool canPlace(int board[][20], int n, int x, int y)
{
    // col
    for (int k = 0; k < x; k++)
    {
        if (board[k][y] == 1)
        {
            return false;
        }
    }
    // left diag
    int i = x;
    int j = y;
    while (i >= 0 and j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }

    // right diagonal
    i = x;
    j = y;
    while (i >= 0 and j < n)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j++;
    }
    return true;
}

bool solveNQueen(int n, int board[][20], int i)
{
    // base case
    // i->row,j->column
    if (i == n)
    {
        // print board
        printBoard(n, board);
        return true;
    }

    // rec case '
    // try to place a queen in every row if not possible in all posibilities backtrack and resolve the problem
    for (int j = 0; j < n; j++)
    {
        // whether curr [i][j] is safe or not
        if (canPlace(board, n, i, j))
        {
            board[i][j] = 1;
            bool success = solveNQueen(n, board, i + 1);
            // if curr grid gets success from rem grid then only true is ret
            if (success)
            {
                return true;
            }
            // backtrack
            // update and remove
            board[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    khushi();
    int board[20][20] = {0};
    int n;
    cin >> n;
    solveNQueen(n, board, 0);

    return 0;
}