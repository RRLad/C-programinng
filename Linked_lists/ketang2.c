#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Convert singular linked list to circular linked list
Node *toCircularList(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = head;

    return head;
}

Node *getWinner(Node *head, int m)
{
    Node *circularList = toCircularList(head);

    
}