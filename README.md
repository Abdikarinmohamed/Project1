# Project1


# Test machine, date, team member names, and x500

* **Test Machine**: CSELAB_KH1-25
* **Date**: 02/15/24
* **Team Members Name**: Abdirahman Abdi, Leban Abraham, Abdikarin Mohamed
* **X500 IDs**: abdi0405, abrah771, moha1357



# Your and your partners’ contributions

Abdirahman Abdi:
CreateDepGraph - Consolidated with Teammates and created a solution on how read in input.
DFSVISIT - Added fucntionality for sequential and parallel mode
ExecuteCommand - Created a function to take commands array and node, and break it into tokens so it can 
    executed by execvp();


Leban Abraham:
CreateDepGraph - Worked with teammates on single solution for graph creation
DFSVisit - helped with sequential logic planning
Worked on testcases and printing to file




Abdikarin:



# How to compile the program:
* To compile the program, navigate to the project directory and run the following command: ```make p_main``` This command tells make to execute the p_main rule, which will compile our source files into the executable named depGraph. After compiling, you can then run our program with: ```./depGraph ../testcases/input1.txt```



# The purpose of your program
The purpose of this program is to simulate a dependency graph execution, where nodes represent commands that must be executed in a specific order based on their dependencies. This is for managing software package dependencies, ensuring that all prerequisites are met before a package is installed. The program supports both sequential and parallel execution modes, demonstrating concepts of process creation and synchronization in operating systems.

# What exactly your program does
The program reads a dependency graph from an input text file, constructs a representation of this graph, and then executes the commands represented by the graph nodes. In sequential mode, commands are executed one after the other, following the dependencies. In parallel mode, independent commands can run concurrently, but with the constraint that a node's commands only run after all its dependencies have been satisfied.

# Any assumptions outside this document (If you have)
* Assumes all commands in the input file are valid and executable on the test machine.
* Assumes the input file does not contain cycles, adhering to a tree structure.
* Assumes the presence of a POSIX-compliant environment for fork/exec/wait operations.
