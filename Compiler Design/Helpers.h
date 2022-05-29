#include <iostream>

using namespace std;

SymbolTable *table = new SymbolTable();

stack<string> callStack;

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
            // cout << "hello" << endl;
            method = counter;
        }

        if (method != 0 && (counter - method) == 2)
        {
            mdata = temp;
        }

        if (method != 0 && (counter - method) == 3)
        {
            cout << mdata << endl;
            cout << split(temp) << endl;
            SymbolTable *methSym = new SymbolTable();
            table->insertTable(methSym);
            methSym->insertRecord("Method", mdata, split(temp));
            methSym->insertName(className);
            className = split(temp);
        }

        int found2 = temp.find("Variable Declaration");
        if (found2 != string::npos)
        {
            // cout << "hello" << endl;
            variable = counter;
        }

        if (variable != 0 && (counter - variable) == 1)
        {
            vdata = temp;
        }

        if (variable != 0 && (counter - variable) == 2)
        {
            cout << vdata << endl;
            cout << split(temp) << endl;
            SymbolTable *varSym = new SymbolTable();
            table->insertTable(varSym);
            varSym->insertRecord("Variable", vdata, split(temp));
            varSym->insertName(className);
        }
    }
    input.close();
}