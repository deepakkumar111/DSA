#include <iostream>

using namespace std;

// struct for an adjacency list node
// to hold data and next element
struct AdjListNode
{
    int data;
    AdjListNode *next;
};

// struct for an adjacency list

struct AdjList
{
    AdjListNode *head; //pointer to head node of list
};

//struct for a graph. A graph as an array of adjacency lists

struct Graph
{
    int V;
    AdjList *arr;
};

//create a new node
AdjListNode *newAdjListNode(int data)
{
    AdjListNode *nptr = new AdjListNode;
    nptr->data = data;
    nptr->next = NULL;
    return nptr;
}

//function to create a graph of V - vertices
Graph *createGraph(int V)
{
    Graph *graph = new Graph;
    graph->V = V;
    //create an array of adjacency list. size of array - V
    graph->arr = new AdjList[V];

    //initialize with NULL
    for (int i = 0; i < V; i++)
    {
        graph->arr[i].head = NULL;
    }
    return graph;
}

//add an edge to an undirected Graph
void addEdge(Graph *graph, int src, int dest)
{
    // add an edge from src to dest
    AdjListNode *nptr = newAdjListNode(dest);
    nptr->next = graph->arr[src].head;
    graph->arr[src].head = nptr;

    // as graph is undirected, add an edge from dest to src also
    nptr = newAdjListNode(src);
    nptr->next = graph->arr[dest].head;
    graph->arr[dest].head = nptr;
}

//function to print the graph
void printGraph(Graph *graph)
{
    for (int i = 0; i < graph->V; i++)
    {
        AdjListNode *root = graph->arr[i].head;
        cout << "Adjacency list of vertex " << i << endl;

        while (root != NULL)
        {
            cout << root->data << " -> ";
            root = root->next;
        }
        cout << endl;
    }
}

int main()
{
    //create a new graph
    int totalVertices = 4;
    Graph *graph;
    graph = createGraph(totalVertices);

    //connect edges
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    printGraph(graph);
}
// Created in master branch
// git remote set-url origin NEW_URL
// created 2
// Hello Kautuk
// Hello
