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

void searchElement(int toSearch)
{
    int idx = 0;
    struct linkedList *temp = start;
    if (start->val == toSearch)
    {
        cout << "The value is found at the start 0th position" << endl;
        return;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->val == toSearch)
            {
                cout << "The value is found at index " << idx << endl;
                break;
            }
            temp = temp->next;
            idx++;
        }
    }
    if (temp == NULL)
    {
        cout << "The value is not present in the linkedList" << endl;
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
    searchElement(5);
    searchElement(0);
    return 0;
}