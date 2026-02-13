#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int subArraySumEqualsK(vector<int> arr, int k)
{
    int count = 0, prefixSum = 0;
    unordered_map<int, int> map;
    map[0] = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        prefixSum += arr[i];
        int remove = prefixSum - k;
        count += map[remove];
        map[prefixSum] += 1;
    }
    return count;
}

int bruteForce(vector<int> arr, int k)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<int> arr = {9, 4, 20, 3, 10, 5};
    int k = 33;
    cout << subArraySumEqualsK(arr, k) << endl;
    cout << bruteForce(arr, k) << endl;
    return 0;
}