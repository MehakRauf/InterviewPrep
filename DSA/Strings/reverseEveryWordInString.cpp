#include <iostream>
#include <algorithm>

using namespace std;

string reverseEveryWordInString(string str)
{
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
            ans += " " + word;
        }
    }
    return ans;
}

int main()
{
    string str = "  hello world  ";
    cout << reverseEveryWordInString(str) << endl;
    cout << reverseEveryWordInString("Khadija") << endl;

    return 0;
}