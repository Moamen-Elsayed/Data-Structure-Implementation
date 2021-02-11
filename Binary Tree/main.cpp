#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

typedef int EType;

typedef struct Node{
    struct Node *right;
    EType val;
    struct Node *left;
}TNode;

typedef struct Node* BTREE;

TNode *insert_left(BTREE T, EType x){
    TNode* tmp;
    tmp = (TNode*) calloc(x, sizeof(TNode));
    if(tmp == NULL){
        return tmp;
    }else{
        tmp->val = x;
        tmp->left = tmp->right = NULL;
    }
    if(T == NULL){
        T = tmp;
        cout << x << " Is Inserted" << endl;
    }else{
        T->left = insert_left(T->left, x);
    }
    return T;
}

TNode *insert_right(BTREE T, EType x){
    TNode* tmp;
    tmp = (TNode*) calloc(x, sizeof(TNode));
    if(tmp == NULL){
        return tmp;
    }else{
        tmp->val = x;
        tmp->left = tmp->right = NULL;
    }
    if(T == NULL){
        T = tmp;
        cout << x << " Is Inserted" << endl;
    }else{
        T->right = insert_right(T->right, x);
    }
    return T;
}

TNode *insert_BST(BTREE T, EType x){
    TNode* tmp;
    tmp = (TNode*) calloc(x, sizeof(TNode));
    if(tmp == NULL){
        return tmp;
    }else{
        tmp->val = x;
        tmp->left = tmp->right = NULL;
    }
    if(T == NULL){
        T = tmp;
        cout << x << " Is Inserted" << endl;
    }else if(x >= T->val){
        T->right = insert_BST(T->right, x);
    }else{
        T->left = insert_BST(T->left, x);
    }
    return T;
}

void inorder(BTREE T){ // left -> root -> right
    if(T != NULL){
        inorder(T->left);
        cout << T->val << " " ;
        inorder(T->right);
    }
}

void preorder(BTREE T){ // root -> left -> right
    if(T != NULL){
        cout << T->val << " ";
        preorder(T->left);
        preorder(T->right);
    }
}

void postorder(BTREE T){ // left -> right -> root
    if(T != NULL){
        postorder(T->left);
        postorder(T->right);
        cout << T->val << " ";
    }
}

EType Height(BTREE T){
    EType h, max;
    if(T == NULL)
        return -1;
    else{
        h = Height(T->left);
        max = Height(T->right);
        if(h > max)
            max = h;
        return max+1;
    }
}

EType find_min_BST(BTREE T){
    if(T == NULL)
        return NULL;
    else if(T->left == NULL)
        return T->val;
    else
        return find_min_BST(T->left);
}

int main() {

    /*
     *       5
     *      / \
     *     3   6
     *          \
     *           8
     *          / \
     *         7   11
     */
    BTREE T1;
    T1 = NULL;
    T1 = insert_BST(T1, 5);
    T1 = insert_BST(T1, 6);
    T1 = insert_BST(T1, 3);
    T1 = insert_BST(T1, 8);
    T1 = insert_BST(T1, 7);
    T1 = insert_BST(T1, 11);

    inorder(T1);
    cout << endl;
    cout << "H = " << Height(T1) << endl;
    cout << find_min_BST(T1);
    return 0;
}
