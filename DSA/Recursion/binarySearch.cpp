#include <iostream>

using namespace std;

int binarySearch(int arr[], int st, int end, int tar)
{

    if (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid] == tar)
        {
            return mid;
        }
        else if (arr[mid] < tar)
        {
            return binarySearch(arr, mid + 1, end, tar);
        }
        else if (arr[mid] > tar)
        {
            return binarySearch(arr, st, mid - 1, tar);
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << binarySearch(arr, 0, 4, 50) << endl;
    return 0;
}