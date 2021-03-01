#include<stdio.h>
#define m 10

int stck[m];
int top = -1;

void push()
{
    if(top == m-1)
        printf("\nSTACK OVERFLOW\n");
    
    else
    {
        int data;
        printf("\nEnter value to be pushed: \n");
        scanf("%d", &data);
        stck[++top] = data;
        printf("\n%d has been pushed\n", data);
    }
}

void pop()
{
    if(top == -1)
        printf("STACK UNDERFLOW\n");

    else
        printf("\n%d is popped\n", stck[top--]);
}

void peek()
{
    if(top != -1)
        printf("\n%d\n", stck[top]);

    else
        printf("\nSTACK UNDERFLOW\n");
}

void display()
{
    if(top == -1)
        printf("\nEmpty Stack\n");

    else
        for(int i = top; i>=0; i--)
            printf("\n%d\n", stck[i]);
}

int main()
{
    int opt;
    do 
    {
        printf("\n__________________________________________________\n");
        printf("\n\tSTACK OPERATIONS \n");
        printf("\n1) Push\n");
        printf("\n2) Pop\n");
        printf("\n3) Peek\n");
        printf("\n4) Display\n");
        printf("\n5) Exit\n");
        printf("\nEnter your desired option number\n");
        scanf("%d", &opt);

        switch(opt)
        {
            case 1: 
            push();
            break;

            case 2: 
            pop();
            break;

            case 3: 
            peek();
            break;

            case 4: 
            display();
            break;

            case 5: 
            break; 

            default: 
            printf("\nEnter a valid option number\n");
        }

    }
    while(opt!=5);

    return 0;
}