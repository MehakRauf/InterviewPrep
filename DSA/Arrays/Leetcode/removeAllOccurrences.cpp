#include <iostream>
#include <vector>

using namespace std;

int removeAllOccurrences(vector<int> arr, int val)
{
    int slow = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != val)
        {
            arr[slow++] = arr[i];
        }
    }
    return slow;
}

int main()
{
    cout << removeAllOccurrences({3, 2, 2, 3, 2, 4, 5}, 3) << endl;
    return 0;
}