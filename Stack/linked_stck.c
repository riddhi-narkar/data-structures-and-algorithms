#include<stdio.h>
#include<stdlib.h>

// STRUCTURE DEFINITION
struct node
{
    int data;
    struct node* next;
};

struct node* create_node(int);
void push();
void pop();
void peek();
void display();

struct node *newnode, *temp, *top = NULL;

struct node* create_node(int val)
{
    newnode = (struct node *)malloc(sizeof(struct node));
     
    if (newnode == NULL)
    {
        printf("\nMemory cannot be allocated\n");
        return 0;
    }

    else
    {
        newnode->data = val;
        newnode->next = NULL;
        return newnode;
    } 
}

void push()
{
    int val;
    printf("\nEnter value\n");
    scanf("%d", &val);

    newnode = create_node(val);
    if(top == NULL)
    {
        newnode->next = NULL;
        top = newnode;
    }

    else
    {
        newnode->next = top;
        top = newnode;
    }

    printf("\n%d is pushed\n", val);
}

void pop()
{
    if(top == NULL)
        printf("\nUNDERFLOW\n");

    int x = top->data;
    temp = top;
    top = top->next;
    free(temp);

    printf("\n%d is popped\n", x);
}

void peek()
{
    if(top == NULL)
        printf("\nUNDERFLOW\n");
    
    else
        printf("\nTop is %d\n", top->data);
}

void display()
{
    if(top == NULL)
        printf("\nEmpty stack\n");
    
    else
    {
        for(temp = top; temp != NULL; temp = temp->next )
            printf("%d -> ", temp->data);
    }
}

int main()
{
    int opt;
    
    do
    {
        printf("\n");
        printf("\n__________________________________\n");
        printf("\t LINKED STACK\n");
        printf("\n1) Push");
        printf("\n2) Pop");
        printf("\n3) Peek");
        printf("\n4) Display");
        printf("\n5) Exit");
        printf("\n");
        printf("\nEnter your choice number:\t");
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
            printf("\nINVALID CHOICE TRY AGAIN\n");
        }
    } while (opt!=5);
    
    return 0;
}