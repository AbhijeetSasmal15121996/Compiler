#include <map>
#include <list>
#include <iostream>
#include "Helpers.h"

using namespace std;

class SymbolTable
{
private:
    Scope *root;
    Scope *current;

public:
    SymbolTable()
    {
        root = new Scope(NULL);
        current = root;
    }

    void enterScope()
    {
        current = current->nextChild();
    }

    void exitScope()
    {
        current = current->parent();
    }

    void put(string key, Record *item)
    {
        current->put(key, item);
    }

    Record *lookUp(string key)
    {
        return current->lookUp(key);
    }

    void printTable()
    {
        cout << "Size is :" << root->getRecords().size();
        // root->printScope();
    }

    void resetTable()
    {
        root->resetScope();
    }
};
