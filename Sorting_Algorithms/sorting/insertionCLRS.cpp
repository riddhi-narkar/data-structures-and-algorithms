#include<iostream>
using namespace std;
 
 /*

 NOTE:
 DO not use sizeof(arr)/sizeof(arr[0]) to calculate size of arrays.
 Refer: https://www.geeksforgeeks.org/using-sizof-operator-with-array-paratmeters-in-c/

 */

void insertion_sort(int arr[], int size)
{
    int i, j, key;

    for(j = 1; j < size; j++)
    {
        key = arr[j];
        //storing the current element in a variable; so as to be inserted when a correct position is found.

        i = j - 1;

        //now find the correct position for this new element in the sorted subarray

        while(i >= 0 && (arr[i] > key))
        {
            arr[i+1] = arr[i]; 
            /*
            for the first time, this will put the last element of the sorted subarray one position
            outside(that is we are acquiring a new position in the sorted subarray).
            This new position is actually the current element which we are trying to fit in.
            After we find the correct index, we will insert the 'key' in the empty gap thus created in
            this process. (the key was the current element which we saved in the variable "key" earlier)
            */

            i--;
        }

        arr[i+1] = key; //inserted key in it's correct position
    }
}

int main()
{
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    insertion_sort(a, 10);

    for(int i = 0; i < 10; i++)
        cout << "\n" << a[i];

    return 0;
}
