#include <iostream>
#include <unordered_set>
using namespace std;

struct linkedList
{
    int val;
    struct linkedList *next;
};
struct linkedList *start1 = NULL;
struct linkedList *start2 = NULL;

void addElement(int val, linkedList **start)
{
    struct linkedList *temp = (struct linkedList *)malloc(sizeof(struct linkedList));
    temp->val = val;
    temp->next = NULL;
    if (*start == NULL)
    {
        *start = temp;
        return;
    }
    struct linkedList *curr = *start;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
}

void removeDups()
{
    unordered_set<int> uniqueElements;
    struct linkedList *curr = start1;
    while (curr != NULL)
    {
        if (uniqueElements.find(curr->val) == uniqueElements.end())
        {
            addElement(curr->val, &start2);
            uniqueElements.insert(curr->val);
        }
        curr = curr->next;
    }
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
    addElement(2, &start1);
    addElement(2, &start1);
    addElement(2, &start1);
    addElement(4, &start1);
    addElement(4, &start1);
    addElement(4, &start1);
    addElement(5, &start1);
    addElement(8, &start1);
    addElement(25, &start1);
    addElement(25, &start1);
    addElement(25, &start1);
    printElements(start1);
    removeDups();
    printElements(start2);
    return 0;
}