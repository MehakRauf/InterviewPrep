#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int> arr, int tar)
{
    set<vector<int>> s;
    vector<vector<int>> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                if ((arr[i] + arr[j] + arr[k]) == tar)
                {
                    vector<int> values = {arr[i], arr[j], arr[k]};
                    sort(values.begin(), values.end());
                    if (s.find(values) == s.end())
                    {
                        s.insert(values);
                        ans.push_back(values);
                    }
                }
            }
        }
    }
    return ans;
}

vector<vector<int>> threeSumOptimized(vector<int> arr, int target)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        int j = i + 1, k = arr.size() - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < target)
            {
                j++;
            }
            else if (sum > target)
            {
                k--;
            }
            else
            {
                ans.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1])
                {
                    j++;
                }
                while (j < k && arr[k] == arr[k + 1])
                {
                    k--;
                }
            }
        }
    }
    return ans;
}

vector<vector<int>> threeSumOptimal(vector<int> arr, int target)
{

    set<vector<int>> uniqueTriplets;
    for (int i = 0; i < arr.size(); i++)
    {
        int first = -arr[i];
        set<int> s;
        for (int j = i + 1; j < arr.size(); j++)
        {
            int third = first - arr[j];
            if (s.find(third) != s.end())
            {
                vector<int> trips = {arr[i], arr[j], third};
                sort(trips.begin(), trips.end());
                uniqueTriplets.insert(trips);
            }
            s.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 0, 1, 0, 0, 0, 0};
    int target = 0;
    vector<vector<int>> ans = threeSumOptimized(arr, target);
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