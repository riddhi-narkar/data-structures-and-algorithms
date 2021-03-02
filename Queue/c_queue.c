#include<stdio.h>

// GLOBAL VARIABLES DECLARATION
#define Max 5
int queue[Max];
int front = -1;
int rear = -1;

// FUNCTION DECLARATION
void enqueue();
void dequeue();
void peek();
void display();

void enqueue()
{    
    if( (front == 0 && rear == Max -1 )|| (rear == front -1) )
        printf("\nQUEUE OVERFLOW\n");

    else
    {
        int data;
        printf("\nEnter data: ");
        scanf("%d", &data);

        if( rear == -1 && front == -1 )
        {
            rear = 0; 
            front = 0;
        }

        else if(rear == Max-1) 
            rear = 0;

        else 
            rear += 1;

        queue[rear] = data;
    }
}

void dequeue()
{
    if( (front == -1 && rear == -1) || (front > rear) )
        printf("\nQUEUE UNDERFLOW\n");
        
    else
    {
        int temp = queue[front];
        printf("\n%d is deleted from queue\n", temp);

        if(front == rear)
        {
            front = -1;
            rear = -1;
        }

        else if(front == Max - 1)
            front = 0;

        else
            front += 1;
    }
}

void peek()
{
    if(front == -1 && rear == -1)
        printf("\nEMPTY QUEUE\n");

    else
        printf("\n%d\n", queue[front]);
}

void display()
{
    if(front == -1 && rear == -1)
        printf("\nEMPTY QUEUE\n");
    
    else if(front < rear)
        for(int i = front; i <= rear; i++)
            printf("\n%d", queue[i]);
    
    else
    {
        for (int i = front; i <= Max-1; i++ )
           printf("\n%d", queue[i]);

        for (int i = 0; i <= rear; i++)
            printf("\n%d", queue[i]);
    }
}

int main()
{
    int opt;
    do
    {
        printf("\n1) Enqueue\n");
        printf("2) Dequeue\n");
        printf("3) Peek\n");
        printf("4) Display\n");
        printf("5) Exit\n");
        printf("\nDesired option number: ");
        scanf("%d", &opt);

        switch(opt) 
        {
            case 1: 
            enqueue();
            break;

            case 2: 
            dequeue();
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
            printf("\nINVALID INPUT TRY AGAIN\n");
        }
    } while(opt != 5);
    return 0;
}