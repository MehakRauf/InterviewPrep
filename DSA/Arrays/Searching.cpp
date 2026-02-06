#include <iostream>
using namespace std;

// timeComplexity = O(n)
int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

// timeComplexity = O(log n)
int binarySearch(int arr[], int n, int target)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {3, 5, 2, 6, 8};
    // int target = 8, size = sizeof(arr) / sizeof(arr[0]), result = linearSearch(arr, size, target);
    int target = 0, size = sizeof(arr) / sizeof(arr[0]), result = binarySearch(arr, size, target);
    if (result == -1)
    {
        cout << "Element not found." << endl;
    }
    else
    {
        cout << "Element is found at: " << result << endl;
    }
    return 0;
}