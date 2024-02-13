# TODO: Complete the Makefile
#graph_h.o: graph.c graph.h
#	gcc -o graph graph.c graph.h
#main: main.c main.h graphc
#	gcc -o main main.h graphc

#.PHONY: clean

#clean:
#	rm -f 

p_main: main.c graph.c graph.h main.h
	gcc -o depGraph main.c graph.c
#can put ./depGraph arg1 agr2 here if you want it run straight from compilation

.PHONY: clean

clean:
	rm -f depGraph