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

class Equation {
    private:
        vector<string> *left;
        vector<string> *right;
        string name;
    
    void getLeft(){
        return this->left;
    }

    void getRight(){
        return this->right;
    }

    void getName(){
        return this->name;
    }

    vector setLeft(string x){
        this->left->push_back(x);
    }

    vector setRight(string x){
        this->right->push_back(x);
    }

    string setName(string x){
        this->name = x;
    }

}


vector getEquation(void)
{
    ifstream input("output.txt");
    string temp,mdata;
    int x,xd = 0;
    int q,method = 0;
    vector<Equation> eq;
    Equation *qs = NULL;
    while (getline(input, temp))
    {
        int found0 = temp.find("Method Declaration");
        counter++;
        if (found0 != string::npos)
        {
            method = counter;
        }

        if (method != 0 && (counter - method) == 2)
        {
            mdata = temp;
        }

        if (method != 0 && (counter - method) == 3)
        {
            mdata = split(temp);
        }


        int found1 = temp.find("Equation");


        if (found1 != string::npos)
            x = 1;
        int found = temp.find(";");
        if (found != string::npos){
            qs->setName(mdata);
            eq.push_back(qs);
            qs = NULL;
            x = 0;
        }
        if (x == 1)
        {
            if (qs == NULL)
                qs = new Equation();
            cout << temp << endl;
            int found3 = temp.find("Equals to");
            if(found3 != string:npos) {
                q = 1;
                xd = 0;
                continue;
            }
            if (q == 0 && xd != 0 ){
                
                qs->setLeft(split(temp))
            } else if(q == 1 && xd != 0){
                qs->setRight(split(sum));
            }
            xd++;
        }
    }
    input.close();
    return eq;
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