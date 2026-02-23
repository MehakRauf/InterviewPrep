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

void reverse()
{
    DLL *curr = start, *temp = NULL;
    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }

    if (temp)
    {
        start = temp->prev;
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
    reverse();
    printValues();
    return 0;
}