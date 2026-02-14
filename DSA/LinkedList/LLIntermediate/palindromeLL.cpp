#include <iostream>
#include <stack>
using namespace std;

struct linkedList
{
    int val;
    struct linkedList *next;
};
struct linkedList *start = NULL;

void addElement(int val)
{
    struct linkedList *temp = (struct linkedList *)malloc(sizeof(struct linkedList));
    temp->val = val;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
        return;
    }
    struct linkedList *curr = start;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
}

bool isPalindrome()
{
    stack<int> stack;
    struct linkedList *curr = start;
    while (curr != NULL)
    {
        stack.push(curr->val);
        curr = curr->next;
    }

    curr = start;
    while (curr != NULL)
    {
        int value = stack.top();
        stack.pop();
        if (curr->val != value)
        {
            return false;
        }
        curr = curr->next;
    }
    return true;
}

void printElements()
{
    struct linkedList *temp = start;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    addElement(2);
    addElement(4);
    addElement(5);
    addElement(8);
    addElement(5);
    addElement(41);
    addElement(2);
    printElements();
    cout << isPalindrome() << endl;
    return 0;
}