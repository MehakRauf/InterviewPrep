#include <iostream>
#include <algorithm>
using namespace std;

bool isFreqSame(int arr1[], int arr2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}
bool permutationInString(string s1, string s2)
{
    int freq[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        freq[s1[i] - 'a']++;
    }

    int windowSize = s1.length();
    for (int i = 0; i < s2.length(); i++)
    {
        int idx = i, windowLength = 0;
        int windowFreq[26] = {0};
        while (windowLength < windowSize && idx < s2.length())
        {
            windowFreq[s2[idx] - 'a']++;
            idx++;
            windowLength++;
        }
        if (isFreqSame(freq, windowFreq))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    string s1 = "ab", s2 = "eidboaoo";
    cout << permutationInString(s1, s2) << endl;
    return 0;
}