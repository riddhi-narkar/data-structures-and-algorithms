#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int start1, int start2, int end)
{
    int size1 = start2 - start1 + 1;
    int size2 = end - start2;
    int left[size1], right[size2];

    for(int i = 0; i < size1; i++)
        left[i] = arr[start1 + i];

    for(int i = 0; i < size2; i++)
        right[i] = arr[start2 + i];

    left[size1] = INT_MAX;
    right[size2] = INT_MAX;

    int i = 0, j = 0;

    for(int k = start1; k < end; k++)
    {
        if(left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }

        else
        {
            arr[k] = right[j];
            j++;
        }
    }
}

void merge_sort(int arr[], int start, int end)
{
    if(start < end)
    {
        int partition = ceil(start + ((end - start)/2) );
        merge_sort(arr, start, partition);
        merge_sort(arr, partition, end);
        merge(arr, start, partition, end);
    }
}

int main()
{
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    merge_sort(a, 0, 10);

    for(int i = 0; i<10; i++)
        cout << "\n" << a[i];

    return 0;
}