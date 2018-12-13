#ifndef AVL_HEAD
#define AVL_HEAD
#include "bnode.h"

bool balanced(bnode* x);
int balance_fac(bnode* x);
bool AVLbalanced(bnode* x);

bool balanced(bnode* x){
    return x->left->height == x->right->height;
}

int balance_fac(bnode* x){
    return x->left->height = x->right->height;
}

bool AVLbalanced(bnode* x){
    return (-2 < balance_fac(x))&&(balance_fac(x) < 2);
}

# endif