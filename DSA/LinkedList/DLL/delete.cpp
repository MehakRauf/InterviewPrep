#include <iostream>
using namespace std;

struct DLL
{
    int val;
    DLL *prev = NULL;
    DLL *next = NULL;
};
DLL *start = NULL;

void addValue(int n)
{

    DLL *temp = (struct DLL *)malloc(sizeof(struct DLL));
    temp->val = n;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
        return;
    }

    DLL *curr = start;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    temp->prev = curr;
    curr->next = temp;
}

void printValues()
{
    DLL *curr = start;
    while (curr != NULL)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

void deleteVal(int n)
{
    DLL *curr = start;

    if (start->val == n)
    {
        start->next->prev = NULL;
        start = start->next;
        free(curr);
        return;
    }
    while (curr != NULL)
    {
        if (curr->val == n)
        {
            if (curr->next != NULL)
            {
                curr->next->prev = curr->prev;
            }
            curr->prev->next = curr->next;
            free(curr);
            return;
        }
        curr = curr->next;
    }
}

int main()
{
    addValue(2);
    addValue(12);
    addValue(5);
    addValue(20);
    addValue(3);
    addValue(21);
    printValues();
    deleteVal(21);
    printValues();
    return 0;
}