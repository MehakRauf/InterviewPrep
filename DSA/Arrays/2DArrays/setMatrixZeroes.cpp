#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void setZeroes(vector<vector<int>> &arr)
{
    bool col0 = false, row0 = false;
    int m = arr.size(), n = arr[0].size();
    for (int i = 0; i < n; i++)
    {
        if (arr[0][i] == 0)
        {
            row0 = true;
            break;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (arr[0][i] == 0)
        {
            col0 = true;
            break;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][0] = 0;
                arr[0][j] = 0;
            }
        }
    }
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 1; j--)
        {
            if (arr[i][0] == 0 || arr[0][j] == 0)
            {
                arr[i][j] = 0;
            }
        }
    }

    if (row0)
    {
        for (int i = 0; i < n; i++)
        {
            arr[0][i] = 0;
        }
    }
    if (col0)
    {
        for (int i = 0; i < m; i++)
        {
            arr[i][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    int rows = matrix.size();
    int cols = matrix[0].size();
    setZeroes(matrix);

    cout << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}