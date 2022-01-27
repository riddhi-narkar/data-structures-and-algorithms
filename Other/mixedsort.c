#include<stdio.h>

// FUNCTION DEFINITION

void swap(int* x, int* y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void print(int n, int s, int a[n])
{
    printf("\nThe array after sort %d is: \n", s);

    for(int i = 0; i<n; i++)
        printf("\t%d", a[i]);
    
    printf("\n");
}

//________________________________________________________________________________________________________________________________

int main()
{
    int n;
    printf("\nEnter size of the array followed by its elements: ");
    scanf("%d", &n);

    int mid = n/2;
    //printf("%d is the mid:\n", mid);

    int a[n];
    for(int i = 0; i<n; i++)
        scanf("%d", &a[i]);
    
    //  applying selection sort to the first half of the array
    //  SELECTION SORT:
    //    -> works by selecting the largest(or smallest) value from an array and placing it to its correct position
    //    -> has no best or the worst case for a significantly huge array, we study the average case for time complexity

    for(int i = 0; i<mid-1; i++)
    {
        int element = i;

        for(int j = i+1; j<mid; j++)
            if(a[element] > a[j])
                element = j;
        // In this for loop, we are choosing one element, and by comparing it with all the remaining elements, 
        // we place the element at its correct position.

        // we try to give the smallest value to our element pointer, and in the code below, we swap our element
        // with the outer for loop iterator, which is actually, its correct position.

        if(element != i)
            swap(&a[element], &a[i]);

        // print(n, i, a);
        // printf("end of selection\n");
    }

    print(n, 1, a);

    // applying insertion sort to the remaining half of the array
    // INSERTION SORT: 
    //    ~ works by maintaining a small sorted subarray
    //    ~ with every iteration, we keep adding one element to this sorted subset

    for(int i = mid+1; i<n; i++)
    {
        int pos = i;

        while(pos!= mid && a[pos] < a[pos-1])
        {
            swap(&a[pos], &a[pos-1]);
            pos -= 1;
        }
        
        // print(n, i, a);
        // printf("end of insertion\n");
    }

    print(n, 2, a);

    //  applying bubble sort to this resulting array
    //  BUBBLE SORT: 

    for(int i = 0; i < n-1; i++)
    {
        for(int p = 0; p < n-1-i; p++)
            if(a[p]>a[p+1])
                swap(&a[p], &a[p+1]);
    }

    printf("\nThe array now has been completely sorted using 3 sorting algorithms :)\n");
    print(n, 3, a);
    printf("\n");

    return 0;
}