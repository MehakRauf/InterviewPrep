#include <iostream>
#include <algorithm>

using namespace std;

string reverseWordsInString(string str)
{
    reverse(str.begin(), str.end());
    string ans;
    for (int i = 0; i < str.length(); i++)
    {
        string word;
        while (str[i] != ' ' && i < str.length())
        {
            word += str[i++];
        }
        reverse(word.begin(), word.end());
        if (word.length() > 0)
        {
            if (!ans.empty())
            {
                ans += " ";
            }
            ans += word;
        }
    }
    return ans;
}

int main()
{
    string str = "  hello world  ";
    cout << reverseWordsInString(str) << endl;
    cout << reverseWordsInString("Khadija") << endl;

    return 0;
}