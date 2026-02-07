#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int majorityElementBrute(vector<int> arr, int n)
{
    int ans;
    for (int i = 0; i < n; i++)
    {
        int freq = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                freq++;
            }
        }
        if (freq > n / 2)
        {
            return freq;
        }
    }
}

int majorityElementOptimal(vector<int> arr, int n)
{
    int freq = 1, ans = arr[0];
    sort(arr.begin(), arr.end());
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == arr[i - 1])
        {
            freq++;
        }
        else
        {
            freq = 1;
            ans = arr[i];
        }
        if (freq > n / 2)
        {
            return ans;
        }
    }
    return ans;
}

int majorityElementMoore(vector<int> arr, int n)
{
    int freq = 0, ans = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (freq == 0)
        {
            ans = arr[i];
        }
        if (ans == arr[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }

    int count = 0;
    for (int val : arr)
    {
        if (ans == val)
        {
            count++;
        }
    }
    if (count > n / 2)
    {
        return ans;
    }
    else
    {
        // if it doesnt exists n/2 times
        return -1;
    }
}

int main()
{
    vector<int> arr = {1, 2, 2, 1, 1, 1, 1, 3, 1, 2, 6, 5, 4};
    // cout << majorityElementBrute(arr, arr.size());
    // cout << majorityElementOptimal(arr, arr.size());
    cout << majorityElementMoore(arr, arr.size());
    return 0;
}