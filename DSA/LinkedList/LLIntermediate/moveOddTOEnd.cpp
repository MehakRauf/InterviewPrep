#include <iostream>
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

void moveOddToEnd()
{
    linkedList *evenHead = NULL, *evenTail, *oddHead = NULL, *oddTail;
    linkedList *curr = start;
    while (curr != NULL)
    {
        if (curr->val % 2 == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = curr;
                evenTail = curr;
            }
            else
            {
                evenTail->next = curr;
                evenTail = evenTail->next;
            }
        }
        else
        {
            if (oddHead == NULL)
            {
                oddHead = oddTail = curr;
            }
            else
            {
                oddTail->next = curr;
                oddTail = oddTail->next;
            }
        }
        curr = curr->next;
    }
    if (!evenHead)
    {
        start = oddHead;
    }
    evenTail->next = oddHead;

    if (oddTail)
    {
        oddTail->next = NULL;
    }
    start = evenHead;
}
int main()
{
    addElement(2);
    addElement(4);
    addElement(5);
    addElement(8);
    addElement(3);
    addElement(25);
    printElements();
    moveOddToEnd();
    printElements();
    return 0;
}