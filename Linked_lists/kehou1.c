#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createList(int n);
void printList(struct Node *head);
struct Node *insertList(struct Node *head, int value, int pos);

struct Node *createNode(int n)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = n;
    node->next = NULL;

    return node;
}

struct Node *createList(int n)
{
    struct Node dummy = {0, NULL};
    struct Node *tail = &dummy;

    for (int i = 1; i <= n; i++)
    {
        struct Node *node = createNode(i);
        tail->next = node;
        tail = tail->next;
    }

    return dummy.next;
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node *insertList(struct Node *head, int value, int pos)
{
    if (pos <= 0)
    {
        return head;
    }
    else if (pos == 1)
    {
        struct Node *newNode = createNode(value);
        newNode->next = head;
        return newNode;
    }
    else
    {
        struct Node *current = head;
        // Changed starting point to 1
        for (int i = 1; (i < pos - 1) && (current != NULL); i++)
        {
            current = current->next;
        }

        // Fixed comparison operator
        if(current == NULL){
            return head;
        }

        struct Node *newNode = createNode(value);
        newNode->next = current->next;
        current->next = newNode;

        return head;
    }
}