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

int nthEndNode(int n)
{
    if (start == NULL)
    {
        return -1;
    }

    int len = 0;
    struct linkedList *curr = start;
    while (curr != NULL)
    {
        len++;
        curr = curr->next;
    }

    curr = start;
    for (int i = 1; i <= len - n; i++)
    {
        curr = curr->next;
    }

    if (curr != NULL)
    {
        return curr->val;
    }
    return -1;
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
    cout << nthEndNode(2) << endl;
    cout << nthEndNode(4) << endl;
    cout << nthEndNode(1) << endl;

    return 0;
}