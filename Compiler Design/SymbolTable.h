#include <map>
#include <list>
#include <iostream>
#include "Helpers.h"
using namespace std;

class TableNode
{
public:
    string type;
    string value;
    string scope;
    TableNode() {}
    TableNode(string type, string value, string scope)
    {
        this->scope = scope;
        this->type = type;
        this->value = value;
    }
};

class SymbolTable
{
private:
    // using hashmap of strings as key and TableNode as an object
    list<Node *> record;

public:
    list<SymbolTable *> table;
    // insert a new table with given key value pairs
    void changeScope(SymbolTable *n)
    {
        this->table.push_back(n);
    }

    void insert(Node *h)
    {
        this->record.push_back(h);
    }

    // look up the given variable name in the given scope
    // bool lookup(string variableName)
    // {
    //     if (table.find(variableName) != table.end())
    //     {
    //         return true;
    //     }
    //     return false;
    // }

    // void modify(string scope, string variableName, string value, string type)
    // {
    //     // modify the existing variable
    //     if (table.find(variableName) != table.end())
    //     {
    //         table.find(variableName)->second->scope = scope;
    //         table.find(variableName)->second->type = type;
    //         table.find(variableName)->second->value = value;
    //     }
    //     else
    //     {
    //         cout << "Error " << variableName << "Not Found " << endl;
    //     }
    // }

    void print_table()
    {
        cout << this->record.size() << endl;
        for (auto i = this->record.begin(); i != this->record.end(); i++)
        {
            cout << "Type is :" << (*i)->type << endl;
            cout << "Value is :" << (*i)->value << endl;
        }
    }
};
