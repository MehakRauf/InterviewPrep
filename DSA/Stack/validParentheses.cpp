#include <iostream>
#include <stack>

using namespace std;

bool validParentheses(string str)
{
    stack<char> ch;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            ch.push(str[i]);
        }
        else
        {
            if (ch.empty())
                return false;
            else
            {
                char c = ch.top();
                ch.pop();
                if ((c == '(' && str[i] != ')') && (c == '[' && str[i] != ']') && (c == '{' && str[i] != '}'))
                {
                    return false;
                }
            }
        }
    }
    return ch.empty();
}

int main()
{

    cout << validParentheses("{()") << endl;
    return 0;
}