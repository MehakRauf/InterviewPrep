#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool seacrhElement(vector<vector<int>> mat, int target)
{
    int m = mat.size(), n = mat[0].size();
    int r = 0, c = n - 1;
    while (r < m && c >= 0)
    {
        if (mat[r][c] == target)
        {
            return true;
        }
        else if (mat[r][c] < target)
        {
            r++;
        }
        else
        {
            c--;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = 3;
    int cols = 3;
    cout << seacrhElement(matrix, 10) << endl;
    return 0;
}