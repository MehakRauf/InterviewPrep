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

int getNthElement(int n)
{
    if (start == NULL)
    {
        return -1;
    }
    struct linkedList *curr = start;
    int idx = 1;
    while (curr != NULL && idx < n)
    {
        curr = curr->next;
        idx++;
    }
    if (curr == NULL)
    {
        return -1;
    }
    return curr->val;
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
    cout << getNthElement(4) << endl;
    cout << getNthElement(3) << endl;
    cout << getNthElement(9) << endl;
    cout << getNthElement(6) << endl;
    cout << getNthElement(1) << endl;
    return 0;
}