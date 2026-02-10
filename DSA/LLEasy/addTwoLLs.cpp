#include <iostream>
#include <unordered_set>
using namespace std;

struct linkedList
{
    int val;
    struct linkedList *next;
    linkedList(int v) : val(v), next(nullptr) {}
};
struct linkedList *start1 = NULL;
struct linkedList *start2 = NULL;

void addElement(int val, linkedList **start)
{
    struct linkedList *temp = new linkedList(val);
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

void reverseLL(linkedList **start)
{
    struct linkedList *prev = NULL, *next = NULL, *curr = *start;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *start = prev;
}

linkedList *addLinkedLists()
{
    int carry = 0;
    reverseLL(&start1);
    reverseLL(&start2);
    struct linkedList *l1 = start1, *l2 = start2, *res = NULL, *curr = NULL;

    while (carry != 0 || l1 != NULL || l2 != NULL)
    {
        int sum = carry;

        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        sum = sum % 10;

        linkedList *newNode = new linkedList(sum);
        // if the result ll is null then make this as head
        if (res == NULL)
        {
            res = newNode;
            curr = newNode;
        }
        // otherwise add it to the next and move curr to it
        else
        {
            curr->next = newNode;
            curr = newNode;
        }
    }
    // return the head of the resultant ll
    reverseLL(&res);
    return res;
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
    cout << "First number: ";
    printElements(start1);

    addElement(4, &start2);
    addElement(5, &start2);
    addElement(8, &start2);
    addElement(5, &start2);
    addElement(5, &start2);
    addElement(2, &start2);
    cout << "Second number: ";
    printElements(start2);

    linkedList *resultant = addLinkedLists();
    cout << "Sum: ";
    printElements(resultant);

    return 0;
}
