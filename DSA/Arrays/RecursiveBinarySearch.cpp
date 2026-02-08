#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int tar, int left, int right)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == tar)
        {
            return mid;
        }
        if (arr[mid] < tar)
        {
            return binarySearch(arr, tar, mid + 1, right);
        }
        else
        {
            return binarySearch(arr, tar, left, mid - 1);
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    cout << binarySearch(arr, 4, 0, 3) << endl;
    return 0;
}