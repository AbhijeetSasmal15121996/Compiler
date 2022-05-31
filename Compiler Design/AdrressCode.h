#ifndef __adresscode_h__
#define __adresscode_h__

#include <iostream>
#include <vector>
using namespace std;
class TAC
{
private:
    string op, lhs, rhs, result;

public:
    TAC() {}
    TAC(string op, string lhs, string rhs, string result)
    {
        this->op = op;
        this->lhs = lhs;
        this->rhs = rhs;
        this->result = result;
    }

    void dump()
    {
        printf("%s = %s %s %s", this->result, this->lhs, this->op, this->rhs);
    }

    void printTac(ofstream *stream, int number)
    {
        // todo : get the bytecode here and store it in a file and when the interpretation just read file
        string initial = "n" + to_string(number);
        string one = this->lhs + "\\n";
        string two = "=";
        string three = this->rhs + "\\n";
        string four = this->op + "\\n";
        string five = "result\\n";
        *stream << initial << " [label=\"" << one << two << three << four << five << "\"];";
    }

    void setOp(string op)
    {
        this->op = op;
    }

    void setLhs(string lhs)
    {
        this->lhs = lhs;
    }

    void setRhs(string rhs)
    {
        this->rhs = rhs;
    }

    void setResult(string result)
    {
        this->result = result;
    }

    string getOp()
    {
        return this->op;
    }

    string getLhs()
    {
        return this->lhs;
    }

    string getRhs()
    {
        return this->rhs;
    }

    string getResult()
    {
        return this->result;
    }
};

class BBlock
{
private:
    void generate(ofstream *output)
    {
        *output << "graph [ splines = ortho ]" << endl;
        *output << "node [shape = box];" << endl;
        for (auto i = 0; i < tacInstructions.size(); i++)
        {
            tacInstructions[i]->printTac(output, i);
            string final = "\nn" + to_string(i) + " ->" + " n" + to_string(i + 1) + "\n";
            *output << final;
        }
    }

public:
    string name;
    vector<TAC *> tacInstructions;
    TAC condition;
    BBlock *trueExit, *falseExit;
    BBlock() : trueExit(NULL), falseExit(NULL) {}
    void generatetac(void)
    {
        ofstream output("tac.dot");
        output << "digraph G {" << endl;
        generate(&output);
        output << "}" << endl;
        output.close();
    }

    void add(TAC *tac)
    {
        this->tacInstructions.push_back(tac);
    }
};

#endif
