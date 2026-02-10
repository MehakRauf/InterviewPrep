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

// k -> position
void deleteAtK(int k)
{
    struct linkedList *prev = NULL;
    struct linkedList *temp = start;

    if (k == 1)
    {
        start = start->next;
        free(temp);
        return;
    }
    for (int i = 1; i < k; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    free(temp);
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
    addElement(3);
    addElement(25);
    printElements();
    deleteAtK(4);
    printElements();
    return 0;
}