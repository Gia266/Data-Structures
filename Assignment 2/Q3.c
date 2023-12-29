//
// Created by LG on 2022-11-17.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct treeNode{
    int data;
    struct treeNode *left;
    struct treeNode *right;
}treeNode;

struct treeNode *insertData(struct treeNode *node, int data){
    if (node == NULL) {
        struct treeNode *temp = (treeNode *) malloc (sizeof (treeNode));
        temp -> data = data; //still follows the treeNode struct doe can even just put this into the insert function too
        temp -> left = NULL;
        temp -> right = NULL;
        // always right node first ig ->
        return temp;
    }
        //is the input data smaller than the parent?
    else if (data < (node-> data)){
        node -> left = insertData(node->left, data);

    }else if (data > (node -> data)){ //is input data bigger than parent?
        node -> right = insertData(node -> right, data);
    }
    return node;
}

//define helper function that will find the height
int findHeight(treeNode *node){
    int heightLeft;
    int heightRight;
    int heightNumber;

    if (node==NULL){
        return heightNumber =0;
    }else {
        heightLeft = findHeight(node->left);
        heightRight = findHeight(node->right);

        if(heightLeft>heightRight){
            heightNumber = heightLeft + 1;
        }else{
            heightNumber = heightRight + 1;
        }

    }
    return heightNumber;
}
bool isBalanced(struct treeNode* root)
{

    int leftHeight;
    int rightHeight;

    //empty tree is a balnced tree
    if (root == NULL)
        return true;


    leftHeight = findHeight(root->left);
    rightHeight= findHeight(root->right);

    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
        return true;
    }else
        return false;
}

struct treeNode* rightRotate(struct treeNode* y){
    struct treeNode* x = y->left;
    struct treeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

struct treenode* leftRotate(struct treeNode* x){
    struct treeNode* y = x->right;
    struct treeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

int getBalance(struct treeNode* N){
    if(N == NULL)
        return 0;
    return findHeight(N->left)- findHeight(N->right);
}

struct treeNode* Rotation(struct treeNode* root){


    int balance = getBalance(root);
    //left left case
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    //left right case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    //right right case
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }
    //right left case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    Rotation(root->left);
    Rotation(root->right);


    return root;


}
//void rotation(){
//
//}

void preOrder(struct treeNode *node){
    // check if there are nodes
    if (node == NULL) return;

    //prints the nodes
    printf("%d\n", node->data);

    //recursion functions
    preOrder(node->left);
    preOrder(node->right);
}



int main(){
    treeNode *root = NULL;
    root = insertData(root, 12);
    root = insertData(root, 8);
    root = insertData(root, 5);
    root = insertData(root, 4);
    root = insertData(root, 2);
    root = insertData(root, 9);
    root = insertData(root, 18);
    root = insertData(root, 17);

    //now balance it
    struct treeNode* root2 = Rotation(root);

    while(isBalanced(root2) == false) {
        //do they need to bee rotated?
        if (isBalanced(root2->left) == false) {
            if (getBalance(root2) < 1) {
                root2->left = rightRotate(root2->left);
            } else if (getBalance(root2) > 1) {
                root2->left = leftRotate(root2->left);
            }
        }

        if (isBalanced(root2->right) == false) {
            if (getBalance(root2) < 1) {
                root2->right = leftRotate(root2->right);
            } else if (getBalance(root2) > 1) {
                root2->right = rightRotate(root2->right);
            }
        }
    }


    printf("\n");

    printf("Pre Order Traversal of Rotated Tree\n");
    preOrder(root2);

    return 0;
}

