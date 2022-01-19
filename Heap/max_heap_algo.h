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

void max_heapify(int a[], int size, int index)
{
    int largest;
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

        max_heapify(a, size, largest);
    }

}

void build_max_heap(int a[], int size)
{
    for(int i = floor(size/2); i>=0; i--)
        max_heapify(a, size, i);
}

void heapsort(int a[], int size)
{
    build_max_heap(a, size);

    for(int i = size; i>0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = a[0];

        size -= 1;
        max_heapify(a, size, 0);
    }
}