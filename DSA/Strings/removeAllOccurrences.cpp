#include <iostream>

using namespace std;

void removeAllOccurrences(string s, string part)
{
    while (s.length() > 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    cout << s << endl;
}
int main()
{
    string s = "daabcbaabcbc";
    string part = "abc";
    removeAllOccurrences(s, part);
}