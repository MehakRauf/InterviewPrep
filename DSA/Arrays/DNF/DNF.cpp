#include <iostream>
#include <vector>

using namespace std;

void dnfSort(vector<int> &arr)
{
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            mid++;
            low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[high], arr[mid]);
            high--;
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 0, 2, 1, 0, 1};
    dnfSort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}