#include<stdio.h>

#define Max 3
int queue[Max];
int front = -1, rear = -1;
void enqueue();
void dequeue();
void peek(); 
void display();

void enqueue()
{   
    if (rear == Max - 1)
        printf("\nQUEUE OVERFLOW\n");
    
    else 

    {   int data;
        printf("Enter value to be enqueued: ");
        scanf("%d", &data);
    
        if (front == -1 && rear == -1)
        {
            rear = 0 ;
            front = 0;
        }
        
        else
            rear += 1;
     
        queue[rear] = data;
    }
}

void dequeue()
{
    if(front == -1 || front>rear)
        printf("\nQUEUE UNDERFLOW\n");
    
    else
    {
        int data = queue[front];
        front += 1;
        printf("\n%d is deleted", data);
    }
}

void peek()
{
    if(front == -1 || front>rear)
        printf("\nQUEUE UNDERFLOW");

    else
        printf("\nFront is %d", queue[front]);
    
}

void display()
{
    if(front>rear || front == -1)
        printf("\nQUEUE UNDERFLOW\n");
    
    else
        for(int i = front; i<=rear; i++)
            printf("\n%d", queue[i]);
}

int main()
{
    int opt;
   do
   {
        printf("\n");
        printf("\n ~ ~ ~ ~ ~ ~ QUEUE OPERATIONS ~ ~ ~ ~ ~ ~ \n");
        printf("\n1) Enqueue");
        printf("\n2) Dequeue");
        printf("\n3) Peek");
        printf("\n4) Display");
        printf("\n5) Exit");
        printf("\nEnter your desired option number: ");
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
            printf("\nInvalid input, retry\n");
        }
     
     } while(opt != 5);

    return 0;
}