#include <iostream>
using namespace std;

// detect the strting node of cycle return that node without using extra space
// if no cycle return NULL

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

linkedList *detectCycleNode()
{
    linkedList *slow = start, *fast = start;
    // while (fast && fast->next)
    // {
    //     slow = slow->next;
    //     fast = fast->next;

    //     if (slow == fast)
    //     {
    //         linkedList *prev = start;
    //         while (prev != slow)
    //         {
    //             prev = prev->next;
    //             slow = slow->next;
    //         }
    //         return prev;
    //     }
    // }
    // return NULL;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
        {
            break;
        }
    }

    if (fast == NULL || fast->next == NULL)
    {
        return NULL; // No cycle
    }
    
    slow = start;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
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
    return 0;
}