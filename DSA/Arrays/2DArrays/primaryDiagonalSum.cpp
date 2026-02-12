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
            if (i == j)
            {
                sum += arr[j][i];
            }
        }
    }
    return sum;
}
int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = 3, cols = 3;

    cout << diagonalSum(arr, rows, cols) << endl;
    return 0;
}