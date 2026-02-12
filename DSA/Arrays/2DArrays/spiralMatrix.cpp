#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>> arr)
{
    int srow = 0, scol = 0, erow = arr.size() - 1, ecol = arr[0].size() - 1;
    vector<int> ans;
    while (srow <= erow && scol <= ecol)
    {
        // top
        for (int i = scol; i <= ecol; i++)
        {
            ans.push_back(arr[srow][i]);
        }
        // right
        for (int i = srow + 1; i <= erow; i++)
        {
            ans.push_back(arr[i][ecol]);
        }
        // bottom
        for (int i = ecol - 1; i >= scol; i--)
        {
            if (srow == erow)
            {
                break;
            }
            ans.push_back(arr[erow][i]);
        }
        // left
        for (int i = erow - 1; i >= srow + 1; i--)
        {
            if (scol == ecol)
            {
                break;
            }
            ans.push_back(arr[i][scol]);
        }
        srow++;
        scol++;
        erow--;
        ecol--;
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = 3;
    int cols = 3;
    vector<int> ans;
    ans = spiralMatrix(matrix);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}