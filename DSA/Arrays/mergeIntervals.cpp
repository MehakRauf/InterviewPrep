#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> arr)
{
    vector<vector<int>> ans;
    if (arr.size() == 0)
    {
        return ans;
    }
    sort(arr.begin(), arr.end());
    ans.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i][0] <= ans.back()[1])
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
        else
        {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 20}};
    vector<vector<int>> ans = mergeIntervals(intervals);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}