#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<string> board, int row, int col, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == 'Q')
        {
            return false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    for (int i = row, j = col; j >= 0 && i >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j < n; j++, i--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}

void nQueens(vector<string> board, int row, int n, vector<vector<string>> &ans)
{
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, row, i, n))
        {
            board[row][i] = 'Q';
            nQueens(board, row + 1, n, ans);
            board[row][i] = '.';
        }
    }
}

void solveNQueens(int n)
{
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    nQueens(board, 0, n, ans);
    for (auto vec : ans)
    {
        for (auto val : vec)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    solveNQueens(4);
    return 0;
}