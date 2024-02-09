#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

// A structure to represent an adjacency list node 
struct AdjListNode { 
    int dest;
    struct AdjListNode* next; 
}; 
  
// A structure to represent an adjacency list 
struct AdjList{
    int visit;
    struct AdjListNode *head; 
}; 
  
// A structure to represent a graph. A graph 
// is an array of adjacency lists. 
// Size of array will be V (number of vertices  
// in graph) 
struct DepGraph{ 
    int V; 
    struct AdjList* array; 
}; 

// TODO: Declare functions in the graph.c
// A utility function to create a new adjacency list node 
struct AdjListNode* newAdjListNode(int dest);
  
// A utility function that creates a graph from the input text file
struct DepGraph* createDepGraph(FILE *input, char cmds[][550]);
  
// Adds an edge to an directed graph 
void addEdge(struct DepGraph* graph, int src, int dest);

// Recursive DFS call
void DFSVisit(struct DepGraph* graph, int node, char cmds[][550], int mode);

// execute the generated graph
void processGraph(struct DepGraph* graph, char cmds[][550], int mode);

#endif