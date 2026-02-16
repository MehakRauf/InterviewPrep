#include <iostream>
#include <vector>

using namespace std;

void SubStrings(vector<int> &arr, vector<int> &ans, int idx, vector<vector<int>> &allSubStrings)
{
    if (idx == arr.size())
    {
        allSubStrings.push_back(ans);
        return;
    }
    ans.push_back(arr[idx]);
    SubStrings(arr, ans, idx + 1, allSubStrings);
    ans.pop_back();
    SubStrings(arr, ans, idx + 1, allSubStrings);
}

vector<vector<int>> storeSubstrings(vector<int> arr)
{
    int idx = 0;
    vector<int> ans;
    vector<vector<int>> allSubStrings;

    SubStrings(arr, ans, idx, allSubStrings);
    return allSubStrings;
}
int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans = storeSubstrings(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}