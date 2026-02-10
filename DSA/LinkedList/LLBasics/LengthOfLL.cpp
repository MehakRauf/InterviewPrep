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

int lengthOfLL()
{
    int count = 0;
    struct linkedList *curr = start;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
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
    cout << lengthOfLL() << endl;
    return 0;
}