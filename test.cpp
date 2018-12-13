#define DEBUG

#include "depend.h"
#include "bnode.h"
#include <iostream>

using namespace std;

bnode* root = new bnode;

void driver(){
    char c = 'a';
    int index;
    bnode* tmp;
    while(c != 'q'){
        cin >> c >> index;
        switch(c){
            case 'i':insert(root,index);break;
            case 'r':remove(root,index);break;
            case 's':
            tmp = search(root,index);
            if(tmp->index == index) printf("Get\n");
            else printf("Not\n");
            break;
            default:
            printf("None\n");
        }
        midrun(root);
        printf("\n");
    }
}

int main(){
    root->index = 0;
    printf("Test Start\n");
    driver();
    printf("Test End\n");
}