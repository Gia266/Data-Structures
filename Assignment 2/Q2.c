//
// Created by LG on 2022-11-16.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode treeNode;

struct treeNode{
    int data;
    treeNode *left;
    treeNode *right;
};

typedef struct tree {
    treeNode *root;
} Tree;

//function to create a new node
treeNode *createNode(int data)
{
    treeNode *newNode = malloc(sizeof (treeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//makes a tree
Tree *MakeTree(int data, void *key)
{
    Tree* tree = malloc(sizeof(Tree));
    if (tree != NULL)
        tree->root = createNode(data);
    return tree;
}

//insertData function
int insertData(int data, void *key, treeNode *root)
{
    treeNode *result = malloc(sizeof(treeNode));
    if (root == NULL)	{
        treeNode *node = createNode(data);
        root = node;
    }

    if (data <= root->data) {

        if (root->left != NULL)
            result = insertData(data, key, root->left);
        else {
            treeNode *n = createNode(data);
            root->left = n;
        }
    } else if (data >= root->data) {
        if (root->right != NULL)
            result = insertData(data,key,root->right);
        else {
            treeNode  *n = createNode(data);
            root->right = n;
        }
    }
    return result;
}

//function converting tree into an array
int treeToArray(treeNode *root, int arr[], int index)
{
    if(root == NULL)
        return index;
    arr[index] = root->data;
    index++;
    if(root->left != NULL)
        index = treeToArray(root->left, arr, index);
    if(root->right != NULL)
        index = treeToArray(root->right, arr, index);
    return index;
}
//counts how may nodes in the tree
int count(treeNode *root)
{
    int i= 1;

    if (root == NULL)
        return 0;
    else
    {
        i += count(root->left);
        i += count(root->right);
        return i;
    }
}
Tree *Merge(treeNode *root1, treeNode *root2)
{
    int size1 = count(root1);
    int size2 = count(root2);

    int array1[size1];
    int array2[size2];

//convert both the BST to arrays
    treeToArray(root1, array1, 0);
    treeToArray(root2, array2 , 0);

    int totalSize = size1 + size2;
    int merge[totalSize];
    for (int i = 0; i < size1; i++)
    {
        merge[i] = array1[i];
    }

    for(int i = 0, j = size1; (j < totalSize)&&(i < size2); i++, j++)
    {
        merge[j] = array2[i];
    }

   printf("\n");
    int v1 = 1;
    Tree *t = MakeTree (merge[0],&v1);
    for(int i = 1; i < totalSize+1; i++)
    {
        insertData(merge[i], &v1, t->root);
    }
    return t;
}

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


void printCurrentLevel(treeNode *root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void breadthTraversal(struct treeNode* root)
{
    int height = findHeight(root);
    int i;
    for (i = 1; i <= height; i++) {
        printCurrentLevel(root, i);
        printf("\n");
    }

}

int main() {

    //create first tree
    int root1 = 1;
    Tree *tree1 = MakeTree (3,&root1);
    insertData(1, &root1, tree1->root);
    insertData(2, &root1, tree1->root);
    insertData(5, &root1, tree1->root);

    //create second tree
    int root2 = 1;
    Tree *tree2 = MakeTree (4,&root2);
    insertData(1, &root2, tree2->root);
    insertData(2, &root2, tree2->root);
    insertData(7, &root2, tree2->root);
    insertData(9, &root2, tree2->root);

    Tree *tree3 = Merge(tree1->root, tree2->root);
    breadthTraversal(tree3->root);
    return 0;
}
