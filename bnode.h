#pragma once
#include "math.h"

struct bnode{
    int index; int height = 1;
    bnode *left = nullptr, *right = nullptr;
    bnode *parent;
};

void updateHeight(bnode* r);

// Brief: conter rotate
bnode* zig(bnode* r);

// Brief: anti rotate
bnode* zag(bnode* r);

void swap(bnode* a,bnode* b);

bnode* pred(bnode* r);

bnode* succ(bnode* r);

#ifdef DEBUG
#include <stdio.h>
void display(bnode* r, int depth){
    if(!r) return;
    display(r->left,depth+1);
    for(auto i = 0; i < depth ; ++i){
        printf(" ");
    }
    printf("%d\n",r->index);
    display(r->right,depth+1);
}

void displayAll(bnode* r){
    display(r,0);
}

void midrun(bnode *r){
    if(!r) return;
    midrun(r->left);
    printf("%d ",r->index);
    midrun(r->right);
}
#endif

// Comparation Function
bool less(int l,int r);
bool more(int l,int r);
bool equal(int l,int r);

bnode* search(bnode* r,int index);
bnode* insert(bnode* r,int index);
bnode* remove(bnode* r,int index);


