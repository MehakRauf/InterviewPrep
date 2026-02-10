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

void deleteElement(int toDelete)
{
    struct linkedList *temp = start;
    struct linkedList *prev = start;
    if (start->val == toDelete)
    {
        start = start->next;
        free(temp);
        return;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->val == toDelete)
            {
                prev->next = temp->next;
                free(temp);
                break;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
    }
    if (temp == NULL)
    {
        cout << "The value is not present in the linkedList" << endl;
    }
    else
    {
        cout << "The value is deleted successfully!" << endl;
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
    addElement(2);
    addElement(4);
    addElement(5);
    addElement(8);
    addElement(3);
    addElement(25);
    printElements();
    deleteElement(2);
    printElements();
    deleteElement(25);
    printElements();
    return 0;
}