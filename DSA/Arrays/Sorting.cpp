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
int main()
{
    vector<int> arr = {1, 3, 2, 4, 8, 3, 7};
    insertionSort(arr);
    return 0;
}