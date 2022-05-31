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
    int Class = 0;
    int variable = 0;
    int parameter = 0;
    int method = 0;
    string mdata, vdata, paramdata;
    string className;
    ifstream input("output.txt");
    while (getline(input, temp))
    {
        int found2 = temp.find("Identifier");
        counter++;
        if (Class == 1 && found2 != string::npos)
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

        int found1 = temp.find("MethodDeclaration");

        if (found1 != string::npos)
        {
            method = counter;
        }

        if (method != 0 && (counter - method) == 2)
        {
            mdata = temp;
            // cout << "Mdata" << mdata << endl;
        }

        if (method != 0 && found2 != string::npos)
        {
            SymbolTable *methSym = new SymbolTable();
            table->insertTable(methSym);
            methSym->insertRecord("Method", mdata, split(temp));
            methSym->insertName(className);
            className = split(temp);
            method = 0;
        }

        int found3 = temp.find("VarDeclaration");
        if ((found3 != string::npos))
        {
            variable = counter;
        }

        if (variable != 0 && (counter - variable) == 1)
        {
            vdata = temp;
        }

        if (variable != 0 && found2 != string::npos)
        {
            SymbolTable *varSym = new SymbolTable();
            table->insertTable(varSym);
            varSym->insertRecord("Variable", vdata, split(temp));
            varSym->insertName(className);
            variable = 0;
        }

        int found13 = temp.find("ParameterList");
        if ((found13 != string::npos))
        {
            parameter = counter;
        }

        if (parameter != 0 && (counter - parameter) == 1)
        {
            paramdata = temp;
        }

        if (parameter != 0 && (counter - parameter == 2))
        {
            SymbolTable *varSym = new SymbolTable();
            table->insertTable(varSym);
            varSym->insertRecord("Variable", paramdata, split(temp));
            varSym->insertName(className);
            parameter = 0;
        }
    }
    input.close();
}

string leftrightsplit(string string_to_split, char sepearator, bool bleft)
{
    int count = 0;
    string right, left = "";
    for (int i = 0; i < string_to_split.length(); i++)
    {
        if (string_to_split[i] == sepearator)
        {
            count = 1;
            i++;
        }
        if (count == 0)
            left = left + string_to_split[i];
        else
            right = right + string_to_split[i];
    }
    if (bleft)
    {
        return left;
    }
    else
        return right;
}

void makeTAC(SymbolTable *table)
{
    ifstream input("output.txt");
    int counter, x, stLabel, method = 0;
    int label = 0;
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
        int found0 = temp.find("MethodDeclaration");
        counter++;

        if (found0 != string::npos)
        {
            method = counter;
        }

        if (method != 0 && (counter - method) == 3)
        {
            mdata = split(temp);
            // cout << "Method Declaration " << mdata << endl;
        }

        // End Get Method

        // Get inside Scope of the method
        int found1 = temp.find(":{");
        if (found1 != string::npos && mdata != "")
        {
            count++;
        }

        int found2 = temp.find("StatementList:");
        if (found2 != string::npos && count > 0)
        {
            start = 1;
        }
        if (start == 1)
        {
            int found5 = temp.find("while");

            if (found5 != string::npos)
            {
                whstate = counter;
            }

            if ((counter - whstate) >= 3 && (counter - whstate) < 7)
            {
                string res = split(temp);
                wh1 = wh1 + res;
            }
            int found4 = temp.find("Statement");

            if (found4 != string::npos)
            {
                state = 1;
            }

            int found1 = temp.find("AssignmentStatement");

            if (found1 != string::npos)
            {
                x = 1;
                // cout << "Label: " << label << endl;
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
                // cout << txt;
                // cout << "Scope Name: " << mdata << endl;

                cout << txt << endl;
                string lhs = leftrightsplit(txt, '=', true);
                string op = "";
                string rhs = leftrightsplit(txt, '=', false);
                if (txt.find("+") != string::npos)
                    op = "+";
                if (txt.find("-") != string::npos)
                    op = "-";
                if (txt.find("*") != string::npos)
                    op = "*";
                if (txt.find("/") != string::npos)
                    op = "/";
                string lValue = leftrightsplit(rhs, op[0], true);
                string rValue = leftrightsplit(rhs, op[0], false);
                string dlType = table->check(table, lhs, mdata);
                dlType = split(dlType);

                string drType = table->check(table, lhs, mdata);
                drType = split(drType);

                string drhType = table->check(table, lhs, mdata);
                drhType = split(drhType);

                if (drType.compare(drhType) != 0)
                {
                    cout << "Type Error: Plese Check Your Data Types " << endl;
                }
                txt = "";
            }

            if (x == 1)
            {
                string res = split(temp);
                if (res == "")
                    continue;
                if (res == "+")
                    res = " + ";
                if (res == "-")
                    res = " - ";
                if (res == "*")
                    res = " * ";
                if (res == "/")
                    res = " / ";
                if (res == "Equals to")
                    res = " = ";
                txt = txt + res;
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
    BBlock *root = NULL;
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
            expr = expr + res;
        }
    }
    root->generatetac();
    input.close();
}