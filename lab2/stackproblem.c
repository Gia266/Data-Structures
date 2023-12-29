
//Stackproblem.c – Lab 02 – Gia, Lee

/*
 * Create a program that reads in characters one at a time, and when the end of line is reached, prints
 * the characters in reverse order
 *
 *
 * • The input shall be one line of characters. You should handle an input of up to 80 characters
 * (plus the newline character at the end of the line).
 * • The output shall be one line of characters – in opposite order to the input
 *
 */
#include <stdio.h>
#include <string.h>

char stack [80];
int top = -1;

// push
int push (char c){
    if (top == 80-1)  return 0; //if it's full

    top = top +1;

    stack[top] = c;
    return  1;
}

// pop
int pop (char c){
    if (top == -1) return 0; // if it has no input

    c =stack [top] ;
    top = top -1;

    printf("%c", c);
    //return 1;
}

int main (){
    char string[80];
    int i;
    printf ("enter one line of characters:\n");
    scanf("%s", &string);

    for (i=0; i<strlen(string); i++){
        push (string[i]);
    }

    printf("reverse for line of characters:\n");
    for (i= 0; i< strlen(string); i++){
        pop (string [i]);
    }
    putchar('\n');

    return 0;
}
