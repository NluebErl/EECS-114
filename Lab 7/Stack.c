#include <stdio.h>
#include <stdlib.h>

struct StackNode{
    int data;
    struct StackNode* next;
};

// Initialize a stack
struct StackNode* newNode(int data){
    struct StackNode* stackNode = (struct StackNode*) malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// check whether the stack is empty
int isEmpty(struct StackNode* root);

// return the top element of stack
int peek(struct StackNode* root);

// add item to the stack
void push(struct StackNode** root, int data);

// remove item from the stack
int pop(struct StackNode** root);

void PrintStack(struct StackNode* root);

int main()
{
    // Create a stack and push items to the stack
    struct StackNode* root = NULL;

    // Check if the stack is empty
    printf("Stack created. Is stack empty? %s\n", isEmpty(root) ? "Yes" : "No");

    // Push integers 0 to 19 to the stack
    for (int i = 0; i < 20; i++)
    {
        push(&root, i);
    }
    printf("\nStack after pushing integers 0 to 19:\n");
    PrintStack(root);

    printf("Is stack empty? %s\n", isEmpty(root) ? "Yes" : "No");

    // Pop items from the stack and print them
    for (int i = 0; i < 10; i++)
    {
       pop(&root);
    }
    printf("\nStack after popping 10 items:\n");
    PrintStack(root);

    // Add more items to the stack
    for (int i = 20; i < 30; i++)
    {
        if (i % 2 == 0)
        {
            push(&root, i);
        }
    }
    printf("\nStack after pushing even integers from 20 to 29:\n");
    PrintStack(root);

    // Pop one item from the stack
    pop(&root);
    printf("\nStack after popping one item:\n");
    PrintStack(root);

    // Display the top item of the stack
    printf("\nTop item is %d\n", peek(root));

    return 0;
}

int isEmpty(struct StackNode* root)
{
    // If the stack is empty, return 1, otherwise return 0
    return (root == NULL);
}

int peek(struct StackNode* root)
{
    // Return -1 if the stack is empty, otherwise return the value at the root
    if (isEmpty(root))
    {
        return -1;
    }
    return root->data;
}

void push(struct StackNode** root, int data)
{
    // Create a new node with data and set the next pointer to the current root, and update the root to point to the new node
    struct StackNode* node = newNode(data);
    node->next = *root;
    *root = node;
}

int pop(struct StackNode** root)
{
    if (isEmpty(*root))
    {
        return -1;
    }

    // Store current root to a temp variable, update the root to the next node, and free temporary variable
    struct StackNode* temp = *root;
    int popped = temp->data;
    *root = temp->next;
    free(temp);
    return popped;
}

void PrintStack(struct StackNode* root)
{
    struct StackNode* temp = root;
    while (temp != NULL)
    {
        printf("%d -> ", peek(temp));
        temp = temp->next;
    }
    printf("NULL\n");
}
