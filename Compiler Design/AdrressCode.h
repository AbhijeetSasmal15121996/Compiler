#ifndef __adresscode_h__
#define __adresscode_h__

#include <iostream>
#include <list>
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
        printf("%s = %s %s %s", result, lhs, op, rhs);
    }

    void printTac(ofstream *stream)
    {
        *stream << op << endl;
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
        *output << "node [shape = box];" << endl;
        for (auto i = tacInstructions.begin(); i != tacInstructions.end(); i++)
        {
            (*i)->printTac(output);
        }
    }

public:
    string name;
    list<TAC *> tacInstructions;
    TAC condition;
    BBlock *trueExit, *falseExit;
    BBlock() : trueExit(NULL), falseExit(NULL) {}
    void generatetac(void)
    {
        ofstream output("tac.dot");
        output << "diagraph {" << endl;
        generate(&output);
        output << "}" << endl;
        output.close();
    }
};

#endif
