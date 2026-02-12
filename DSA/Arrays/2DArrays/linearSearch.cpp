#include <iostream>
using namespace std;

bool linearSearch(int arr[][3], int target, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

pair<int, int> linearSrch(int arr[][3], int target, int rows, int cols)
{
    pair<int, int> values = {-1, -1};
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == target)
            {
                values = {i, j};
                return values;
            }
        }
    }
    return values;
}
int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = 3, cols = 3;
    pair<int, int> ans = linearSrch(arr, 6, rows, cols);
    cout << ans.first << " " << ans.second << endl;

    return 0;
}