//
// Created by LG on 2022-10-11.
//
//
// Created by LG on 2022-10-11.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void push (char);
void pop ();
int top =-1;
char expression [100];
char stack [100];

int main(){
    printf("enter expression:\n");
    scanf ("%s", &expression);

    for (int i = 0; expression[i]!='\0'; i++){
        if (expression[i] == '(' ){
            push (expression [i]);
        }
        else if(expression[i] == "{"){
            push (expression [i]);
        }
        else if (expression[i] == "["){
            push (expression [i]);
        }
        else if (expression[i] == ')'){
            pop();
        }
        else if (expression[i] == "}"){
            pop ();
        }
        else if (expression[i] == "]"){
            pop ();
        }
    }

    if (top == -1){
        printf("balanced : 1");
    }
    else {
        printf ("not balanced : 0");
    }

    return 0;

}

void push (char expression){
    top = top + 1;
    stack [top] = expression ;
    //return 1;
    return;
}

void pop (){
    top = top -1;
    return;
}
