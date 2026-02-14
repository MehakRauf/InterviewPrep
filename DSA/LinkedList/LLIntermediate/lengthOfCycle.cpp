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

int lengthOfLoop()
{
    unordered_set<linkedList *> values;
    struct linkedList *curr = start, *startOfLoop;
    int count = 0;
    while (curr != NULL)
    {
        if (values.find(curr) != values.end())
        {
            startOfLoop = curr;
            do
            {
                count++;
                curr = curr->next;
            } while (curr != startOfLoop);
            return count;
        }
        values.insert(curr);
        curr = curr->next;
    }
}

void createLoop(int pos)
{
    if (start == NULL)
        return;

    struct linkedList *loopNode = NULL;
    struct linkedList *temp = start;
    int count = 1;

    // Find the node at position pos
    while (temp->next != NULL)
    {
        if (count == pos)
            loopNode = temp;
        temp = temp->next;
        count++;
    }

    // Connect last node to loopNode
    if (loopNode != NULL)
        temp->next = loopNode;
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

    createLoop(4);
    cout << lengthOfLoop() << endl;

    return 0;
}