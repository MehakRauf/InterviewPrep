#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void generateCombinations(vector<int> candidates, int i, int target, vector<int> &combin, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(combin);
        return;
    }

    for (int j = i; j < candidates.size(); j++)
    {
        // skip duplicates
        if (j > i && candidates[j] == candidates[j - 1])
            continue;

        if (candidates[i] > target)
            break;

        combin.push_back(candidates[j]);
        generateCombinations(candidates, j + 1, target - candidates[j], combin, ans);
        combin.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> combin;
    sort(candidates.begin(), candidates.end());
    generateCombinations(candidates, 0, target, combin, ans);
    return ans;
}

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> ans = combinationSum(candidates, target);

    for (auto values : ans)
    {
        for (auto val : values)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}