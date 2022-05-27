#ifndef __heplers__h
#define __helpers_h
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Record
{
private:
    string id;
    string type;

public:
    Record()
    {
    }
    Record(string id, string type)
    {
        this->id = id;
        this->type = type;
    }

    void setId(string id)
    {
        this->id = id;
    }

    void setType(string type)
    {
        this->type = type;
    }

    string getId()
    {
        return this->id;
    }

    string getType()
    {
        return this->type;
    }

    void printRecord()
    {
        cout << "Id : " << this->getId() << "\n"
             << "Type : " << this->getType() << endl;
    }
};

class Variable : public Record
{
private:
    string name;
    string value;

public:
    Variable()
    {
    }
    void setName(string name)
    {
        this->name = name;
    }

    void setValue(string value)
    {
        this->value = value;
    }

    string getName()
    {
        return this->name;
    }

    string getValue()
    {
        return this->value;
    }
};

class Method : public Record
{
private:
    map<string, Variable> parameters;
    map<string, Variable> variables;
    string name;

public:
    Method()
    {
    }
    void setName(string name)
    {
        this->name = name;
    }
    void addVariable(string id, string type, string name, string value)
    {
        Variable v;
        v.setId(id);
        v.setType(type);
        v.setName(name);
        v.setValue(value);
        variables.insert({name, v});
    }

    void addMethod(string id, string type, string name, string value)
    {
        Variable v;
        v.setId(id);
        v.setType(type);
        v.setName(name);
        v.setValue(value);
        parameters.insert({name, v});
    }
};

class Class : public Record
{
private:
    map<string, Variable> variables;
    map<string, Method> methods;

public:
    Class()
    {
    }

    void addVariable(string id, string name, string type, string value)
    {
        Variable v;
        v.setId(id);
        v.setType(type);
        v.setName(name);
        v.setValue(value);
        variables.insert({name, v});
    }

    void addMethod(string id, string name, string type)
    {
        Method m;
        m.setId(id);
        m.setName(name);
        m.setType(type);
        methods.insert({name, m});
    }

    bool lookUpVariable(string name)
    {
        if (variables.find(name) != variables.end())
        {
            return true;
        }
        return false;
    }

    bool lookUpMethod(string name)
    {
        if (methods.find(name) != methods.end())
        {
            return true;
        }
        return false;
    }
};

class Scope
{
private:
    int next = 0;
    Scope *parentScope;
    vector<Scope *> childrenScopes;
    map<string, Record *> records;

public:
    Scope(Scope *s)
    {
    }

    map<string, Record *> getRecords()
    {
        return this->records;
    }

    Scope *parent()
    {
        return this->parentScope;
    }

    void setParent(Scope *parent)
    {
        this->parentScope = parent;
    }

    Scope *nextChild()
    {
        Scope *nextScope;
        if (next == childrenScopes.size())
        {
            nextScope = new Scope(this);
            childrenScopes.push_back(nextScope);
        }
        else
        {
            nextScope = childrenScopes[next];
            next++;
        }
        return nextScope;
    }

    Record *lookUp(string key)
    {
        if (records.find(key) != records.end())
        {
            return records.find(key)->second;
        }
        else
        {
            if (parentScope == NULL)
            {
                return NULL;
            }
            else
            {
                return parentScope->lookUp(key);
            }
        }
    }

    void resetScope()
    {
        next = 0;
        for (auto i = childrenScopes.begin(); i != childrenScopes.end(); i++)
        {
            (*i)->resetScope();
        }
    }

    void put(string key, Record *item)
    {
        this->records.insert({key, item});
    }

    void printScope()
    {
        for (auto i = this->records.crbegin(); i != this->records.crend(); i++)
        {
            (*i).second->printRecord();
        }
    }
};

#endif