#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelfBrute(vector<int> nums)
{
    vector<int> ans(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++)
    {
        int product = 1;
        for (int j = 0; j < nums.size(); j++)
        {
            if (i != j)
            {
                product *= nums[j];
            }
        }
        ans[i] = product;
    }
    return ans;
}

vector<int> productExceptSelfOptimized(vector<int> nums)
{
    int n = nums.size();
    vector<int> ans(n, 1);
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);

    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < n; i++)
    {
        ans[i] = prefix[i] * suffix[i];
    }
    return ans;
}

vector<int> productExceptSelfSpaceOptimized(vector<int> nums)
{
    int n = nums.size();
    vector<int> ans(n, 1);
    vector<int> suffix(n, 1);
    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }
    for (int j = n - 2; j >= 0; j--)
    {
        suffix[j] = suffix[j + 1] * nums[j + 1];
        ans[j] *= suffix[j];
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = productExceptSelfSpaceOptimized(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}