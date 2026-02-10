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

void moveLastToFront()
{
    if (start == NULL)
    {
        return;
    }
    if (start->next == NULL)
    {
        return;
    }

    struct linkedList *curr = start;
    struct linkedList *prev = NULL;

    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    curr->next = start;
    prev->next = NULL;
    start = curr;
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
    moveLastToFront();
    printElements();
    return 0;
}