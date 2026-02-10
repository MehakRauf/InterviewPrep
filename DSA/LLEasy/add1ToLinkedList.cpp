#include <iostream>
using namespace std;

// Input: head: 4 -> 5 -> 6
// Output: head: 4 -> 5 -> 7
// Explanation: Adding 1 to number represented by Linked List = 456 + 1 = 457

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
void reverseLL()
{
    if (start == NULL)
        return;
    struct linkedList *prev = NULL, *curr = start, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    start = prev;
}

void add1ToLL()
{
    reverseLL();
    int carry = 1, sum = 0;
    struct linkedList *curr = start;
    while (curr != NULL && carry != 0)
    {
        sum = curr->val + carry;
        curr->val = sum % 10;
        carry = sum / 10;

        if (curr->next == NULL && carry > 1)
        {
            addElement(carry);
            carry = 0;
        }
        curr = curr->next;
    }
    reverseLL();
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
    addElement(4);
    addElement(5);
    addElement(6);
    printElements();
    add1ToLL();
    printElements();
    return 0;
}