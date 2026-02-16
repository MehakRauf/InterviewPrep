#include <iostream>
#include <vector>
using namespace std;

vector<int> nthRow(int nRow)
{
    vector<vector<int>> triangle;
    for (int i = 0; i <= nRow; i++)
    {
        vector<int> row(i + 1, 1);
        for (int j = 1; j < i; j++)
        {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);
    }
    return triangle[nRow];
}

int main()
{
    vector<int> ans = nthRow(3);
    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}