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

    TAC(string op, string result)
    {
        this->op = op;
        this->result = result;
    }

    TAC(string op, string lhs, string result)
    {
        this->op = op;
        this->lhs = lhs;
        this->result = result;
    }

    void dump(ofstream *stream)
    {
        *stream << " [label=\""
                << this->result
                << "="
                << this->lhs << " "
                << this->op << " "
                << this->rhs
                << "\"];";
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

class Expression : public TAC
{
public:
    Expression(string _op, string _lhs, string _rhs, string _result) : TAC(_op, _lhs, _rhs, _result) {}
};

class MethodCall : public TAC
{
public:
    MethodCall(string _f, string _N, string _result) : TAC("call", _f, _N, _result) {}
};

class Jump : public TAC
{
public:
    Jump(string _lablel) : TAC("goto", _lablel) {}
};

class CondJump : public TAC
{
public:
    CondJump(string _op, string _x, string _label) : TAC(_op, _x, _label) {}
};

class BBlock
{
private:
    void generate(ofstream *output)
    {
        *output << "node [shape = box];" << endl;
        for (auto i = 0; i < this->tacInstructions.size(); i++)
        {
            *output << "n" << to_string(i);
            this->tacInstructions[i]->dump(output);
            string final = "\nn" + to_string(i) + " ->" + " n" + to_string(i + 1) + "\n";
            *output << final;
        }
    }
    string name;
    vector<TAC *> tacInstructions;

public:
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

    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return this->name;
    }
};

#endif
