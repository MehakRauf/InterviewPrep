#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> bruteForce(vector<int> arr, int tar)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int first = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
        {
            if ((first + arr[j]) == tar)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

vector<int> optimized(vector<int> arr, int tar)
{
    sort(arr.begin(), arr.end());
    int st = 0, end = arr.size() - 1;
    while (st <= end)
    {
        if (arr[st] + arr[end] == tar)
        {
            return {st, end};
        }
        if (arr[st] + arr[end] < tar)
        {
            st++;
        }
        else
        {
            end--;
        }
    }
    return {-1, -1};
}

vector<int> twoSum(vector<int> arr, int tar)
{
    unordered_map<int, int> m;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        int first = arr[i];
        int second = tar - first;
        if (m.find(second) != m.end())
        {
            ans.push_back(i);
            ans.push_back(m[second]);
            return ans;
        }
        m[first] = i;
    }
    return {-1, -1};
}

int main()
{
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twoSum(arr, target);
    // vector<int> ans = bruteForce(arr, target);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}