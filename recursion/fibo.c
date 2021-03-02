#include<stdio.h>

int fibo(int);

int fibo(int a)
{
    if (a == 0)
    return 0;

    else if (a == 1)
    return 1;

    else
    return (fibo(a-2) + fibo(a-1));
}

int main()
{
    int a, ans;
    printf("\nEnter number of terms for fibonacci series: \n");
    scanf("%d", &a);
    
    for(int i=0; i<a; i++)
    {
        ans = fibo(i);
        printf("%d\t", ans);
    }
    
    printf("\n");
    return 0;
}