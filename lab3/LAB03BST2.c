//
// Created by LG on 2022-11-07.
//
// LAB03BST2.c - Lab 03 - Gia, Lee


#include "LAB3_BST.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int numNodes = 0;

// stating the functions

// function checks if it is a bst
int checkBST(Node* node)
{
    if(node == NULL) return 1;
        // If node < left child, not valid.
        // If node > right child, it is not valid.
    else if(node->leftChild != NULL && (node->key < node->leftChild->key)) return 0;
    else if(node->rightChild != NULL && (node->key > node->rightChild->key)) return 0;

    return 1;
}

Tree* inputIdents() //function reading data from file "IDENTS.txt"
{
    FILE *fp = fopen("./IDENTS.TXT", "r");  // opens file
    if(fp == NULL)
    {
        printf("Could not open ident file. Exiting program.\n");
        exit(0);
    }

    char inputline[128];                // Allocate a memory
    const char seperator[3] = " \n";    // new line of input data.

    Tree* identTree = NULL;             // Create a tree to hold all of the data.

    // Variables to hold the input values as they are inputted.
    int key;
    char *val;
    char *copyVal;

    for(;;)
    {
        // Input line from text file.
        if(fgets(inputline, 128, fp) == NULL) break;

        // Seperates the input line into two different tokens.
        key = atoi(strtok(inputline, seperator));
        val = strtok(NULL, seperator);

        // Deep copy ensures there are no connections to the original variable.
        copyVal = malloc(strlen(val)+1); // Allocate the amount of space needed to hold the password value.
        strcpy(copyVal, val); // Deepcopy val (from inputline) into tempVal (seperate variable).

        if(numNodes == 0) // If there are no nodes, initiate new tree.
        {
            identTree = initTree(key,copyVal);
            numNodes++;
        }
        else if(find(key, identTree->root) == NULL) // If no node with current key exists.
        {
            insert(key,copyVal,identTree->root); // Input into existing tree.
            numNodes++; // Increase count of nodes in BST.
        }
        else if(find(key, identTree->root) != NULL) // If node with current key already exists.
        {
            find(key, identTree->root)->value = copyVal; // Replace old value with new value.
        }
    }
    printf("Input complete.\n");
    printf("BST NODES: %d\n", numNodes); // Print required status report.

    // Verify if BST is built properly.
    if(checkBST(identTree->root))
    {
        printf("BST is valid. Continuing...\n");
    }
    else
    {
        printf("BST is not valid. Exiting program.\n");
        exit(0);
    }

    return identTree;
}

void runDeletes(Tree* tree)
{
    FILE *fp = fopen ("./DELETES.TXT", "r"); // open input file
    if(fp == NULL)
    {
        printf("Could not open delete file. Exiting program.\n");
        exit(0);
    }

    char inputline[128];
    const char seperator[3] = " \n";

    Node *deleteNode = NULL;

    int key;

    for (;;)
    {
        // Input line from text file. If it is NULL, end of file has been reached, so break.
        if (fgets (inputline, 128, fp) == NULL) break;
        key = atoi(strtok(inputline, seperator)); // Gets the input token for the delete function.
        deleteNode = find(key, tree->root); // Find the node to be deleted.

        if(deleteNode != NULL) // If there is a valid node to delete, then continue.
        {
            withdraw(key,tree->root, deleteNode); // Removes the node with the specified key from the tree.
            if(find(key, tree->root) == NULL) // Verify that the node with the specific key does not exist any more.
            {
                numNodes--; // Decrease number of nodes.
            }
        }
    }
    printf("Deletes complete.\n");
    printf("NODES AFTER DELETES: %d\n", numNodes);

    // Verify if BST is still built properly.
    if(checkBST(tree->root))
    {
        printf("BST is valid. Continuing...\n");
    }
    else
    {
        printf("BST is not valid. Exiting program.\n");
        exit(0);
    }
}

void runLookups(Tree* tree)
{
    FILE *fp = fopen ("./LOOKUPS.TXT", "r"); // Attempt to open input file for deletes as specified in defines.
    // If file cannot be opened, indicate as such and terminate program.
    if(fp == NULL)
    {
        printf("Could not open delete file. Exiting program.\n");
        exit(0);
    }

    char inputline[128];
    const char seperator[3] = " \n";

    Node *lookupNode = NULL;

    // Variable to hold the input values as they are inputted.
    int key;

    printf("Credential Lookups:\n");

    for(;;)
    {
        // Input line from text file. If it is NULL, end of file has been reached, so break.
        if (fgets (inputline, 128, fp) == NULL) break;
        key = atoi(strtok(inputline, seperator)); // Gets the input token for the delete function.
        lookupNode = find(key, tree->root);

        // Output appropriate message based on lookup results.
        if(lookupNode == NULL) printf("<NOT FOUND>\n");
        else printf("ID %010d  PASSWORD %12s\n", lookupNode->key, lookupNode->value);
    }
}



void main(void)
{
    printf("-----------------------------------\n");
    Tree* identTree = inputIdents();
    printf("-----------------------------------\n");
    runDeletes(identTree);
    printf("-----------------------------------\n");
    runLookups(identTree);
    printf("-----------------------------------\n");
}