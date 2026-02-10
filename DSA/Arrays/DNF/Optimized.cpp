#include <iostream>
#include <vector>
using namespace std;

void sortArray(vector<int> &arr)
{
    int zeroes = 0, ones = 0, twos = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            zeroes++;
        }
        else if (arr[i] == 1)
        {
            ones++;
        }
        else
        {
            twos++;
        }
    }

    int idx = 0;
    for (int i = 0; i < zeroes; i++)
    {
        arr[idx++] = 0;
    }
    for (int j = 0; j < ones; j++)
    {
        arr[idx++] = 1;
    }
    for (int k = 0; k < twos; k++)
    {
        arr[idx++] = 2;
    }
}

int main()
{
    vector<int> arr = {1, 2, 0, 2, 1, 0, 1};
    sortArray(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}