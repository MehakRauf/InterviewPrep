#include <iostream>
using namespace std;

struct linkedList
{
    int val;
    struct linkedList *next;
    linkedList(int x)
    {
        val = x;
        next = NULL;
    }
};

linkedList *head1 = NULL;
linkedList *head2 = NULL;

void addElement(linkedList *&head, int val)
{
    linkedList *temp = new linkedList(val);
    temp->val = val;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }

    linkedList *curr = head;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
}

linkedList *mergeTwoSortedLLs()
{
    linkedList dummy(-1);
    linkedList *curr = &dummy;
    struct linkedList *h1 = head1, *h2 = head2;

    while (h1 != NULL && h2 != NULL)
    {
        if (h1->val <= h2->val)
        {
            curr->next = h1;
            h1 = h1->next;
        }
        else
        {
            curr->next = h2;
            h2 = h2->next;
        }
        curr = curr->next;
    }
    if (h1 != NULL)
    {
        curr->next = h1;
    }
    if (h2 != NULL)
    {
        curr->next = h2;
    }
    return dummy.next;
}

void printElements(linkedList *start)
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
    // First linked list
    addElement(head1, 2);
    addElement(head1, 4);
    addElement(head1, 5);

    // Second linked list
    addElement(head2, 1);
    addElement(head2, 3);
    addElement(head2, 5);

    printElements(head1);
    printElements(head2);

    linkedList *res = mergeTwoSortedLLs();
    printElements(res);
    return 0;
}