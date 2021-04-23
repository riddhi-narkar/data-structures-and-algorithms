#include <iostream>
using namespace std;

void push(int stck [], int top)
{
    try
    {
        int data;
        cout << "Enter data: " << endl;
        cin >> data;
        top++;
        stck[top] = data;
    }

    catch(exception e)
    {
        printf("\nWARNING: Stack overflow. Limit exceeded. Tried pushing at index %d.\nFIX: Try popping a value.\n", top);
    }
}

int pop(int stck [], int top)
{
    try
    {
        int data = stck[top];
        top--; 
        return data;
    }

    catch(exception e)
    {
        printf("\nWARNING: Stack underflow. Tried popping a null stack.\nFIX: Try pushing a value instead.\n");
        return 0;
    }   
}

int peek(int stck[], int top)
{
    try
    {
        int data = stck[top];
        return data;
    }

    catch(exception e)
    {
        printf("\nWARNING: Stack underflow. Tried popping a null stack.\nFIX: Try pushing a value instead.\n");
        return 0;
    }
}

void display(int stck[], int top)
{
    cout << "\nThe stack is: " << endl;

    for(int i = top; i <= 0; i--)
        cout << stck[i] << endl;
}

int main()
{
    int n, choice, top = -1, data;
    bool opt = true;
    char key;
    cout << "Enter max stack size: ";
    cin >> n;
    int stck[n];
    cout << "__________________________________________________________________________________________________\n";

    while(opt)
    {
        cout << "1) Push" << endl;
        cout << "2) Pop" << endl;
        cout << "3) Peek" << endl;
        cout << "4) Display" << endl;

        cout << endl << "Enter your choice number: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                push(stck, top);
                break;

            case 2:
                data = pop(stck, top);
                break;

            case 3: 
                data = peek(stck, top);
                break;
            
            case 4: 
                display(stck, top);
                break;
        }

        cout << "Press any key to continue and 'n' to stop" << endl;
        cin >> key;

        if(key == 'n')
            opt = false;
    }
}