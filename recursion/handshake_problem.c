#include<stdio.h>

int handshakes(int);

int handshakes(int h)
{
    if(h<=1)
    return -1;

    else
    {
        if(h == 2)
        return 1;

        else
        return (handshakes(h-1) + (h-1));
    }
}

int main()
{
    float n;
    int flag;
    printf("\nLET'S SOLVE THE HANDSHAKE PROBLEM!!!\n");
    printf("\nRULES:-");
    printf("\n1) There are n people in a room. \n2) Each person shakes hands once with every other person.\n3) Find the total number of handshakes\n");
    printf("\nTry to figure out and check your answers here!!\n");
    
    do
    {
        printf("\nEnter the value of n: ");
        scanf("%f", &n);
        float op = handshakes((int)n);
    
        if(op == -1)
        {
            printf("\nThat's absurd for count of people for handshakes :(\n");
            printf("\nPress 1 to repeat and 0 to end\n");
            scanf("%d", &flag);
        }
    
        else
        {
            printf("Number of handshakes done for %d people are %d\n", (int)n, (int)op);
            printf("\nPress 1 to repeat and 0 to end\n");
            scanf("%d", &flag);
        }
    
    } while(flag == 1);

    return 0;
}