#include<stdio.h>

int gcd(int, int);

int gcd(int a, int b)
{
    if(a%b == 0)
    return b;

    else 
    return (gcd(b, a%b));
    
}

int main()
{
    int a, b, ans;
    printf("\nEnter two numbers to find gcd: \n");
    scanf("%d%d", &a, &b);
    printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
    return 0;
}