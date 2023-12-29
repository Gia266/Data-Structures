// queueproblem.c – Lab 02 – Gia, Lee

/*
 * Implement a multi-instance version of the linked-list queue. In your program, create 4 queues. Read
numbers until you encounter a negative integer input. For every number input, if the number modulo
4 is 0, put the number in the first queue; if the number modulo 4 is 1, put the number in the second
queue; if the number modulo 4 is 2, put it in the third queue, and if the number modulo 4 is 3, put it
in the fourth queue. When the negative number is input, output all the numbers in the first queue,
then all the numbers in the second queue, then all the numbers in the third queue, and then all the
numbers in the fourth queue.


Detailed specifications:
• The input shall be integer numbers separated by spaces or newlines. There may be as many as
400 inputs, and it is possible that all input numbers modulo 4 will evaluate to the same value.
• The output shall be integer numbers each printed with a %5d format, 12 per output line.


 */

#include <stdio.h>
#include <stdlib.h>

#define bool	unsigned char
#define	false	(unsigned char) 0
#define true	(unsigned char) 1

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

//Item *front = NULL;
//Item *end = NULL;        // Pointers to front and end queue elements
//int count = 0;            // Number of items in queue

//bool qempty (void)
//// Returns true if queue is empty
//{
//    return count==0;
//}//qempty()

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


//bool qremove (int *n, queue *pqueue)
//// Remove first value from front of queue
//{
//    bool	result = false;
//    // Check if there is anything to remove
//    if (pqueue->front != 0)	{
//        // There is data to remove
//        Item	*ptmp = pqueue -> front;		// pointer to first element
//        *n = pqueue -> front->value;			// give value to caller
//        pqueue -> front = pqueue ->front->next;		// move front pointer to next item
////        count--;					// reduce queue count
//        free (ptmp);				// give back memory
//        // Did we just remove last item from queue?  If so, must adjust
//        // end pointer
//        if (pqueue->front == NULL)	pqueue->end = NULL;
//        result = true;
//    }
//    return result;
//}//qremove()


//void qprint (queue *pqueue, queue p)
//// Print all contents of array - primarily used for debugging purposes
//{
//    Item	*pv;
//    int		k = 0;		// "Index" in queue - makes output match array
//    // implementation
//    pv = pqueue -> front;
//    while (pv != NULL)	{
//        printf ("%d", k, pv->value);
//        pv = pv->next;
//        k++;
//    }
//    putchar('\n');
//}//qprint()

void printList(queue *pqueue)
{
    Item *pv = pqueue -> front;

    int count =1;

    while(pv)
    {

        printf("%5d",pv->value);
        pv = pv->next;

        if (count % 12 == 0){
            printf("\n");
        }

        count ++;

    }
}


int main()
{
    int n=0;
    queue q1;
    queue q2;
    queue q3;
    queue q4;

    createQueue(&q1);
    createQueue(&q2);
    createQueue(&q3);
    createQueue(&q4);

    printf("insert numbers\n");
    while (1){
        scanf ("%d", &n);
        if(n<0){
            break;
        }
        else if (n%4 ==0){
            // queue q1 qinsert;
            qinsert(&q1, n);

        }
        else if (n%4==1){
            qinsert (&q2, n);

        }
        else if (n%4 ==2){
            qinsert (&q3, n);

        }
        else if (n%4 == 3){
            qinsert(&q4, n);
        }
        else {
            continue;
        }

    }


    printf ("print inputted integers\n");
    printList(&q1);
    printf("\n");
    printList(&q2);
    printf("\n");
    printList (&q3);
    printf("\n");
    printList(&q4);

    return 0;
}

