#include <iostream>
#include <vector>
using namespace std;

void mergeArrays(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    int idx = n + m - 1;
    int i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0)
    {
        if (arr2[j] >= arr1[i])
        {
            arr1[idx] = arr2[j];
            j--;
            idx--;
        }
        else
        {
            arr1[idx] = arr1[i];
            i--;
            idx--;
        }
    }
    while (j >= 0)
    {
        arr1[idx] = arr2[j];
        idx--;
        j--;
    }
}
int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 0, 0, 0};
    vector<int> arr2 = {5, 6, 7};
    // just send the ;ength of no zeroes in arr1
    mergeArrays(arr1, arr2, 4, arr2.size());
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    return 0;
}