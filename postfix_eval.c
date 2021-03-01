#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

//GLOBAL VARIABLE DECLARATION
#define max 10
float stck[max];
int top = -1;

//FUNCTION DECLARATION
void push(float val);
int pop();
float evaluate(char []);

void push(float val)
{
    if(top == max-1)
        printf("\nOVERFLOW\n");
    
    else
    {
        top++;
        stck[top] = val;
    }
}

int pop()
{
    int val;
    if(top == -1)
        printf("\nUNDERFLOW\n");
    
    else
    {
        val = stck[top];
        top--;
    }

    return val;
}

float evaluate(char exp[max])
{

    int i=0;
    float op1, op2, val;
    
    while(exp[i] != '\0')
    {
        if(isdigit(exp[i]))
            push((float)(exp[i] - '0'));
        
        else
        {
            op2 = pop();
            op1 = pop();

            switch(exp[i])
            {
                case '+': 
                val = op1 + op2;
                break;

                case '-': 
                val = op1 - op2;
                break;

                case '*': 
                val = op1*op2;
                break;

                case '/': 
                val = op1 / op2;
                break;

                case '%': 
                val = (int)op1 % (int)op2;
                break;

                case '^': 
                val = pow(op1, op2); 
                break;
            }

            push(val);
        }

        i++;
    }
    return pop();
}

int main()
{
    char exp[max];
    printf("\nEnter a postfix expression: ");
    scanf("%s", exp);
    
    float x = evaluate(exp);
    printf("\n Value of the postfix expression = %.2f\n", x);

    return 0;
}