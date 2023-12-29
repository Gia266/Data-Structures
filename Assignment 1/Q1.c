//
// Created by LG on 2022-10-11.
//
#include <stdio.h>
#include <stdlib.h>

/*
 * Basic structure of Node
 */
typedef struct node {
    int data;
    struct node * prev;
    struct node * next;
}node;

node *head = NULL;
node *tail = NULL;


/*
 * declare functions
 */
void create(int n);
void printList();
void insertfirst (); //inserting at the head of the node
void deletefirst (); // delete the first node
void insertpos (); // insert a node before the tail ig
void merge(); // merge LList D and LList E and reprint them smallest to biggest ig


int main()
{
    int n;
    int data;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);

    //call functions create and printLIst
    create(n);
    printf("print LList A\n");
    printList (); //printing LListA


    insertfirst();
    printf ("print LList B\n");
    printList();

    deletefirst();
    printf ("print LList C\n");
    printList();

    insertpos();
    printf ("print LList D\n");
    printList();

    merge();
    printf ("print List that has merged LList D and LList E in ascending order\n");
    printList();

    return 0;
}
//define functions create and printList

//creates doubly linked list after getting input from user
 void create(int n)
{
    int i, data;
    node *newNode;

    if(n > 0)
    {
        head = ( node *)malloc(sizeof( node));

        if(head != NULL)
        {
            printf("Enter data of head node:\n");
            scanf("%d", &data);

            head->data = data;
            head->prev = NULL;
            head->next = NULL;

            tail = head;

            /*
             * Create rest of the n-1 nodes
             */
            for(i=1; i<n; i++)
            {
                newNode = ( node *)malloc(sizeof( node));

                if(newNode != NULL)
                {
                    printf("Enter data of node:\n");
                    scanf("%d", &data);

                    newNode->data = data;
                    newNode->prev = tail; // Link new node with the previous node
                    newNode->next = NULL;

                    tail->next = newNode; // Link previous node with the new node
                    tail = newNode;          // Make new node as tail/previous node
                }
                else
                {
                    printf("Unable to allocate to newnode\n");
                    break;
                }
            }

            printf("doubly linked list created\n");
        }
        else
        {
            printf("Unable to allocate memory to head\n");
        }
    }
    return;
}

//prints list
void printList()
{
    struct node * ptemp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        ptemp = head;
//        printf("List:\n");

        while(ptemp != NULL)
        {
            printf("%4d", ptemp->data);

            /* Move the current pointer to next node */
            ptemp = ptemp->next;
        }
        printf("\n");
    }
    return;
}

void insertfirst(){

    int data;
    node*newNode;


    if (head == NULL){
        printf ("no list found create a list first\n");
        return;
    }
    else{
        newNode = (node*)malloc(sizeof(node));

        if (newNode != NULL){
            printf ("insert data for new head node\n" );
            scanf("%d", &data);

            newNode -> data = data;
            newNode -> next = head;
            newNode -> prev = NULL;

            head -> prev = newNode;

            head = newNode;
            printf ("insertion complete\n");
        }

    }

    return;
}

void deletefirst(){
    node * ptemp;
    if (head == NULL){
         printf ("there is no node to delete\n");

    }else{
        ptemp = head;
        head = head -> next;

        head -> prev = NULL ;
        free (ptemp);
        printf ("node deleted\n");
    }
    return;
}

void insertpos (){

    node* newNode = NULL;
    node*ptemp = NULL;
    int data;

//    ptemp = (node*) malloc (sizeof (malloc));

    if (head == NULL){
        printf ("list is empty\n");
    }else{
        ptemp = head;
        for(int i=0; i<1 ; i++){
            ptemp = ptemp->next;
        }
//        while (ptemp -> next != tail) {
//            ptemp = ptemp->next;
//        }

        newNode = (node*) malloc (sizeof(node));
        printf ("enter data of node to insert at second last position:\n");
        scanf("%d", &data);

        newNode->data = data;

        newNode->next = ptemp -> next;
        newNode -> prev = ptemp;
        ptemp -> next = newNode;


//        tail = ptemp -> next;
//        ptemp -> next = newNode;
//        tail -> prev = newNode;
//        newNode->next = tail;
//        newNode->prev = ptemp;

    }
    return;
}


void merge(){
    int n;
    int data;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);

    node* newNode = NULL;
    node*ptemp = NULL;
    node *newNode2=NULL;

//    ptemp = (node*) malloc (sizeof (malloc));

    if (tail == NULL){
        printf ("LList D is empty\n");
    }else{
        ptemp = head;
//        while (ptemp -> next != tail) {
//            ptemp = ptemp->next;
//        }

        for(int i = 0; i< n ; i++) {
            if(i ==0) {
                for(int j=0; j<1 ; j++){
                    ptemp = ptemp->next;
                }
                newNode = (node *) malloc(sizeof(node));
                printf("enter data for LList E:\n");
                scanf("%d", &data);

                newNode->data = data;

                newNode->next = ptemp->next;
                newNode->prev = ptemp;
                ptemp->next = newNode;

                newNode2 = (node *) malloc(sizeof(node));
                printf("enter data for LList E:\n");
                scanf("%d", &data);
                newNode2->data = data;
                newNode2->next = newNode -> next;
                newNode2 -> prev = newNode;
                newNode -> next = newNode2;


//                newNode->next = ptemp->next;
//                newNode->prev = ptemp;
//                ptemp->next = newNode;



            }
//            else if (i==1){
//                for(int j=0; j<2 ; j++){
//                    ptemp = ptemp->next;
//                }
//                newNode = (node *) malloc(sizeof(node));
//                printf("enter data for LList E:\n");
//                scanf("%d", &data);
//
//                newNode->data = data;
//
//                newNode->next = ptemp->next;
//                newNode->prev = ptemp;
//                ptemp->next = newNode;
//            }
            else if (i==2){
                for(int j=0; j<3 ; j++){
                    ptemp = ptemp->next;
                }
                newNode = (node *) malloc(sizeof(node));
                printf("enter data for LList E:\n");
                scanf("%d", &data);

                newNode->data = data;

                newNode->next = ptemp->next;
                newNode->prev = ptemp;
                ptemp->next = newNode;
            }
        }




//        tail = ptemp -> next;
//        ptemp -> next = newNode;
//        tail -> prev = newNode;
//        newNode->next = tail;
//        newNode->prev = ptemp;

    }

    return;
}