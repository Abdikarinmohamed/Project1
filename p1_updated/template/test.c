#include "graph.h"

struct AdjListNode* newAdjListNode(int dest){ //the constructor for an adjListNode
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
    newNode->dest = dest; 
    newNode->next = NULL; 
    return newNode; 
} 

void addEdge(struct DepGraph* graph, int src, int dest){
    // If the head of the AdjList array element at the index of src is null, 
    // we create a new node using newAdjListNode()
    // and make the head of the AdjList array element at the index of src points to it.

    if(graph->array[src].head == NULL){//a pointer to struct and a struct can access its members using a dot op.
    struct AdjListNode* newNode = newAdjListNode(dest);
    graph->array[src].head = newNode;
    }else{
        struct AdjListNode* currNode = graph->array[src].head;
        while(currNode->next != NULL){//stops when node.next is null
            currNode = currNode->next;
        }
         struct AdjListNode* newNode = newAdjListNode(dest);
         currNode->next = newNode;//adds node at the end
    }
    // If the head of the AdjList array element at the index of src is NOT null,
    // then we will traverse to the next AdjListNode until we find a node is pointing to a null.
    // Create a new node using newAdjListNode() and make the current node point to it.
}

void processGraph(struct DepGraph* graph, char cmds[32][550], int mode){
    int i;
    int child = fork();
    if (child == 0) {
	   DFSVisit(graph, 0, cmds, mode);
    }
    else {
        wait(NULL);
    }
}

void DFSVisit(struct DepGraph* graph, int node, char cmds[32][550], int mode) {
    // Use RECURSION to traverse the node in DepGraph's AdjList array, 
    // so that the execution of child nodes happened before the parent node.
    // If the mode is sequential, wait child process to finish before moving on to the next node.
    // If the mode is parallel, move on to the next node.
    if(graph->array[node].head == NULL || graph->array[node].visit == 1){
        return;
    }
   

    //pid_t pid = getpid();
    pid_t parentPid = getppid();
    FILE *resultsFile = fopen("results.txt", "a");
    if(resultsFile == NULL){
        perror("Error opening results.txt");
        exit(EXIT_FAILURE);
    }
    
   
    graph->array[node].visit = 1;
    struct AdjListNode* currNode = graph->array[node].head;
    while(currNode != NULL){
        
        pid_t pid = fork(); //parent process holds the child id, and child holds zero if succesfull
        if(pid == 0){//child process
            //printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
            //printf("Node: %d cmd: %s", currNode->dest, cmds[currNode->dest]);
            DFSVisit(graph, currNode->dest, cmds, mode);
            fprintf(resultsFile, "PID=%d, Parent PID=%d, Commands=%s\n", getpid(), getppid(), cmds[currNode->dest]);
            //write to file then close file  currNode->dest,
            fclose(resultsFile);
            _exit(0);
            
        }else if(pid > 0){//parent
            if(mode == 1){
                wait(NULL);//wait for child process to finish
                
            }else{
                while(wait(NULL) > 0);
            }
        }else{
            perror("Fork Failed");
            exit(1);
        }
        
        currNode = currNode->next;
        /*if(mode == 1){
            DFSVisit(graph, currNode->dest, cmds, mode);
        }*/
    }

    if (mode != 1) {
        while (wait(NULL) > 0);
    }


    /*while(wait(NULL) > 0); This is for parellel mode*/
   // Now all child processes have completed. The parent process can print its own details.
    // In sequential mode, this happens after waiting for all children.
    // In parallel mode, this happens after all children have been forked and waited on.
    if (graph->array[node].head == NULL || mode == 1 || (mode != 1 && currNode == NULL)) { //
        fprintf(resultsFile, "PID=%d, Parent PID=%d, Commands=%s\n", getpid(), getppid(), cmds[node]);
        system(cmds[node])
        // Note: Do not close the resultsFile here, as it will be used by other processes.
        //if you do it will double print the parents
        
    }
    
    
    
    // Let's move on to complete the code that will be executed in each recursion.
    // Open the results.txt file. If the file does not exist, then create one using c code.

    // Get the PID of the current process and its parent process
    // Write the PIDS and commands to the results.txt
     //fclose(output);//in the parent process
    // execute the command at the given node.
    
}


int main(int argc, char **argv) {

    int mode;
    ssize_t read;
	size_t len = 0;
	char *line = NULL; //no memory has been set aside yet

    int V;
    char cmds[32][550] = {};

    FILE *input = fopen("../testcases/input1.txt", "r");
    if(input == NULL){
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    int numVertex;
    if((read = getline(&line, &len, input)) != -1){
        sscanf(line, "%d", &numVertex);
    }

    getline(&line, &len, input); //reads in the '\n'
    int lineCount = 0; //holds index of to be copied line & (cnt?)
    while ((read = getline(&line, &len, input)) != -1) { //getline(char **pstring, size_t *size, FILE *stream);

         if(read > 1 && line[0] != '\n'){
            strncpy(cmds[lineCount], line, read - 1);  //(dest, src, #num of chars to be copied)
                //the read-1 is bec strncpy adds the '\0' which is added twice later, so we stop the duplicate by stopping before it.
            cmds[lineCount][read - 1] = '\0'; //adds the '\0' back on
            lineCount++;
        }else{
            break; //either read is failed or line contains a new line, which seperates the commands | edges.
        }
    }



    printf("Num nodes: %d\n", numVertex);
    for (int i = 0; i < lineCount; i++) {
        printf("%s\n", cmds[i]);
    }

    struct DepGraph* newGraph = (struct DepGraph*) malloc(sizeof(struct DepGraph));
    if (newGraph == NULL) {
    // Handle allocation failure
    }

    newGraph->V = numVertex;
    //newGraph->array = malloc(numVertex * sizeof(struct AdjList)); //works without this
    if (newGraph->array == NULL) {
    // Handle allocation failure
    }
    struct AdjList* adjLists = (struct AdjList*) malloc(numVertex * sizeof(struct AdjList));
    for (int i = 0; i < numVertex; i++) {
        adjLists[i].head = NULL; // Assuming the AdjList structure has a head pointer
    }
    newGraph->array = adjLists;//now points to the first adjList


    while((read = getline(&line, &len, input)) != -1){
        char* token = strtok(line, " ");
        int src, dest;
        if(token != NULL){
            sscanf(token, "%d", &src);
            token = strtok(NULL, " ");//moves it infront of 2nd #
            if(token != NULL){
                sscanf(token, "%d", &dest);
                //printf("Number 1: %d, Number 2: %d\n", src, dest);
                addEdge(newGraph, src, dest);
            }
        }
    }
    
    int i = 0;
    for(int i = 0; i < numVertex; i++){
        struct AdjListNode* currNode = newGraph->array[i].head;
        while(currNode != NULL){
            printf("Node %d: -> Node:%d\n", i, currNode->dest);
            currNode = currNode->next;
        }
        //printf("\n");
    }
    
    processGraph(newGraph, cmds, 0);

   
    
    
    // Free the allocated line buffer
    free(line);

    // Close the file
    fclose(input);

    return 0;
}