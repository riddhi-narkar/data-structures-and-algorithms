#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

// global variable declaration

# define Max 50
char stck[Max];
int top = -1;

// function declaration

void push (char [], char);
char pop (char []);
void conversion(char [], char []);
int priority(char);

//priority function definition

int priority (char x)
{
    if(x == '^')
    return 2;
    
    else if(x == '*' || x == '/' || x == '%')
    return 1;

    else if (x == '+' || x == '-')
    return 0;

    else
    return 0; 
}

//push function definition

void push(char stck[], char data)
{
    if(top == Max-1)
        printf("\nSTACK OVERFLOW\n");

    else 
    {
        top += 1;
        stck[top] = data;
    }
}

//pop function definition

char pop(char stck[])
{
    if(top == -1)
    {
        printf("\nSTACK UNDERFLOW\n");
        return 0;
    }
    
    else
    {
        char data = stck[top];
        top -= 1;
        return data;
    }
}

//conversion function definition

void conversion(char source[], char final[])
{
    int i = 0, j = 0;
    char temp;
    strcpy (final, "");

    while(source[i] != '\0')
    {
        if(source[i] == '(')
        {
            push(stck, source[i]);
            i += 1;
        }

        else if(source [i] == ')')
        {
            while((top != -1) && (stck[top]!= '('))
            {
                final[j] = pop(stck);
                j += 1;
            }

            if(top == -1)
            {
                printf("\nINCORRECT EXPRESSION\n");
                exit(0);
            }

            temp = pop(stck);
            i += 1;
        }

        else if (isdigit(source[i]) || isalpha(source[i]))
        {
            final[j] = source[i];
            j += 1;
            i += 1;
        }

        else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%' || source[i] == '^')
        {
            while((top != -1) && (stck[top] != '(') && (priority (stck[top]) >= priority(source[i])) )
            {
                final[j] = pop(stck);
                j += 1;
            }

            push (stck, source[i]);
            i += 1;
        }

        else
        {
            printf("\nINCORRECT EXPRESSION\n");
            exit(0);
        }
    }

    while((top != -1) && (stck[top] != '('))
    {
        final[j] = pop(stck);
        j += 1;
    }

    final[j] = '\0';
}

//main

int main()
{
    char infix[Max], postfix[Max];
    printf("\n");
    printf("\nEnter an infix expression: ");
    scanf("%s", infix);

    strcpy(postfix, "");
    conversion(infix, postfix);
    printf("\nPostfix expression: %s\n", postfix);
    return 0;
}