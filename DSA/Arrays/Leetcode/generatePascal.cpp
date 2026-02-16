#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generatePascal(int nRows)
{
    vector<vector<int>> triangle;
    for (int i = 0; i < nRows; i++)
    {
        vector<int> rows(i + 1, 1);
        for (int j = 1; j < i; j++)
        {
            rows[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(rows);
    }
    return triangle;
}

int main()
{
    vector<vector<int>> ans = generatePascal(3);
    for (auto vec : ans)
    {
        for (auto val : vec)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}