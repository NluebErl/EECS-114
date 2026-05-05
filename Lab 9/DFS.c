#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 12
int vertexCount = 0;

struct Vertex
{
    char label;
    int foundTime;
    int finishTime;
    bool visited;
    struct Vertex* parent;
};

int adjMatrix[MAX][MAX];
struct Vertex* lstVertices[MAX];

void addVertex(char label) 
{
    struct Vertex* vertex = (struct Vertex*)malloc(sizeof(struct Vertex));
    vertex->label = label;
    vertex->parent = NULL;
    vertex->visited = false;
    lstVertices[vertexCount++] = vertex;
}

void addEdge(int start,int end) 
{
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;
}

void displayVertex(int vertexIndex) 
{
    printf("%c ",lstVertices[vertexIndex]->label);
}

// get the adjacent unvisited vertex
int getAdjUnvisitedVertex(int vertexIndex) 
{
    int i;
    for(i = 0; i < vertexCount; i++) 
    {
        if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false) 
        {
            return i;
        }
    }
    return -1;
}

void DFSVisit(int vertexIndex, int* time);
void DFS();


int main()
{
    addVertex('a');
    addVertex('b');
    addVertex('c');
    addVertex('d');
    addVertex('e');
    addVertex('f');
    addVertex('g');
    addVertex('h');
    addVertex('i');
    addVertex('j');
    addVertex('k');
    addVertex('l');

    addEdge(0, 1);
    addEdge(0, 6);
    addEdge(0, 7);
    addEdge(1, 2);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(2, 4);
    addEdge(7, 8);
    addEdge(7, 11);
    addEdge(8, 9);
    addEdge(8, 10);

    for(int i = 0; i < vertexCount; i++)
    {
        displayVertex(i);
    }
    printf("\n");

    DFS();

    for (int i = 0; i < vertexCount; i++)
    {
        printf("Vertex %c: found = %d finish = %d\n", lstVertices[i]->label, lstVertices[i]->foundTime, lstVertices[i]->finishTime);
    }

    // Print Adjacency Matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertexCount; i++)
    {
        printf("%c: ", lstVertices[i]->label);
        for (int j = 0; j < vertexCount; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void DFS()
{
    for (int i = 0; i < vertexCount; i++)
    {
        lstVertices[i]->visited = false;
        lstVertices[i]->parent = NULL;
    }

    int time = 0;

    for (int i = 0; i < vertexCount; i++)
    {
        if (!lstVertices[i]->visited)
        {
            DFSVisit(i, &time);
        }
    }
}

void DFSVisit(int vertexIndex, int* time)
{
    (*time)++;
    lstVertices[vertexIndex]->foundTime = *time;
    lstVertices[vertexIndex]->visited = true;
    for (int i = 0; i < vertexCount; i++)
    {
        if (getAdjUnvisitedVertex(vertexIndex) != -1)
        {
            int adjVertexIndex = getAdjUnvisitedVertex(vertexIndex);
            lstVertices[adjVertexIndex]->parent = lstVertices[vertexIndex];
            DFSVisit(adjVertexIndex, time);
        }
    }
    (*time)++;
    lstVertices[vertexIndex]->finishTime = *time;
}