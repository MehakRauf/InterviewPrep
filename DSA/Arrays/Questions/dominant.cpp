#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int dominantIndex(vector<int> nums)
{
    int largest = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > nums[largest])
        {
            largest = i;
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == largest)
            continue;

        if (nums[i] * 2 > nums[largest])
        {
            return -1;
        }
    }
    return largest;
}

int main()
{
    cout << dominantIndex({0, 0, 1, 2});
    return 0;
}