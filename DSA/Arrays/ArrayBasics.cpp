#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<int> sumProduct(int arr[], int size)
{
    vector<int> result;
    int sum = 0, product = 1;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        product *= arr[i];
    }
    result.push_back(sum);
    result.push_back(product);
    return result;
}

void swapMinMax(int arr[], int n)
{
    int smallestIdx, largestIdx, smallest = INT_MAX, largest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
            smallestIdx = i;
        }
        if (arr[i] > largest)
        {
            largest = arr[i];
            largestIdx = i;
        }
    }
    swap(arr[smallestIdx], arr[largestIdx]);

    cout << "The array after swaping the min and max values" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void uniqueNumbers(int arr[], int n)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    for (auto val : freq)
    {
        if (val.second == 1)
        {
            cout << val.first << " ";
        }
    }
    cout << endl;
}

// only if there is only one unique number in the array {1,2,3,1,2,4,4} - 3 is only unique
void uniqueNumberXOR(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans ^= arr[i];
    }
    cout << ans << endl;
}

void arrayIntersection(int arr1[], int arr2[], int n1, int n2)
{
    unordered_set<int> set1(arr1, arr1 + n1);
    unordered_set<int> result;

    for (int i = 0; i < n2; i++)
    {
        if (set1.find(arr2[i]) != set1.end())
        {
            result.insert(arr2[i]);
        }
    }

    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> result = sumProduct(arr, size);
    cout << "The sum is: " << result[0] << endl;
    cout << "The product is: " << result[1] << endl;
    swapMinMax(arr, size);
    uniqueNumbers(arr, size);
    int arr1[] = {1, 2, 2, 3, 1, 7, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    uniqueNumberXOR(arr1, size1);

    int arr2[] = {1, 4, 3, 5, 7, 8, 9, 0};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    arrayIntersection(arr1, arr2, size1, size2);
    return 0;
}