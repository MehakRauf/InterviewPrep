#include <iostream>

using namespace std;

struct stack
{
    int value;
    stack *next;
};

stack *head = NULL;

void push(int val)
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    temp->value = val;
    if (head == NULL)
    {
        head = temp;
        head->next = NULL;
        return;
    }
    else
    {
        struct stack *curr = head;
        head = temp;
        head->next = curr;
        return;
    }
}

void pop()
{
    if (head == NULL)
    {
        cout << "Stack is empty!" << endl;
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    struct stack *curr = head->next;
    free(head);
    head = curr;
}

int top()
{
    if (head == NULL)
    {
        cout << "Stack is empty!" << endl;
        return 0;
    }
    return head->value;
}

void printElement()
{
    if (head == NULL)
    {
        cout << "No element in the stack!" << endl;
        return;
    }
    struct stack *curr = head;
    while (curr != NULL)
    {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    printElement();
    pop();
    cout << top() << endl;
    pop();
    cout << top() << endl;
    printElement();
    pop();
    cout << top() << endl;
    pop();
    cout << top() << endl;
    printElement();
    return 0;
}