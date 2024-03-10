//This is the implementation file stack.cpp.
//This is the implementation of the class Stack.
//The interface for the class Stack is in the header file stack.h.
#include <iostream>
#include <cstddef>
#include "stack.h"
using namespace std;
using namespace stacksavitch;

namespace stacksavitch
{
    //Uses cstddef:
    Stack::Stack( ) : top(NULL)
    {
        //Body intentionally empty.
    }

    Stack::Stack(const Stack& aStack){
        //<The definition of the copy constructor is Self-Test Exercise 11.>
    }

    Stack::~Stack( )
    {
    char next;
    while (! empty( ))
    next = pop( ); //pop calls delete.
    }

    //Uses cstddef:
    bool Stack::empty( ) const
    {
    return (top == NULL);
    }

    void Stack::push(char theSymbol)
    {
        StackFramePtr newFrame = new StackFrame;
        newFrame->data = theSymbol;
        newFrame->link = top;
        top = newFrame;
    }
    
    //Uses iostream and cstdlib:
    char Stack::pop( )
    {
    if (empty( ))
    {
        cout << "Error: popping an empty stack.\n";
        exit(1);
    }
    char result = top->data;

    StackFramePtr tempPtr;
    tempPtr = top;
    top = top->link;

    delete tempPtr;

    return result;
    }
}//stacksavitch



int main( ) 
{
    Stack s; 
    char next, ans;  
    do  
    {  
        cout << "Enter a word: ";  
        cin.get(next);  
        while (next != '\n' )  
        {  
            s.push(next);  
            cin.get(next);  
        }  

        cout << "Written backward that is: ";  
        while (!s.empty())  
            cout << s.pop();  
        cout << endl ;  
        cout << "Again?(y / n): ";  
        cin >> ans;  
        cin.ignore(10000, '\n') ;  
    }while (ans != 'n' && ans != 'N');  

    return 0;  
}