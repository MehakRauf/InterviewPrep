#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, char digit)
{
    // horizontal check
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == digit)
        {
            return false;
        }
    }

    // vertical check
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == digit)
        {
            return false;
        }
    }

    // check in the grid
    int srow = (row / 3) * 3, scol = (scol / 3) * 3;
    for (int i = srow; i <= srow + 2; i++)
    {
        for (int j = scol; j <= scol + 2; j++)
        {
            if (board[i][j] == digit)
            {
                return false;
            }
        }
    }
    return true;
}

bool helper(vector<vector<char>> &board, int row, int col)
{
    // base case as rows are from 0-8
    // we have reached the last row so means sudoku is solved
    if (row == 9)
    {
        return true;
    }

    // calculate next row and column
    int nextRow = row, nextCol = col + 1;

    // if on last column then change row
    if (nextCol == 9)
    {
        nextRow = row + 1;
        nextCol = 0;
    }

    // if there is already a digit check for next row and column
    if (board[row][col] != '.')
    {
        return helper(board, nextRow, nextCol);
    }

    // check for all digits
    for (char digit = '1'; digit <= '9'; digit++)
    {
        // see if it is safe
        if (isSafe(board, row, col, digit))
        {
            // place the digit if it is safe
            board[row][col] = digit;
            // go for next rows and cols
            if (helper(board, nextRow, nextCol))
            {
                return true;
            }
            // backtrack
            board[row][col] = '.';
        }
    }
    return false;
}

void sudokuSolver(vector<vector<char>> board)
{
    helper(board, 0, 0);
}

int main()
{
    return 0;
}