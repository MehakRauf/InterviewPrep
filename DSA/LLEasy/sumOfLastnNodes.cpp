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

int sumOfnNodes(int n)
{
    struct linkedList *fast = start, *slow = start;
    for (int i = 1; i <= n; i++)
    {
        if (fast == NULL)
            return 0; // n> length
        fast = fast->next;
    }

    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    int sum = 0;
    while (slow != NULL)
    {
        sum += slow->val;
        slow = slow->next;
    }
    return sum;
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
    cout << sumOfnNodes(3) << endl;
    return 0;
}