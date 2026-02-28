#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int smallest = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[smallest])
            {
                smallest = j;
            }
        }
        swap(arr[i], arr[smallest]);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(vector<int> arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int gap = i - 1, currentVal = arr[i];
        while (gap > 0 && arr[gap] > currentVal)
        {
            arr[gap + 1] = arr[gap];
            gap--;
        }
        arr[gap + 1] = currentVal;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(vector<int> &arr, int l, int mid, int r)
{
    vector<int> temp;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r)
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
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= r)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int i = 0; i < temp.size(); i++)
    {
        arr[l + i] = temp[i];
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int partition(vector<int> &arr, int low, int high)
{
    int i = low - 1, pivot = arr[high];
    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main()
{

    vector<int> arr = {1, 13, 2, 4, 18, 93, 7};
    quickSort(arr, 0, arr.size() - 1);
    for (int val : arr)
    {
        cout << val << " ";
    }
    return 0;
}
