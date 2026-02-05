#include <iostream>
#include <climits>
using namespace std;

int minValue(int arr[], int n)
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int maxValue(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int secondMaxValue(int arr[], int n)
{
    int max = INT_MIN, secondMax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            secondMax = max;
            max = arr[i];
        }
        else if (arr[i] > secondMax && arr[i] != max)
        {
            secondMax = arr[i];
        }
    }
    return secondMax;
}

void minMaxBuiltinFunc(int arr[], int n)
{
    int smallest = INT_MAX, largest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        smallest = min(smallest, arr[i]);
        largest = max(largest, arr[i]);
    }
    cout << "Smallest = " << smallest << " largest = " << largest << endl;
}

int minIndex(int arr[], int n)
{
    int smallest = INT_MAX, smallestIdx;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
            smallestIdx = i;
        }
    }
    return smallestIdx;
}

int maxIdx(int arr[], int n)
{
    int largest = INT_MIN, largestIdx;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
            largestIdx = i;
        }
    }
    return largestIdx;
}

int main()
{
    int arr[] = {4, 4, 13, 17, 16, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << minValue(arr, size) << endl;
    cout << maxValue(arr, size) << endl;
    cout << secondMaxValue(arr, size) << endl;
    cout << minIndex(arr, size) << endl;
    cout << maxIdx(arr, size) << endl;
    minMaxBuiltinFunc(arr, size);
    return 0;
}