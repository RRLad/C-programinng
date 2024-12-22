#include <stdio.h>
#include <stdlib.h>
#include "func.h"

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node *createList(int n)
{
    struct Node dummy = {0, NULL};
    struct Node *tail = &dummy;

    // Read n integers and create nodes
    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);

        struct Node *newNode = createNode(value);
        tail->next = newNode;
        tail = tail->next;
    }

    return dummy.next;
}

void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
        {
            printf("->");
        }
        current = current->next;
    }
    printf("->NULL\n");
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

    // Find insertion point
    struct Node *current = head;
    for (int i = 1; i < pos - 1 && current != NULL; i++)
    {
        current = current->next;
    }

    // Check if position is valid
    if (current == NULL)
    {
        printf("Position exceeds list length!\n");
        return head;
    }

    // Insert new node
    struct Node *newNode = createNode(value);
    newNode->next = current->next;
    current->next = newNode;

    return head;
}