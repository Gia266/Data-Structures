//
// Created by LG on 2022-10-12.
//
#include <stdio.h>
#include <stdlib.h>
#define bool	unsigned char
#define	false	(unsigned char) 0
#define true	(unsigned char) 1

int  top = -1;
int  stack [100];

// Queue is linked list of items.
struct item	{
    struct item		*next;
    int				value;
};
typedef struct item		Item, *pItem;

// Queue implementation
typedef struct queue{
    Item *front;
    Item *end;
}queue;

void createQueue(queue *pqueue){
    pqueue -> front =NULL;
    pqueue -> end = NULL;
    int count;
};


bool qinsert (queue *pqueue, int n)
// Add value n to queue end of queue
{
    // Create node to hold value being added to queue
    Item	*pnew = (Item *)malloc(sizeof (struct item));
    bool	result = false;
    if (pnew != NULL)	{
        pnew->value = n;
        pnew->next = NULL;
        // Make current last node point to new node
        if (pqueue->end != NULL)	{
            pqueue->end->next = pnew;
        }
        // and update queue's end pointer
        pqueue-> end = pnew;
        // If queue was empty, new node is also new front node
        if (pqueue->front == NULL)	pqueue->front = pnew;
//        count++;
        result = true;
    }
    return result;
}//qinsert()


void printList(queue *pqueue)
{
    Item *pv = pqueue -> front;
    while(pv)
    {
        printf("%5d",pv->value);
        pv = pv->next;
    }
}


int push (int n)
{
    if (top == 99)  return 0;
    stack[++top] = n;
    return  1;
}//push()

int pop (int n){
    if (top == -1) return 0; // if it has no input

    n =stack [top] ;
    top = top -1;

    printf("%5d", n);
    //return 1;
}

int main (){
    queue q1;
    createQueue(&q1);

    int k;
    printf ("enter k value:\n");
    scanf("%d", &k);

    int number;
    printf ("enter number of integers:\n");
    scanf ("%d", &number);

    int myArray [100];
    for(int i = 0; i<number; i++){
        printf("enter integer:\n");
        scanf ("%d", &myArray [i]);
    }

    for (int i=0; i<k; i++){
        push (myArray[i]);
    }

    printf("reverse for line of characters:\n");
    for (int i= 0; i< k; i++){
        pop (myArray [i]);
    }

    for (int i = k; i < number ; i++ ){
        qinsert(&q1, myArray[i]);
    }

    printList(&q1);
    putchar('\n');

    return 0;
}
