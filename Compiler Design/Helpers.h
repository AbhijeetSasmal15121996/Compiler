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

string split(string string_to_split, char sepearator)
{
    int count = 0;
    string t = "";
    for (int i = 0; i < string_to_split.length(); i++)
    {
        if (string_to_split[i] == sepearator)
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

void makeTAC()
{
    ifstream input("output.txt");
    int counter, label, x, stLabel, method = 0;
    int count = 0;
    int state = 0;
    int whstate = 0;
    int start = 0;
    string txt, wh1, mdata, temp = "";
    BBlock *root = NULL;
    TAC *tac = NULL;
    while (getline(input, temp))
    {

        // Get Method Name
        int found0 = temp.find("Method Declaration");
        counter++;

        if (found0 != string::npos)
        {
            method = counter;
        }

        if (method != 0 && (counter - method) == 3)
        {
            mdata = split(temp);
            cout << "Method Declaration " << mdata << endl;
        }

        // End Get Method

        // Get inside Scope of the method
        int found1 = temp.find(":{");
        if (found1 != string::npos && mdata != "")
        {
            count++;
        }
        // cout << count << endl;
        int found2 = temp.find("List of statement/s:");
        if (found2 != string::npos && count > 0)
        {
            start = 1;
        }
        if (start == 1)
        {
            int found5 = temp.find("While");

            if (found5 != string::npos)
            {
                whstate = counter;
            }

            if ((counter - whstate) >= 4 && (counter - whstate) <= 7)
            {
                string res = split(temp);
                if (res == "less than")
                    res = " < ";
                if (res == "greater than")
                    res = " > ";
                if (res == "Equals to")
                    res = " == ";
                wh1 = wh1 + res;
            }
            int found4 = temp.find("Statement");

            if (found4 != string::npos)
            {
                state = 1;
            }

            int found1 = temp.find("Equation");

            if (found1 != string::npos)
            {
                x = 1;
                cout << "Label: " << label << endl;
                label++;
            }

            if (state == 1 && found1 != string::npos)
            {
                stLabel = label - 1;
                state = 2;
            }

            int found = temp.find(";");

            if (found != string::npos && x == 1)
            {
                x = 0;
                txt = txt + "\n";
                cout << txt;
                cout << "Scope Name: " << mdata << endl;
                txt = "";
            }

            if (x == 1)
            {
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
                txt = txt + res;
                if (root == NULL)
                    root = new BBlock();

                // tac = new TAC(split(txt,''),split(txt,''));
            }

            int found12 = temp.find("}");

            if (found12 != string::npos)
            {
                count--;
                if (state == 2 && count != 0)
                {
                    cout << "if(" << wh1 << endl;
                    cout << "Goto Label: " << stLabel << endl;
                }
            }

            if (count == 0)
            {
                start = 0;
            }
        }
    }
}

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