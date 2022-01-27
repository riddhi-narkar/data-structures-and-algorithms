#include <iostream>
using namespace std;
 

void foo (int a[])
{
    a[1] = 5;
} 

int main()
{
    int t[] = {1, 2, 3, 4};
 
    foo(t);

    cout << t[0] + t[1] << endl;

    return 0;
}