#include "main.h"

// hint: to access the files or directories in the parent directory, use "../name_of_your_data"
int main(int argc, char **argv) {
	
	// Validate command-line argument.
	// Uncomment section below and fill out the condition of the if branch
	 if (argc == 0) {
		printf("Incorrect number of arguments...\n");
	 	printf("Usage 1: ./depGraph input_text_file\n");
	 	printf("Usage 2: ./depGraph -p input_text_file\n");
	 	exit(1);
	 }

	// mode 0 DFS
	// mode 1 parallel
	int mode;
	FILE *input;

	// Uncomment the section below and complete the fopen arguments
	 if (argc == 2) {
	 	mode = 0;
	 	input = fopen(argv[1], "r");
	 } else if (argc ==3) {
	 	mode = 1;
	 	input = fopen(argv[2], "r");
	 }

	
	if(!input) {
		printf("File %s not found...\n", argv[1]);
		printf("Exiting...\n");
		exit(1);
	}

	char cmds[32][550];
	struct DepGraph *depGraph = createDepGraph(input, cmds);

	fclose(input);

	processGraph(depGraph, cmds, mode);

	return 0;
}