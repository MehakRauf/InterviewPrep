#include <iostream>
#include <list>

using namespace std;

class Stack
{
    list<int> st;

public:
    void pop() // O(1)
    {
        st.pop_front();
    }

    void push(int val) // O(1)
    {
        st.push_front(val);
    }

    int top() // O(1)
    {
        return st.front();
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