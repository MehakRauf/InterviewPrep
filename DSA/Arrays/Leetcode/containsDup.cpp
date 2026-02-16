#include <iostream>
#include <unordered_set>

#include <vector>

using namespace std;

bool containsDuplicate(vector<int> nums)
{
    unordered_set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        if (s.find(nums[i]) != s.end())
        {
            return true;
        }
        s.insert(nums[i]);
    }
    return false;
}

int main()
{
    cout << containsDuplicate({1, 2, 3, 2}) << endl;
    return 0;
}