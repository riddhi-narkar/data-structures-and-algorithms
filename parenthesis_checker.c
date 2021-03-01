#include<stdio.h>
#include<string.h>

//global variables 
# define max 30
static int top = -1;
int stck[max];

//function declarations
char pop();
void push(char);


//push function definition
void push(char x)
{ 
    if (top == (max-1) )
    printf("\nSTACK OVERFLOW\n");

    else
    {
        top += 1;
        stck[top] = x;
    }
}


//pop function definition
char pop()
{
    if (top == -1)
    return -1;
        
    else
    return stck[top--];
}

//main function
int main()
{
    char temp, flag = 1;
    char ex[max];

    printf("\nEnter your expression: \n");
    scanf("%s", ex);
     
    for(int i=0; i<strlen(ex); i++)
    {
        if(ex[i] == '(' || ex[i] == '[' || ex[i] == '{') 
        push(ex[i]);
        
        if(ex[i] == ')' || ex[i] == ']' || ex[i] == '}') 
        {
            if(top == -1)
            flag = 0;
  
            else
            {
                temp = pop();

                if(temp == -1)
                printf("\n STACK UNDERFLOW");

                else if( ex[i] == ')' && (temp == '[' || temp == '{') )
                flag = 0;

                else if( ex[i] == ']' && (temp == '(' || temp == '{') )      
                flag = 0;

                else if( ex[i] == '}' && (temp == '[' || temp == '(') )
                flag = 0;  
                
            }
        }
                 
    }

    if(top >= 0)
    flag = 0;

    if(flag == 1)
    printf("\nVALID EXPRESSION\n");

    else
    printf("\nINVALID EXPRESSION\n");

    return 0;
}