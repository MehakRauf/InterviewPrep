#include <iostream>
#include <climits>
using namespace std;

int columnSum(int arr[][3], int rows, int cols)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < cols; i++)
    {
        int sum = 0;
        for (int j = 0; j < rows; j++)
        {
            sum += arr[j][i];
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}
int main()
{
    int arr[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    int rows = 4, cols = 3;

    cout << columnSum(arr, rows, cols) << endl;
    return 0;
}