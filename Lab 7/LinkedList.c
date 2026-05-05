#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void PrintLinkedList(Node* node);

int main(void)
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // Malloc memory for three nodes of the linked list
    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));

    // Assign data and link each node to the next node
    head->data = 1;
    head->next = second;
    printf("Head node data: %d\n", head->data);
    printf("Head node is located at: %p\n", (void*)head);
    printf("Head node points to: %p\n", (void*)head->next);
    second->data = 2;
    second->next = third;
    printf("Second node data: %d\n", second->data);
    printf("Second node is located at: %p\n", (void*)second);
    printf("Second node points to: %p\n", (void*)second->next);
    third->data = 3;
    third->next = NULL;
    printf("Third node data: %d\n", third->data);
    printf("Third node is located at: %p\n", (void*)third);
    printf("Third node points to: %p\n", (void*)third->next);

    // Print the linked list
    printf("Linked list: ");
    PrintLinkedList(head);
    return 0;
}

void PrintLinkedList(Node* node)
{
    int index = 1;
    while (node != NULL)
    {
        printf("Value #%d is %d; ", index, node->data);
        node = node->next;
        index++;
    }
}