// Question 1

/*
 * 1. write a main function that builds a tree
 * 2. write a postorder(); function that outputs the tree in postorder tree traversal.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// create nodes for trees
// the tree node is not one node but three nodes hehe
 struct treeNode{
    char data;
    struct treeNode *left;
    struct treeNode *right;
};

// cant do typedef here ig cuz neNode is a pointer not a new struct yaknow
struct treeNode * newNode(char data){
// allocate memory to node
    struct treeNode *node = (struct treeNode*)malloc (sizeof (node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
// even though it returns just node its still new node
    return node;
};
//treeNode *root;

//void buildTree(); // function that creates a tree
void postOrder(struct treeNode *node); // travers and print the tree in postorder method

int main (){
    //create the tree :0
    //initialize root (level 0)
    // has to do treenode instead of node cuz or else it doesnt have nuull pointers to left and right
    struct treeNode *root = newNode('A');

    //initialize level 1 nodes
    root -> left = newNode('B');
    root -> right = newNode('C');

    //initialize level 2 nodes
    root -> left -> left = newNode('D');
    root-> left -> right = newNode('E');
    root-> right -> left = newNode('F');
    root -> right -> right = newNode('G');

    //level 3 roots
    root -> left-> left -> left = newNode ('H');
    root -> left -> left-> right = newNode ('I');
    root -> left -> right -> left = newNode ('J');
    root -> right -> right -> left = newNode('K');

    // you can also code it by giving each node a name and then giving it values i guess hehe
    printf("postorder printing of the tree:\n");
    postOrder(root);


    return 0;
}

void postOrder(struct treeNode *node){
    // check if there are nodes
    if (node == NULL) return;

    //recursion functions
    postOrder(node->left);
    postOrder(node->right);
    //finally prints after returning
    printf("%c\n", node->data);
}

//recall to initialize a character cannot use "" must use ' '