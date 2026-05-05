#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

Node* TreeInsert(Node* root, int data);
Node* TreeSearch(Node* root, int key);
void printTreeOrder(Node* root);
void printTreeLevelOrder(Node* root);


int main() 
{
    Node* root = NULL;
    srand(time(NULL));

    // Insert 10 random values into the tree
    for (int i = 1; i <= 10; i++)
    {
        int x = rand() % 100;
        root = TreeInsert(root, x);
        printf("Inserted: %d; ", x);
    }
    printf("\n");

    // Print out the tree in level order
    printf("Tree printed out in PreOrder:\n");
    printTreeLevelOrder(root);
    printf("\n");

    // Print out the tree in order
    printf("Tree printed out in Order: ");
    printTreeOrder(root);
    printf("\n");

    // Let the user determine what value to search for in the tree
    printf("Enter a value to search for in the tree: ");
    int key;
    scanf("%d", &key);
    Node* searchResult = TreeSearch(root, key);
    if (searchResult != NULL)
    {
        printf("Value %d found in the tree at address %p.\n", key, (void*)searchResult);
    }
    else
    {
        printf("Value %d not found in the tree.\n", key);
    }

    return 0;
}

Node* TreeInsert(Node* root, int data)
{
    // Initialize the new node and set up pointers for traversal
    Node* newNode = createNode(data);
    Node* parent = NULL;
    Node* current = root;

    // Traverse the tree to find the correct position for the new node
    while (current != NULL)
    {
        parent = current;
        if (data < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    // Set the parent pointer of the new node
    newNode->parent = parent;

    // If the tree was empty, the new node becomes the root
    if (parent == NULL)
    {
        return newNode;
    }
    else if (data < parent->data)
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
    }

    return root;
}

Node* TreeSearch(Node* root, int key)
{
    // Traverse the tree to find the node with the specified key
    while(root != NULL && root->data != key)
    {
        // Move to the left or right child based on the comparison of the key with the current node's data
        if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return root;
}

void printTreeOrder(Node* root) 
{
    // Recursively print the tree in order (left, root, right)
    if (root != NULL)
    {
        printTreeOrder(root->left);
        printf("%d ", root->data);
        printTreeOrder(root->right);
    }
}

void printTreeLevelOrder(Node* root) 
{
    if (root == NULL)
    {
        return;
    }

    // Initialize a queue for level order traversal
    Node* queue[100];
    int front = 0;
    int rear = 0;

    // Enqueue the root node
    queue[rear++] = root;

    int level = 0;

    // Continue until the queue is empty
    while (front < rear)
    {
        // Calculate the number of nodes at the current level and display
        int levelSize = rear - front;
        printf("Level %d: ", level);

        // Process all nodes at the current level
        for (int i = 0; i < levelSize; i++)
        {
            // Dequeue the current node and print its data
            Node* current = queue[front++];
            printf("%d ", current->data);

            // Enqueue the left and right children of the current node if they exist
            if (current->left != NULL)
            {
                queue[rear++] = current->left;
            }
            if (current->right != NULL)
            {
                queue[rear++] = current->right;
            }
        }

        // Move to the next line after printing all nodes at the current level
        printf("\n");
        level++;
    }
}