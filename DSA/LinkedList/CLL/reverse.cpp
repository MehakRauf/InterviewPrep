#include <iostream>

using namespace std;

struct CLL
{
    int val;
    CLL *next = NULL;
};
CLL *start = NULL;
CLL *tail = NULL;

void insert(int n)
{
    CLL *temp = (struct CLL *)malloc(sizeof(struct CLL));
    temp->val = n;

    if (start == NULL)
    {
        start = tail = temp;
        start->next = start;
        return;
    }

    tail->next = temp;
    temp->next = start;
    tail = temp;
}

void reverseElement()
{
    CLL *curr = start;
    CLL *prev = tail;
    CLL *next;
    do
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != start);

    tail = start;
    start = prev;
}

void printElements()
{
    struct CLL *curr = start;
    do
    {
        cout << curr->val << " ";
        curr = curr->next;
    } while (curr != start);
    cout << endl;
}

int main()
{

    insert(5);
    insert(25);
    insert(3);
    insert(5);
    insert(6);
    printElements();
    reverseElement();
    printElements();
    return 0;
}