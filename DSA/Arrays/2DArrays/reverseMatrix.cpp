#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void reverseMatrix(vector<vector<int>> &matrix)
{
    vector<int> values;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            values.push_back(matrix[i][j]);
        }
    }

    reverse(values.begin(), values.end());

    int idx = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            matrix[i][j] = values[idx++];
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void reverseMatrixRows(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int j = 0, k = arr[i].size() - 1;
        while (j < k)
        {
            swap(arr[i][j], arr[i][k]);
            j++;
            k--;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void reverseMatrixColumns(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr[0].size(); i++)
    {
        int j = 0, k = arr.size() - 1;
        while (j < k)
        {
            swap(arr[j][i], arr[k][i]);
            j++;
            k--;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    reverseMatrixColumns(matrix);
    return 0;
}