#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> repeatedAndMissing(vector<vector<int>> grid)
{
    vector<int> ans;
    unordered_set<int> s;
    int expectedSum = 0, actualSum = 0, a, b, n = grid.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            actualSum += grid[i][j];
            if (s.find(grid[i][j]) != s.end())
            {
                a = grid[i][j]; // repeated element;
                ans.push_back(a);
            }
            s.insert(grid[i][j]);
        }
    }
    expectedSum = (n * n) * (n * n + 1) / 2;
    b = expectedSum + a - actualSum;
    ans.push_back(b);
    return ans;
}
int main()
{
    vector<vector<int>> grid = {{1, 3}, {2, 2}};
    vector<int> ans = repeatedAndMissing(grid);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}