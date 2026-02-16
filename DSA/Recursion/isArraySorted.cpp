#include <iostream>

using namespace std;

bool isSorted(int arr[], int n)
{
    if (n == 1)
    {
        return true;
    }
    return (isSorted(arr, n - 1) && arr[n - 1] > arr[n - 2]);
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    cout << isSorted(arr, 5) << endl;
    return 0;
}