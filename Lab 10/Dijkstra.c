#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 9
int vertexCount = 0;

typedef struct Vertex
{
    char label; 
    bool visited;
    int distance;
    struct Vertex* parent;
} Vertex;

int adjMatrix[MAX][MAX];

void initAdjMatrix() {
    for (int i = 0; i < MAX; i++) 
    {
        for (int j = 0; j < MAX; j++) 
        {
            adjMatrix[i][j] = -1;
        }
    }
}
Vertex* lstVertices[MAX];

void addVertex(char label) 
{
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->label = label;
    vertex->parent = NULL;
    vertex->visited = false;
    vertex->distance = 0;
    lstVertices[vertexCount++] = vertex;
}

void addEdge(int start, int end, int weight) 
{
    adjMatrix[start][end] = weight;
    adjMatrix[end][start] = weight;
}

void displayVertex(int vertexIndex) 
{
    printf("%c ", lstVertices[vertexIndex]->label);
    printf("weights: ");
    for (int j = 0; j < vertexCount; j++) 
    {
        printf("%d ", adjMatrix[vertexIndex][j]);
    }
    printf("\n");
}

// get the adjacent unvisited vertex
int getAdjUnvisitedVertex(int vertexIndex) 
{
    int i;
    for(i = 0; i < vertexCount; i++) 
    {
        if(adjMatrix[vertexIndex][i] != -1 && lstVertices[i]->visited == false) 
        {
            return i;
        }
    }
    return -1;
}

Vertex* ExtractMin(Vertex* Q[])
{
    int minIndex = -1;
    int minDistance = INT_MAX;
    for (int i = 0; i < vertexCount; i++)
    {
        if (Q[i]->visited == false && Q[i]->distance < minDistance)
        {
            minDistance = Q[i]->distance;
            minIndex = i;
        }
    }
    return Q[minIndex];
}

bool IsEmpty(Vertex* Q[])
{
    for (int i = 0; i < vertexCount; i++)
    {
        if (Q[i]->visited == false)
        {
            return false;
        }
    }
    return true;
}

void InitSingleSource(Vertex* listVertices[], int source)
{
    for (int i = 0; i < vertexCount; i++)
    {
        listVertices[i]->distance = INT_MAX;
        listVertices[i]->parent = NULL;
        listVertices[i]->visited = false;
    }
    listVertices[source]->distance = 0;
}

void Relax(Vertex* u, Vertex* v, int weight)
{
    if (v->distance > u->distance + weight)
    {
        v->distance = u->distance + weight;
        v->parent = u;
    }
}

void Dijkstra(Vertex* listVertices[], int source)
{
    InitSingleSource(listVertices, source);
    Vertex** Q = listVertices;
    while (!IsEmpty(Q))
    {
        Vertex* u = ExtractMin(Q);
        u->visited = true;
        for (int i = 0; i < vertexCount; i++)
        {
            int weight = adjMatrix[u->label - 'A'][i];
            if (weight != -1)
            {
                Relax(u, listVertices[i], weight);
            }
        }
    }
}

int main()
{
    initAdjMatrix();
    addVertex('A');
    addVertex('B');
    addVertex('C');
    addVertex('D');
    addVertex('E');
    addVertex('F');
    addVertex('G');
    addVertex('H');
    addVertex('I');

    addEdge(0, 1, 4); //
    addEdge(0, 7, 8); // 
    addEdge(1, 2, 8); // 
    addEdge(1, 7, 11); // 
    addEdge(2, 3, 7); // 
    addEdge(2, 8, 2); //
    addEdge(2, 5, 4); //
    addEdge(3, 4, 9); //
    addEdge(3, 5, 14); //
    addEdge(4, 5, 10); // 
    addEdge(5, 6, 2); //
    addEdge(6, 7, 1); //
    addEdge(6, 8, 6); //
    addEdge(7, 8, 7); //

    for (int i = 0; i < vertexCount; i++)
    {
        displayVertex(i);
    }
    printf("\n");

    // Print Adjacency Matrix
    InitSingleSource(lstVertices, 0);
    printf("Adjacency Matrix (weights):\n   ");
    // Print column headers
    for (int j = 0; j < vertexCount; j++) 
    {
        printf("%c ", lstVertices[j]->label);
    }
    printf("\n");
    for (int i = 0; i < vertexCount; i++)
    {
        printf("%c: ", lstVertices[i]->label);
        for (int j = 0; j < vertexCount; j++)
        {
            if (adjMatrix[i][j] == -1) // No Edge
                printf(". "); 
            else
                printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    Dijkstra(lstVertices, 0);

    for (int i = 0; i < vertexCount; i++)
    {
        printf("Vertex %c: distance = %d\n", lstVertices[i]->label, lstVertices[i]->distance);
    }

    return 0;
}