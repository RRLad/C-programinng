#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

void deleteDuplicates(struct Node *head)
{
    // End if linked list is null or it only has a single node
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    // Array to store if data is already seen
    bool isSeen[101] = {false};

    // Initialize current and previous nodes
    struct Node *current = head;
    struct Node *prev = NULL;

    while (current != NULL)
    {

        if (isSeen[current->data])
        {
            prev->next = current->next;
        }
        else
        {
            isSeen[current->data] = true;
            prev = current;
        }

        current = current->next;
    }
}