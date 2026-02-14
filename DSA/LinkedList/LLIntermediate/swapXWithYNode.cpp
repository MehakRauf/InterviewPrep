#include <iostream>
#include <unordered_set>
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

void swapNodes(int x, int y)
{
    // if both are same no need to swap
    if (x == y)
        return;
    linkedList *currX, *prevX, *currY, *prevY, *curr = start, *prev = NULL;

    // find the node x
    while (curr != NULL)
    {
        if (curr->val == x)
        {
            prevX = prev;
            currX = curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    curr = start;

    // find the node y
    while (curr != NULL)
    {
        if (curr->val == y)
        {
            prevY = prev;
            currY = curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    // either is null so can't swap simple!!!
    if (currX == NULL || currY == NULL)
    {
        return;
    }

    // when x is not head
    if (prevX != NULL)
    {
        prevX->next = currY;
    }
    else
    {
        start = currY;
    }

    // when y is not head
    if (prevY != NULL)
    {
        prevY->next = currX;
    }
    else
    {
        start = currX;
    }

    // correct the pointers by swapping them
    linkedList *temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;
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
    addElement(12);
    addElement(2);
    addElement(5);
    addElement(8);
    addElement(4);
    addElement(-3);
    addElement(25);
    printElements();
    swapNodes(-3, 2);
    printElements();
    return 0;
}