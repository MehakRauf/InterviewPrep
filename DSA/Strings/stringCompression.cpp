#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void stringCompression(vector<char> &chars)
{
    int idx = 0;
    for (int i = 0; i < chars.size(); i++)
    {
        char ch = chars[i];
        int count = 0;
        while (i < chars.size() && ch == chars[i])
        {
            count++;
            i++;
        }
        if (count == 1)
        {
            chars[idx++] = ch;
        }
        else
        {
            chars[idx++] = ch;
            string toStr = to_string(count);
            for (int i = 0; i < toStr.length(); i++)
            {
                chars[idx++] = toStr[i];
            }
        }
        i--;
    }
    chars.resize(idx);
}

int main()
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    stringCompression(chars);
    for (char ch : chars)
    {
        cout << ch << " ";
    }
    cout << endl;
    return 0;
}