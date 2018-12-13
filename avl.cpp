#include "bnode.h"
#include "avl.h"

bnode* search(bnode* r,int index){
    // Purpose: Avoid segment fault.
    if(!r) return nullptr;
    if (less(index,r->index)) return (r->left) ?search(r->left ,index):r;
    if (more(index,r->index)) return (r->right)?search(r->right,index):r;
    return r;
}

bool leftHigher(bnode* r){
    return balance_fac(r) > 0;
}

bool rightHigher(bnode* r){
    return balance_fac(r) < 0;
}

bool rotateAt(bnode* r){
    // False mean not rotate at all.
    if(AVLbalanced(r)) return false;
    if(leftHigher(r)){
        if(!rightHigher(r->left)){
            zig(r);
        }else{
            zag(r->left); zig(r);
        }
    }else{
        if(!leftHigher(r->right)){
            zag(r);
        }else{
            zig(r->right); zag(r);
        }
    }
    return true;
}

bnode* insert(bnode* r,int index){
    bnode* tmp = search(r, index);
    // Purpose: Avoid segment fault:
    if(!tmp) return nullptr;
    if(equal(index,tmp->index)) return nullptr;
    if(less(index, tmp->index)){
        tmp->left = new bnode;
        tmp->left->parent = tmp;
        tmp->left->index = index;
        tmp->left->height = 1;
        for(auto temp = tmp->left ; temp ; temp = temp->parent){
            if(rotateAt(temp)) break;
            updateHeight(temp);
        }
        return tmp->left;
    }
    else if(more(index, tmp->index)){
        tmp->right = new bnode;
        tmp->right->parent = tmp;
        tmp->right->index = index;
        tmp->right->height = 1;
        for(auto temp = tmp->right ; temp ; temp = temp->parent){
            if(rotateAt(temp)){
                updateHeight(temp);
                break;
            }
        }
        return tmp->right;
    }
    // Rebalance the tree
}

bool removeAt(bnode* tmp){
    if((!tmp->left) && (!tmp->right)){
        // TODO: Is there any method which can make this ugly remove
        // method run in a better way?
        if(tmp->parent->left == tmp)
            tmp->parent->left = nullptr;
        else
            tmp->parent->right = nullptr;
        delete tmp;
        return true;
    }
    if(tmp->left && (!tmp->right)){
        // Single branch remove
        bnode* temp = tmp->left;
        tmp->index = temp->index;
        tmp->right = temp->right;
        tmp->left = temp->left;
        delete temp;
        return true;
    }
    else if(tmp->right && (!tmp->left)){
        bnode* temp = tmp->right;
        tmp->index = temp->index;
        tmp->left = temp->left;
        tmp->right = temp->right;
        delete temp;
        return true;
    }
    return false;
}

bnode* remove(bnode* r,int index){
    bnode* tmp = search(r,index);
    if(!tmp) return nullptr;
    if(equal(index,tmp->index)){
        if(removeAt(tmp)){
            for(auto temp = tmp ; temp ; temp = temp->parent){
                if(rotateAt(temp)) updateHeight(temp);
            }
        }
        if(tmp->left && tmp->right){
            // Purpose: double branch
            bnode* next = succ(tmp);
            swap(tmp,next);
            if(removeAt(next))
                for(auto temp = tmp ; temp ; temp = temp->parent){
                    if(rotateAt(temp)) updateHeight(temp);
            }
        }
    }
    // Not Equal. Return nullptr.
    return nullptr;
}