#include <iostream>
#include <climits>
using namespace std;

int diagonalSum(int arr[][3], int rows, int cols)
{
    int sum = 0, primaryDiagonal = 0, secondaryDiagonal = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (j == cols - 1 - i)
            {
                secondaryDiagonal += arr[j][i];
            }
            else if (i == j)
            {
                primaryDiagonal += arr[i][j];
            }
        }
    }
    sum = primaryDiagonal + secondaryDiagonal;
    return sum;
}

int diagonalSumOptimized(int arr[][3], int rows, int cols)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        sum += arr[i][i];
        if (i != rows - i - 1) // to prevent double addition of middle element
        {
            sum += arr[i][rows - i - 1];
        }
    }
    return sum;
}
int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 15, 6}, {7, 8, 19}};
    int rows = 3, cols = 3;

    cout << diagonalSumOptimized(arr, rows, cols) << endl;
    return 0;
}