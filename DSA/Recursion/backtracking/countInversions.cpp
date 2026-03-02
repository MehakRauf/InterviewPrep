#include <iostream>
#include <vector>

using namespace std;

// brute force approach
int countInversions(vector<int> arr)
{
    int countInv = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
            {
                countInv++;
            }
        }
    }
    return countInv;
}

int merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int invCount = 0, i = st, j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= end)
    {
        temp.push_back(arr[j++]);
    }

    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[st + idx] = temp[idx];
    }

    return invCount;
}

// optimal approach
int mergeSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        int leftInvCount = mergeSort(arr, st, mid);
        int rightInvCount = mergeSort(arr, mid + 1, end);
        int invCount = merge(arr, st, mid, end);

        return (leftInvCount + rightInvCount + invCount);
    }
    return 0;
}

int main()
{

    vector<int> arr = {6, 3, 5, 2, 7};
    // vector<int> arr = {1, 3, 5, 10, 2, 6, 8, 9};
    cout << mergeSort(arr, 0, arr.size() - 1) << endl;
    return 0;
}