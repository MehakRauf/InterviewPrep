// C++ program to find union and intersection of two
// unsorted linked lists

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

// Function to check if a value is present in the linked list
bool isPresent(Node *head, int value)
{
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == value)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

// Function to find the union of two linked lists
Node *findUnion(Node *head1, Node *head2)
{
    Node *res = NULL, *prev = NULL, *curr;
    curr = head1;
    while (curr != NULL)
    {
        if (!isPresent(res, curr->data))
        {
            Node *newNode = new Node(curr->data);
            if (res == NULL)
            {
                res = newNode;
                prev = newNode;
            }
            else
            {
                prev->next = newNode;
                prev = newNode;
            }
        }
        curr = curr->next;
    }
    curr = head2;
    while (curr != NULL)
    {
        if (!isPresent(res, curr->data))
        {
            Node *newNode = new Node(curr->data);
            if (res == NULL)
            {
                res = newNode;
                prev = newNode;
            }
            else
            {
                prev->next = newNode;
                prev = newNode;
            }
        }
        curr = curr->next;
    }
    return res;
}

// Function to find the intersection of two linked
// lists using brute force
Node *findIntersection(Node *head1, Node *head2)
{
    Node *res = NULL, *prev = NULL, *h1 = head1, *h2 = head2;
    while (h1 != NULL)
    {
        Node *newNode = new Node(h1->data);
        if (isPresent(head2, h1->data) && !isPresent(res, h1->data))
        {
            if (res == NULL)
            {
                res = newNode;
                prev = newNode;
            }
            else
            {
                prev->next = newNode;
                prev = newNode;
            }
        }
        h1 = h1->next;
    }
    return res;
}

void printList(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{

    // Creating two hardcoded linked lists
    Node *head1 = nullptr;
    Node *head2 = nullptr;

    // Insert elements into the first linked list
    // 10 -> 15 -> 4 -> 20
    head1 = new Node(10);
    head1->next = new Node(15);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(20);

    // Insert elements into the second linked list
    // 8 -> 4 -> 2 -> 10
    head2 = new Node(8);
    head2->next = new Node(4);
    head2->next->next = new Node(20);
    head2->next->next->next = new Node(10);

    Node *unionList = findUnion(head1, head2);
    Node *intersectionList = findIntersection(head1, head2);

    cout << "Union: ";
    printList(unionList);

    cout << "Intersection: ";
    printList(intersectionList);

    return 0;
}