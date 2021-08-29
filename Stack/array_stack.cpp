#include <iostream>
using namespace std;

// FUNCTION DEFINITIONS

// 1) IS EMPTY OR NOT --------------------------------------------------
bool isEmpty(int stck[], int* top)
{
    return (*top == -1)? true : false;
}


// 2) PUSH ----------------------------------------------------------
void push(int stck [], int* top)
{
    try
    {
        int data;
        cout << "Enter data: " << endl;
        cin >> data;

        top++;
        stck[*top] = data;
    }

    catch(exception e)
    {
        cout << "\nWARNING: Stack overflow. \nFIX: Try popping a value instead.\n" << endl;
    }
}


// 3) POP ---------------------------------------------------------------
int pop(int stck [], int* top)
{
    if(isEmpty(stck, &top) == true)
    {
        cout << "\nWARNING: Stack underflow. \nFIX: Try pushing a value instead.\n" << endl;
        return -1;
    }

    else
    {
        top--; 
        return stck[*top++];
    }
      
}


// 4) PEEK ---------------------------------------------------------------
int peek(int stck[], int* top)
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


void display(int stck[], int* top)
{
    cout << "\nThe stack is: " << endl;

    for(int i = top; i <= 0; i--)
        cout << stck[i] << endl;
}



int main()
{
    int size, choice, top = -1, data;
    bool opt = true;
    char key;

    cout << "Enter max stack size: ";
    cin >> size;
    int stck[size];

    cout << "__________________________________________________________________________________________________\n";

    while(opt)
    {
        cout << "1) Push" << endl;
        cout << "2) Pop" << endl;
        cout << "3) Peek" << endl;
        cout << "4) Display" << endl;
        cout << "5) If empty" << endl;

        cout << endl << "Enter your choice number: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                push(stck, &top);
                break;

            case 2:
                data = pop(stck, &top);
                cout << "The popped element is " << data << endl;
                break; 

            case 3: 
                data = peek(stck, &top);
                cout << "The value of top is " << data << endl;
                break;
            
            case 4: 
                display(stck, &top);
                break;

            case 5: 
                cout << endl;
                string ans = (isEmpty(stck, &top) == true) ? "Empty stack" : "Non-empty stack";
                cout << endl;

        }

        cout << "Press any key to continue and 'n' to stop" << endl;
        cin >> key;

        if(tolower(key) == 'n')
            opt = false;
    }
}