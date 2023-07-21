#include<bits/stdc++.h>
using namespace std;

int GetBit(int number, int position)
{
    /*
    we left shift one to the desired position, then we AND the result with the number

    LEFT SHIFTING: this gives us a binary string with 1 only at the positon which corresponds
    to the positon whose bit we want

    BITWISE AND: this gives us the result we desired (this is the actual bit manipulation we talking about!)

    We return 1 if that's the value, otherwise we simply return 0
    */

    return((number & (1<<position)) != 0);
}

int SetBit(int number, int position)
{
   return(number | (1<<position));
}

int ResetBit(int number, int position)
{
    /*
    1C OPERATOR: ~
    */

    return (number & (~(1<<position)));
}

int UpdateBit(int number, int position, int update_value)
{
    /*
    a combination of ResetBit and SetBit
    For the SetBit part we left shift the update value, which can be either 1 or 0
    */
    number = ResetBit(number, position);
    return(number | (update_value<<position));
}

int main()
{
    cout << "\nGetBit: " << GetBit(4, 1);
    cout << "\nSetBit: " << SetBit(4, 1);
    cout << "\nResetBit: " << ResetBit(4, 1);
    cout << "\nUpdateBit: " << UpdateBit(4, 3, 1) << endl;

    return 0;
}