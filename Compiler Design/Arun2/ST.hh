#include <list>
#include <map>
#include <string>
#include <iostream>
#include <iterator>
#include <unistd.h>
#include <sys/wait.h>

// This basically is the class to get the id and type of the variable, method and class

class Rec
{
private:
    std::string id;
    std::string type;

public:
    Rec(){};
    Rec(std::string id, std::string type)
    {
        this->id = id;
        this->type = type;
    }
    void setId(std::string id) { this->id = id; }
    void setType(std::string type) { this->type = type; }
    std::string getId() { return this->id; }
    std::string getType() { return this->type; }
    virtual void printRec(){};
    virtual Rec *lookupMethod(std::string key) { return NULL; }
    virtual Rec *lookupVariable(std::string key) { return NULL; }
    virtual void getParameters(std::list<std::string> &l){};
};

class Variable : public Rec
{
public:
    Variable() {}
    Variable(std::string id, std::string type) : Rec(id, type) {}
    void printRec() {}
};

class Method : public Rec
{
private:
    std::map<std::string, Variable *> parameters;
    std::map<std::string, Variable *> variables;
    std::list<std::string> parametersMethod;

public:
    Method() {}
    Method(std::string id, std::string type) : Rec(id, type) {}
    void addParameter(std::string key, Variable *item)
    {
        parametersMethod.push_back(item->getType());
        if (parameters.insert(std::pair<std::string, Variable *>(key, item)).second == false)
        {
            std::cout << "Error: parameter " << key << " already exist in the method " << this->getId() << "\n";
        }
    }
    void insertVariable(std::string key, Variable *item)
    {
        if (variables.insert(std::pair<std::string, Variable *>(key, item)).second == false)
        {
            std::cout << "Error: variable " << key << " already exist in the method " << this->getId() << "\n";
        }
    }

    void getParameters(std::list<std::string> &l)
    {
        for (std::list<std::string>::iterator i = parametersMethod.begin(); i != parametersMethod.end(); ++i)
        {
            l.push_back((*i));
        }
    }

    void printRec()
    {
        std::cout << "Symbol table for the method " << this->getId() << "\n";
        for (auto it = parameters.cbegin(); it != parameters.cend(); ++it)
        {

            Variable v = *(it->second);
            std::cout << "NAME: " << v.getId() << " RECORD: PARAMETER   TYPE: " << v.getType() << "\n";
        }
        for (auto it = variables.cbegin(); it != variables.cend(); ++it)
        {

            Variable v = *(it->second);
            std::cout << "NAME: " << v.getId() << " RECORD: VARIABLE   TYPE: " << v.getType() << "\n";
        }
    }
};

class Scope
{

public:
    Scope *parentScope;
    int next;

    std::map<std::string, Rec *> Recs;
    std::list<Scope *>::iterator it;
    std::list<Scope *> childrenScopes;

    Scope(Scope *sc)
    {
        parentScope = sc;
        next = 0;
        it = childrenScopes.begin();
    }

    Scope *nextChild()
    {
        Scope *nextChild;
        it = childrenScopes.begin();
        if (next == childrenScopes.size())
        {

            nextChild = new Scope(this);
            childrenScopes.push_back(nextChild);
        }
        else
        {
            std::advance(it, next);
            nextChild = *it;
        }
        next++;

        return nextChild;
    }

    Rec *lookup(std::string key)
    {

        if (Recs.count(key))
        {
            return Recs[key];
        }
        else
        {
            if (parentScope == NULL)
                return NULL;
            else
                return parentScope->lookup(key);
        }
    }

    void resetScope()
    {
        next = 0;
        for (std::list<Scope *>::iterator i = childrenScopes.begin(); i != childrenScopes.end(); ++i)
        {
            (*i)->resetScope();
        }
    }

    void put(std::string key, Rec *item)
    {

        if (Recs.insert(std::make_pair(key, item)).second == false)
        {
            std::cout << "Error: " << key << " already exist in the Scope "
                      << "\n";
        }
    }

    void printScope()
    {
        std::cout << "\n\n";
        std::cout << "Symbol table of the program "
                  << "\n";
        for (auto it = Recs.cbegin(); it != Recs.cend(); ++it)
        {

            std::cout << "NAME: " << (it->second)->getId() << "RECORD: CLASS   TYPE:  " << (it->second)->getType() << "\n";
        }
        std::cout << "\n";
        for (auto it = Recs.cbegin(); it != Recs.cend(); ++it)
        {
            (it->second)->printRec();
            std::cout << "\n";
        }
    }

    Scope *getParent()
    {
        return parentScope;
    }
};

class Class : public Rec
{
private:
    std::map<std::string, Variable *> variables;
    std::map<std::string, Method *> methods;

public:
    Class() {}
    Class(std::string id, std::string type) : Rec(id, type) {}
    void insertVariable(std::string key, Variable *item)
    {
        if (variables.insert(std::pair<std::string, Variable *>(key, item)).second == false)
        {
            std::cout << "Error: variable " << key << " is present in the class already " << this->getId() << "\n";
        }
    }
    void addMethod(std::string key, Method *item)
    {
        if (methods.insert(std::pair<std::string, Method *>(key, item)).second == false)
        {
            std::cout << "Error: method " << key << " is present in the class already " << this->getId() << "\n";
        }
    }

    Rec *lookupMethod(std::string key)
    {

        if (methods.count(key))
        {
            return methods[key];
        }
        else
        {
            return NULL;
        }
    }

    Rec *lookupVariable(std::string key)
    {

        if (variables.count(key))
        {

            return variables[key];
        }
        else
        {
            return NULL;
        }
    }

    void printRec()
    {

        std::cout << "  Symbol table of the class " << this->getId() << "\n";
        for (auto it = variables.cbegin(); it != variables.cend(); ++it)
        {

            Variable v = *(it->second);
            std::cout << "NAME: " << v.getId() << "RECORD: VARIABLE   TYPE:   " << v.getType() << "\n";
        }
        for (auto it = methods.cbegin(); it != methods.cend(); ++it)
        {

            Method m = *(it->second);
            std::cout << " NAME: " << m.getId() << "RECORD: METHOD   TYPE:   " << m.getType() << "\n";
        }
        std::cout << "\n";
        for (auto it = methods.cbegin(); it != methods.cend(); ++it)
        {

            Method m = *(it->second);
            m.printRec();
            std::cout << "\n";
        }
    }
};
class ST
{
private:
    Scope *root;
    Scope *current;

public:
    void SymbolTable()
    {
        root = new Scope(NULL);
        current = root;
    }
    void enterScope()
    {
        current = current->nextChild();
    }
    void exitScope()
    {
        current = current->getParent();
    }
    void put(std::string key, Rec *item)
    {

        current->put(key, item);
    }
    Rec *lookup(std::string key)
    {
        return current->lookup(key);
    }
    void printTable()
    {
        root->printScope();
    }
    void resetTable()
    {
        root->resetScope();
    }
};
