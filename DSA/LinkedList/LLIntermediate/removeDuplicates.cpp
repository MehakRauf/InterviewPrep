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

void removeDups()
{
    unordered_set<int> s;
    linkedList *curr = start, *prev = NULL;
    while (curr != NULL)
    {
        if (s.find(curr->val) != s.end())
        {
            prev->next = curr->next;
            linkedList *temp = curr;
            curr = curr->next;
            free(temp);
        }
        else
        {
            s.insert(curr->val);
            prev = curr;
            curr = curr->next;
        }
    }
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
    addElement(12);
    addElement(14);
    addElement(5);
    addElement(5);
    addElement(5);
    addElement(8);
    addElement(8);
    addElement(8);
    addElement(-3);
    addElement(25);
    printElements();
    removeDups();
    printElements();
    return 0;
}