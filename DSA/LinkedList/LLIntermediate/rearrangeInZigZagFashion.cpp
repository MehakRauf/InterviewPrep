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

void rearrangeInZigZagFashion()
{
    bool flag = true;
    linkedList *curr = start;
    while (curr->next != NULL)
    {
        if (flag)
        {
            if (curr->val > curr->next->val)
            {
                swap(curr->val, curr->next->val);
            }
        }
        else
        {
            if (curr->val < curr->next->val)
            {
                swap(curr->val, curr->next->val);
            }
        }
        curr = curr->next;
        flag = !flag;
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
    addElement(1);
    addElement(2);
    addElement(3);
    addElement(4);
    printElements();
    rearrangeInZigZagFashion();
    printElements();
    return 0;
}