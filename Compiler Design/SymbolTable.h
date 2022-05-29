#include <map>
#include <list>
#include <iostream>

using namespace std;

class Record
{
public:
    string type, value, name;
    Record() {}
    Record(string type, string value, string name)
    {
        this->type = type;
        this->value = value;
        this->name = name;
    }
};

class SymbolTable
{
private:
    string name;
    vector<SymbolTable *> tables;
    vector<Record *> records;

public:
    void insertName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return this->name;
    }

    void insertRecord(string type, string value, string name)
    {
        Record *r = new Record(type, value, name);
        this->records.push_back(r);
    }

    void insertTable(SymbolTable *newTable)
    {
        this->tables.push_back(newTable);
    }

    SymbolTable *getTable(int index)
    {
        return this->tables[index];
    }

    void print_table(SymbolTable *newTable)
    {
        for (int i = 0; i < this->records.size(); i++)
        {
            cout << "Type is : " << this->records[i]->type << "\t"
                 << "Value is : " << this->records[i]->value << "\t"
                 << "ScopeName is : " << this->name << "\t"
                 << "Name is : " << this->records[i]->name << endl;
        }
        for (auto i = 0; i < this->tables.size(); i++)
        {
            this->tables[i]->print_table(this->tables[i]);
        }
    }
};
