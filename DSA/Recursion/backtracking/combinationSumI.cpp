#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<vector<int>> s;

void generateCombinations(vector<int> candidates, int i, int target, vector<int> &combin, vector<vector<int>> &ans)
{
    // base cases
    if (i == candidates.size() || target < 0)
    {
        return;
    }

    // means reached the required value
    if (target == 0)
    {
        if (s.find(combin) == s.end())
        {
            ans.push_back(combin);
            s.insert(combin);
        }
    }

    // include once
    combin.push_back(candidates[i]);
    generateCombinations(candidates, i + 1, target - candidates[i], combin, ans);
    // include multiple times
    generateCombinations(candidates, i, target - candidates[i], combin, ans);
    // exclusion 
    combin.pop_back();
    generateCombinations(candidates, i + 1, target, combin, ans);
}

vector<vector<int>> combinationSum(vector<int> candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> combin;

    generateCombinations(candidates, 0, target, combin, ans);
    return ans;
}

int main()
{
    vector<int> candidates = {2, 3, 5};
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