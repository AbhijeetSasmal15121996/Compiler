#include <iostream>
#include <vector>
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

class Equation
{
private:
    vector<string> left;
    vector<string> right;
    string name;

public:
    vector<string> getLeft()
    {
        return this->left;
    }

    vector<string> getRight()
    {
        return this->right;
    }

    string getName()
    {
        return this->name;
    }

    void setLeft(string x)
    {
        this->left.push_back(x);
    }

    void setRight(string x)
    {
        this->right.push_back(x);
    }

    string setName(string x)
    {
        this->name = x;
    }
};

void getEquation(void)
{
    ifstream input("output.txt");
    int counter;
    string temp, mdata;
    int x = 0;
    int method = 0;
    string expr = "";
    while (getline(input, temp))
    {
        int found0 = temp.find("Method Declaration");
        counter++;
        if (found0 != string::npos)
        {
            method = counter;
        }

        if (method != 0 && (counter - method) == 3)
        {
            mdata = split(temp);
        }

        int found1 = temp.find("Equation");

        if (found1 != string::npos)
            x = 1;
        int found = temp.find(";");
        if (found != string::npos && x == 1)
        {
            x = 0;
            expr = expr + "\n";
            cout << expr;
            cout << "Scope Name: " << mdata << endl;
        }
        if (x == 1)
        {
            // cout << temp << endl;
            string res = split(temp);
            if (res == "")
                continue;
            if (res == "Addition")
                res = " + ";
            if (res == "Subtractiom")
                res = " - ";
            if (res == "Multiplication")
                res = " * ";
            if (res == "Division")
                res = " / ";
            if (res == "Equals to")
                res = " = ";
            expr = expr + res;           
        }
    }
    input.close();
}