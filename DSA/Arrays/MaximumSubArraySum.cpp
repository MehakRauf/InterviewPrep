#include <iostream>
#include <climits>
using namespace std;

void printSubArray(int arr[], int n)
{
    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            for (int i = start; i <= end; i++)
            {
                cout << arr[i];
            }
            cout << " ";
        }
        cout << endl;
    }
}

int maxSubArraySum(int arr[], int size)
{
    int maxSum = INT_MIN;
    for (int start = 0; start < size; start++)
    {
        int currentSum = 0;
        for (int end = start; end < size; end++)
        {
            currentSum += arr[end];
            maxSum = max(currentSum, maxSum);
        }
    }
    return maxSum;
}

int maxSubArrayKadane(int arr[], int size)
{
    int maxSum = INT_MIN, currentSum = 0;
    for (int i = 0; i < size; i++)
    {
        currentSum += arr[i];
        maxSum = max(currentSum, maxSum);
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }
    return maxSum;
}

int main()
{
    int arr[] = {2, 3, -2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    printSubArray(arr, size);
    cout << maxSubArraySum(arr, size) << endl;
    cout << maxSubArrayKadane(arr, size) << endl;
    return 0;
}