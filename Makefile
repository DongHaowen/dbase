PP = g++

all: main

main: bnode.cpp main.cpp 
	$(PP) main.cpp bnode.cpp -O2 -o main

avl: avltest.cpp avl.cpp bnode.cpp
	$(PP) avltest.cpp bnode.cpp avl.cpp -O2 -o avltest 

test: bnode.cpp test.cpp bnode_normal.cpp
	$(PP) test.cpp bnode.cpp bnode_normal.cpp -O2 -o test