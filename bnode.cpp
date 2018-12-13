#include "bnode.h"

bool less(int l,int r){
    return l < r;
}
bool more(int l,int r){
    return r < l;
}
bool equal(int l,int r){
    return l == r;
}

void updateHeight(bnode* r){
    if(!r) return;
    int temp = 1;
    if(r->left && r->right)
        temp = 1 + max(r->left->height, r->right->height);
    else if(r->left)
        temp = 1 + r->left->height;
    else if(r->right)
        temp = 1 + r->right->height;
    // Target: stop the updating process.
    if(temp == r->height) return;
    r->height = temp;
    updateHeight(r->parent);
}

bnode* zig(bnode* r){
    if(!(r->left)) return nullptr;
    bnode* tmp = r->left->right;
    r->left->right = r;
    r->left = tmp;
    // 切换根节点
    if(r->parent->left == r)
        r->parent->left = r->left;
    else
        r->parent->right = r->left;
    r->left->parent = r->parent;
    r->parent = r->left;
    return r->left;
}

bnode* zag(bnode* r){
    if(!(r->right)) return nullptr;
    bnode* tmp = r->right->left;
    r->right->left = r;
    r->right = tmp;
    // 切换根节点
    if(r->parent->left == r)
        r->parent->left = r->right;
    else
        r->parent->right = r->right;
    r->right->parent = r->parent;
    r->parent = r->right;
    return r->right;
}

void swap(bnode* a,bnode* b){
    int temp = a->index;
    a->index = b->index;
    b->index = temp;
}

bnode* pred(bnode* r){
    if(!r->left){
        bnode* tmp = r;
        bnode* temp = tmp->parent;
        if(!tmp->parent) return nullptr;
        while(temp->left == tmp){
            tmp = temp; temp = temp->parent;
            if(!tmp->parent) return nullptr;
        }
        return temp;
    }
    bnode* tmp = r->left;
    while(tmp->right) tmp = tmp->right;
    return tmp;
}

bnode* succ(bnode* r){
    if(!r->right){
        bnode* tmp = r;
        bnode* temp = tmp->parent;
        if(!tmp->parent) return nullptr;
        while(temp->right == tmp){
            tmp = temp; temp = temp->parent;
            if(!tmp->parent) return nullptr;
        }
        return temp;
    }
    bnode* tmp = r->right;
    while(tmp->left) tmp = tmp->left;
    return tmp;
}

