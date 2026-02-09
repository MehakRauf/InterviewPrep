#include <iostream>
#include <vector>
using namespace std;

int uniqueElementXOR(vector<int> arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans ^= arr[i];
    }
    return ans;
}

int uniqueElement(vector<int> arr)
{
    int n = arr.size();
    if (n == 1)
    {
        return arr[0];
    }
    int st = 0, end = n - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (mid == 0 && arr[mid] != arr[1])
        {
            return arr[mid];
        }
        if (mid == n - 1 && arr[n - 1] != arr[n - 2])
        {
            return arr[mid];
        }
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }
        if (mid % 2 == 0)
        {
            if (arr[mid] == arr[mid - 1])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else
        {
            if (arr[mid] == arr[mid - 1])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    // vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 6};
    // cout << uniqueElementXOR(arr) << endl;
    cout << uniqueElement(arr) << endl;
    return 0;
}