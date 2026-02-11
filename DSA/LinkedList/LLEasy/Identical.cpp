#include <iostream>
using namespace std;

struct linkedList
{
    int val;
    struct linkedList *next;
};

linkedList *head1 = NULL;
linkedList *head2 = NULL;

void addElement(linkedList *&head, int val)
{
    linkedList *temp = (linkedList *)malloc(sizeof(linkedList));
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

bool isIdentical()
{

    if (head1 == NULL || head2 == NULL)
        return false;

    struct linkedList *c1 = head1;
    struct linkedList *c2 = head2;

    while (c1 != NULL && c2 != NULL)
    {
        if (c1->val != c2->val)
        {
            return false;
        }
        c1 = c1->next;
        c2 = c2->next;
    }

    if (c1 == NULL && c2 == NULL)
    {
        return true;
    }
    return false;
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
    addElement(head2, 2);
    addElement(head2, 4);
    addElement(head2, 5);

    printElements(head1);
    printElements(head2);
    cout << isIdentical() << endl;
    return 0;
}