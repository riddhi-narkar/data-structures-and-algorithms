#include<math.h>

unsigned long long parent(unsigned long long i)
{
    return floor(i/2);
}

unsigned long long left(unsigned long long i)
{
    return 2*i;
}

unsigned long long right(unsigned long long i)
{
    return (2*i)+1;
}

void max_heapify(int a[], int index)
{
    int largest, size = sizeof(a)/sizeof(a[0]);
    int l = left(index);
    int r = right(index);

    if(l <= size && a[l] < a[index])
        largest = l;

    else
        largest = index;

    if( r <= size && a[r] > a[largest])
        largest = r;

    if(largest != index)
    {
        int temp = a[index];
        a[index] = a[largest];
        a[largest] = temp;

        max_heapify(a, largest);
    }

}