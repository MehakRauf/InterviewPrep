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

void deleteElement(int n)
{
    CLL *curr = start;
    if (start->val == n)
    {
        start = start->next;
        tail->next = start;
        free(curr);
        return;
    }
    curr = start->next;
    CLL *prev = start;
    while (curr != start)
    {
        if (curr->val == n)
        {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

int main()
{

    insert(5);
    insert(25);
    insert(3);
    insert(5);
    insert(6);
    deleteElement(3);
    printElements();
    return 0;
}