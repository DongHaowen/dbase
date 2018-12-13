PP = g++

all: main

main: bnode.cpp main.cpp 
	$(PP) main.cpp bnode.cpp -O2 -o main

test: bnode.cpp test.cpp bnode_normal.cpp
	$(PP) test.cpp bnode.cpp bnode_normal.cpp -O2 -o test