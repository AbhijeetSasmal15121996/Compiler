#include <iostream>
#include "AdrressCode.h"

using namespace std;

SymbolTable *table = new SymbolTable();

string split(string string_to_split)
{
    int count = 0;
    string t = "";
    for (int i = 0; i < string_to_split.length(); i++)
    {
        if (string_to_split[i] == ':')
        {
            count = 1;
            i++;
        }
        if (count == 0)
            continue;
        else
            t = t + string_to_split[i];
    }
    return t;
}

void write(Node *root, ofstream *ofstream)
{
    string id = to_string(root->id);
    string type = root->type;
    string value = root->value;
    *ofstream << type << ":" << value << endl;
    for (auto i = root->children.begin(); i != root->children.end(); i++)
    {
        write((*i), ofstream);
    }
}

void read(void)
{
    string temp;
    int counter = 0;
    int Class, method, variable = 0;
    string mdata, vdata;
    string className;
    ifstream input("output.txt");
    while (getline(input, temp))
    {
        counter++;
        if (Class == 1)
        {
            SymbolTable *tmp = new SymbolTable();
            table->insertTable(tmp);
            tmp->insertRecord("Class", "Class", split(temp));
            tmp->insertName("Program");
            className = split(temp);
            Class = 0;
        }

        int found = temp.find("CLASS");

        if ((found != string::npos))
        {
            Class = 1;
        }

        int found1 = temp.find("Method Declaration");

        if (found1 != string::npos)
        {
            method = counter;
        }

        if (method != 0 && (counter - method) == 2)
        {
            mdata = temp;
        }

        if (method != 0 && (counter - method) == 3)
        {
            SymbolTable *methSym = new SymbolTable();
            table->insertTable(methSym);
            methSym->insertRecord("Method", mdata, split(temp));
            methSym->insertName(className);
            className = split(temp);
        }

        int found2 = temp.find("Variable Declaration");
        if (found2 != string::npos)
        {
            variable = counter;
        }

        if (variable != 0 && (counter - variable) == 1)
        {
            vdata = temp;
        }

        if (variable != 0 && (counter - variable) == 2)
        {
            SymbolTable *varSym = new SymbolTable();
            table->insertTable(varSym);
            varSym->insertRecord("Variable", vdata, split(temp));
            varSym->insertName(className);
        }
    }
    input.close();
}

void getEquation(void)
{
    ifstream input("output.txt");
    string temp;
    int x = 0;
    while (getline(input, temp))
    {
        int found1 = temp.find("Equation");
        if (found1 != string::npos)
            x = 1;
        if (x == 1)
        {
            cout << temp << endl;
        }
        int found = temp.find(";");
        if (found != string::npos)
            x = 0;
    }
    input.close();
}

/**
 * @brief
 *
 *  if "a = a + 6" in the program i need the left side variable and the operator and the right side
 *  varible and the operator on the right hand side
 *  there is no library for bytecode genearation i need to write from scratch and the interpreter also
 *  please write this one for me
 *                                - Vamsi
 */