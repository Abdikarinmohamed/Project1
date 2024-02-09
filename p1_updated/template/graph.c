#include "graph.h"

struct AdjListNode* newAdjListNode(int dest){ //the constructor for an adjListNode
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
    newNode->dest = dest; 
    newNode->next = NULL; 
    return newNode; 
} 

// TODO: This function is to read files. And based on the file content, build a DepGraph (please refer to figure 1 in project1.pdf).
// Please take a close look at the file structure on page 2, section 4, "Sample Input."
struct DepGraph* createDepGraph(FILE *input, char cmds[][550]){
	ssize_t read;
	size_t len = 0;
	char *line = NULL; //no memory has been set aside yet
    int V;

    // First, let's read the number of nodes and all commands from the input file!
    // 1. Get the number of nodes using getline() and sscanf()
        
    // 2. Skip the blank line. {DONE}

    // 3. Read all commands from the file using a loop until reach the source-destination section (reaches a newline character '\n')
    // We won't do anything to cmds[][550] in this function OTHER THAN reading all commands from it.

    // Now, let's move to Graph Creation!
    // Dynamically allocate the memory space to the DepGraph.
    // Then, initialize the value of V (Number of nodes), and Dynamically allocate the memory space to DepGraph's AdjList array

    // Initialize each element in the DepGraph's AdjList array

    // Now, let's build edges to this DepGraph
    // Inside each loop iteration, use getline(), strtok(), and sscanf() to tokenize sources and destinations from the file.
    // Sources and destinations represent edges between commands. (please refer to figure 1 in project1.pdf)
    // Add edge to the DepGraph using addEdge(), source, and destination   
   
    return graph; 
}

// TODO: This function adds an edge to the node inside DepGraph's AdjList array. 
// Recall how to insert elements to the linked list in lab 1.
void addEdge(struct DepGraph* graph, int src, int dest){
    // If the head of the AdjList array element at the index of src is null, 
    // we create a new node using newAdjListNode()
    // and make the head of the AdjList array element at the index of src points to it.

    // If the head of the AdjList array element at the index of src is NOT null,
    // then we will traverse to the next AdjListNode until we find a node is pointing to a null.
    // Create a new node using newAdjListNode() and make the current node point to it.
}

// TODO: This function writes the DephGraph to the output file and executes the commands.
// Please take a close look at the file structure on page 3, section 5, "Sample Output".
void DFSVisit(struct DepGraph* graph, int node, char cmds[][550], int mode) {
    // Use RECURSION to traverse the node in DepGraph's AdjList array, 
    // so that the execution of child nodes happened before the parent node.
    // If the mode is sequential, wait child process to finish before moving on to the next node.
    // If the mode is parallel, move on to the next node.

    // Let's move on to complete the code that will be executed in each recursion.
    // Open the results.txt file. If the file does not exist, then create one using c code.

    // Get the PID of the current process and its parent process
    // Write the PIDS and commands to the results.txt

    // execute the command at the given node.
    
}

void processGraph(struct DepGraph* graph, char cmds[][550], int mode){
    int i;
    int child = fork();
    if (child == 0) {
	   DFSVisit(graph, 0, cmds, mode);
    }
    else {
        wait(NULL);
    }
}
