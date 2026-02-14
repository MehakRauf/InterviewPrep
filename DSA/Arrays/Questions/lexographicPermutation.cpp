#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void lexographicPermutation(vector<int> &arr)
{
    int pivot = -1, n = arr.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            pivot = i;
            break;
        }
    }
    if (pivot == -1)
    {
        reverse(arr.begin(), arr.end());
        return;
    }

    for (int i = n - 1; i > pivot; i--)
    {
        if (arr[i] > arr[pivot])
        {
            swap(arr[i], arr[pivot]);
            break;
        }
    }
    int i = pivot + 1, j = n - 1;
    while (i <= j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 5, 4};
    lexographicPermutation(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 9;
}