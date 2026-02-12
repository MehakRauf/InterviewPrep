#include <iostream>
#include <climits>
using namespace std;

int diagonalSum(int arr[][3], int rows, int cols)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (j == cols - 1 - i)
            {
                sum += arr[j][i];
            }
        }
    }
    return sum;
}
int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 15, 6}, {7, 8, 19}};
    int rows = 3, cols = 3;

    cout << diagonalSum(arr, rows, cols) << endl;
    return 0;
}