#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool binarySearch(vector<vector<int>> mat, int target, int row)
{
    int st = 0, end = mat[0].size() - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (mat[row][mid] == target)
        {
            return true;
        }
        if (mat[row][mid] < target)
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
}
bool seacrhElement(vector<vector<int>> mat, int target)
{
    int m = mat.size(), n = mat[0].size();
    int st = 0, end = m - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (target >= mat[mid][0] && target <= mat[mid][n - 1])
        {
            return binarySearch(mat, target, mid);
        }
        if (target <= mat[mid][n - 1])
        {
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = 3;
    int cols = 3;
    cout << seacrhElement(matrix, 1) << endl;
    return 0;
}