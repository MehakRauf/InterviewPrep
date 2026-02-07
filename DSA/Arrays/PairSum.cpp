#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSumBrute(vector<int> arr, int tar)
{
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == tar)
            {
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
                return ans;
            }
        }
    }
}

vector<int> pairSumOptimal(vector<int> arr, int tar)
{
    int l = 0, r = arr.size() - 1;
    vector<int> ans;
    while (l < r)
    {
        if ((arr[l] + arr[r]) == tar)
        {
            ans.push_back(arr[l]);
            ans.push_back(arr[r]);
            return ans;
        }else if((arr[l] + arr[r]) < tar){
            l++;
        }else{
            r--;
        }
    }
}
int main()
{
    vector<int> arr = {2, 7, 11, 15};
    // vector<int> ans = pairSumBrute(arr, 9);
    // cout << ans[0] << ", " << ans[1] << endl;
    vector<int> ans = pairSumOptimal(arr, 13);
    cout << ans[0] << ", " << ans[1] << endl;
    return 0;
}