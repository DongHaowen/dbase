#include "bnode.h"

bnode* search(bnode* r,int index){
    // Purpose: Avoid segment fault.
    if(!r) return nullptr;
    if (less(index,r->index)) return (r->left) ?search(r->left ,index):r;
    if (more(index,r->index)) return (r->right)?search(r->right,index):r;
    return r;
}

bnode* insert(bnode* r,int index){
    bnode* tmp = search(r, index);
    // Purpose: Avoid segment fault:
    if(!tmp) return nullptr;
    if(less(index, tmp->index)){
        tmp->left = new bnode;
        tmp->left->parent = tmp;
        tmp->left->index = index;
        tmp->left->height = 1;
        updateHeight(tmp->left);
        return tmp->left;
    }
    if(more(index, tmp->index)){
        tmp->right = new bnode;
        tmp->right->parent = tmp;
        tmp->right->index = index;
        tmp->right->height = 1;
        updateHeight(tmp->right);
        return tmp->right;
    }
    return tmp;
}

void removeAt(bnode* tmp){
    if((!tmp->left) && (!tmp->right)){
        // TODO: Is there any method which can make this ugly remove
        // method run in a better way?
        if(tmp->parent->left == tmp)
            tmp->parent->left = nullptr;
        else
            tmp->parent->right = nullptr;
        delete tmp; 
    }
    if(tmp->left && (!tmp->right)){
        // Single branch remove
        bnode* temp = tmp->left;
        tmp->index = temp->index;
        tmp->right = temp->right;
        tmp->left = temp->left;
        delete temp;
    }if(tmp->right && (!tmp->left)){
        bnode* temp = tmp->right;
        tmp->index = temp->index;
        tmp->left = temp->left;
        tmp->right = temp->right;
        delete temp;
    }
}

bnode* remove(bnode* r,int index){
    bnode* tmp = search(r,index);
    if(!tmp) return nullptr;
    if(equal(index,tmp->index)){
        removeAt(tmp);
        if(tmp->left && tmp->right){
            // Purpose: double branch
            bnode* next = succ(tmp);
            swap(tmp,next);
            removeAt(next);
        }
    }
    // Not Equal. Return nullptr.
    return nullptr;
}