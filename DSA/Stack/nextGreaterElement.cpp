#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int> nums)
{
    vector<int> nextGreater(nums.size(), -1);
    stack<int> s;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (s.size() > 0 && s.top() <= nums[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            nextGreater[i] = -1;
        }
        else
        {
            nextGreater[i] = s.top();
        }
        s.push(nums[i]);
    }
    return nextGreater;
}

int main()
{
    vector<int> nums = {6, 8, 0, 1, 3};
    vector<int> ans = nextGreaterElement(nums);
    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}