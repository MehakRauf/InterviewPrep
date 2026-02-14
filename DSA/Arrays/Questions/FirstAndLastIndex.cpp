// Give the first and last address of the target in an array.
// If the target doesn't exist in the array, return [-1,1]
// For example: Target = 8 Array = [1,3,5,8,4,2,8,9,0] Result = 3,6

#include <iostream>
#include <vector>
using namespace std;

// if the array is already sorted
vector<int> firstAndLastIndex(vector<int> arr, int tar)
{
    int first = 0, last = arr.size() - 1;
    vector<int> ans = {-1, -1};
    while (first <= last)
    {
        int mid = first + (last - first) / 2;
        if (arr[mid] == tar)
        {
            ans[0] = mid;
            last = mid - 1;
        }
        else if (arr[mid] < tar)
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }

    first = 0, last = arr.size();
    while (first <= last)
    {
        int mid = first + (last - first) / 2;
        if (arr[mid] == tar)
        {
            ans[1] = mid;
            first = mid + 1;
        }
        else if (arr[mid] < tar)
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }
    return ans;
}

vector<int> returnIndices(int arr[], int target, int size)
{
    vector<int> ans = {-1, -1};
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            if (ans[0] == -1)
            {
                ans[0] = i;
            }
            ans[1] = i;
        }
    }
    return ans;
}

int main()
{

    int arr[] = {1, 3, 5, 8, 4, 2, 8, 9, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 8;
    vector<int> ans = returnIndices(arr, target, size);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}