#ifndef __interpreter_h
#define __interpreter_h
#include <stack>
#include "AdrressCode.h"

using namespace std;

class Interpreter
{
private:
    stack<TAC *> callStack;

public:
    Interpreter() {} // default constructor
    ~Interpreter()   // destructor
    {
        while (!callStack.empty())
        {
            TAC *temp = callStack.top(); // get the top most element
            delete temp;
        }
    }

    void interpret(TAC *item)
    {
        string result = "";
        cout << result << endl;
    }

    void addElement(TAC *item)
    {
        callStack.push(item);
    }

    TAC *getElement()
    {
        return callStack.top();
    }

    void removeElement()
    {
        callStack.pop();
    }

    bool isEmpty()
    {
        return callStack.empty();
    }
};

#endif
