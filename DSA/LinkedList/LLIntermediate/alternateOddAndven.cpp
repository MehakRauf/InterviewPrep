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

void alternateOddAndEven()
{
    stack<linkedList *> odd;
    stack<linkedList *> even;
    linkedList *curr = start;
    int i = 1;
    while (curr != NULL)
    {
        if (curr->val % 2 == 0 && i % 2 != 0)
        {
            even.push(curr);
        }
        else if (curr->val % 2 != 0 && i % 2 == 0)
        {
            odd.push(curr);
        }
        curr = curr->next;
        i++;
    }

    while (!odd.empty() & !even.empty())
    {
        swap(odd.top()->val, even.top()->val);
        odd.pop();
        even.pop();
    }
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
    // Input: 11 -> 20 -> 40 -> 55 -> 77 -> 80
    // Output: 11 -> 20 -> 55 -> 40 -> 77 -> 80
    addElement(11);
    addElement(20);
    addElement(40);
    addElement(55);
    addElement(77);
    addElement(80);
    printElements();
    alternateOddAndEven();
    printElements();
    return 0;
}