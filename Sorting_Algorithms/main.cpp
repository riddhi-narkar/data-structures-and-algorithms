#include "selection_sort.cpp"
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> v [1, 5, 3, 68, 6, 94, 9, 87, 2, 4567, 24, 864, 22, 56 ,25, 686];
    selection(v);
    for(auto it:v)
        cout << it << endl;
}
