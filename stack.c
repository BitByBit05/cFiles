#include <stdio.h>
#include <stdlib.h>

struct stack{
    int totalSize; 
    int top;
    int *arr;
};
int isStackFull(struct stack *ptr);
int isStackEmpty(struct stack *ptr);
//function to display stack
void displayStack(struct stack *ptr){
    printf("\n -----Printing The Stack: -----\n");
    if(isStackEmpty(ptr)){//returns if the stack is empty!
        printf("Stack Empty");
        return;
    }
    for (int i = 0; i <= ptr->top; i++){
        printf("%d \t", ptr->arr[i]);
    }
    printf("\n");
}
//function to check for stackoverflow
int isStackFull(struct stack *ptr){
    if(ptr->top == ptr->totalSize - 1)
        return 1;
    else
        return 0;
}
//function to check for stack underflow
int isStackEmpty(struct stack *ptr){
    if(ptr->top == -1)
        return 1;
    else 
        return 0;
}

void stackPush(struct stack *ptr){
    printf("Enter the data: ");
    int data;
    scanf("%d", &data);
    if (isStackFull(ptr)){
        printf("Stack Overflow! \n");
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top] = data;
    printf("Stack Push Successfull: \n");
    char decide;
    printf("Do you want to continue pushing? 'y' for yes, 'n' for no: \n");
    scanf("%c", &decide);
    if (decide == 'y'){
        stackPush(ptr);
    }
    
}

int main(){
    struct stack *s;
    s->top = -1;
    s->totalSize = 10;
    s->arr = (int *)malloc(s->totalSize * sizeof(int));
    
    //Check if stack is empty
    if (isStackEmpty(s))
        printf("The stack is Empty! \n");
    else
        printf("The stack isn't Empty! \n");
    
    //Check if stack is full
    if (isStackFull(s))
        printf("The stack is Full! \n");
    else
        printf("The stack isn't Full! \n");
    
    stackPush(s);
    displayStack(s);
    return 0;
}