#include <stdio.h>
#include <stdlib.h>

struct StackNode{
    int data;
    struct StackNode* next;
};

struct StackNode* newNode(int data){
    struct StackNode* stackNode =
        (struct StackNode*) malloc(sizeof(struct StackNode));

    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode* root){
    return (root == NULL);
}

int peek(struct StackNode* root){
    if (isEmpty(root))
        return -1;
    return root->data;
}

void push(struct StackNode* root, int data){
    struct StackNode* node = newNode(data);

    node->next = root->next;
    root->next = node;
}

int pop(struct StackNode* root){
    if (root == NULL || root->next == NULL)
        return -1;

    struct StackNode* temp = root->next;
    int popped = temp->data;

    root->next = temp->next;
    free(temp);

    return popped;
}

void PrintStack(struct StackNode* root){
    struct StackNode* temp = root;

    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    // Create the first node manually
    struct StackNode* root = newNode(0);

    for (int i = 1; i < 20; i++)
    {
        push(root, i);
    }

    PrintStack(root);

    return 0;
}