#include <iostream>
#include <vector>

using namespace std;

void permutations(vector<int> &nums, int idx)
{
    if (idx == nums.size())
    {
        for (int i = 0; i < idx; i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[i], nums[idx]);
        permutations(nums, idx + 1);
        swap(nums[i], nums[idx]);
    }
}

void stringPermutations(string str, int idx)
{
    if (idx == str.length())
    {
        for (int i = 0; i < idx; i++)
        {
            cout << str[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = idx; i < str.length(); i++)
    {
        swap(str[i], str[idx]);
        stringPermutations(str, idx + 1);
        swap(str[i], str[idx]);
    }
}

int main()
{
    vector<int> arr = {1, 2, 3};
    stringPermutations("Hel", 0);
    return 0;
}