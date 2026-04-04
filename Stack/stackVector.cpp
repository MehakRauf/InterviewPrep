#include <iostream>
#include <vector>

using namespace std;

class Stack
{
    vector<int> st;

public:
    void pop() // O(1)
    {
        st.pop_back();
    }

    void push(int val) // O(1)
    {
        st.push_back(val);
    }

    int top() // O(1)
    {
        int size = st.size();
        return st[size - 1];
    }

    bool isEmpty()
    {
        return (st.size() == 0);
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.isEmpty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl; // 30 20 10
    return 0;
}