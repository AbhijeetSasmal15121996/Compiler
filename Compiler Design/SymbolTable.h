#include <map>
#include <list>
#include <iostream>
#include <string>

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
    vector<Record *> getRecords()
    {
        return this->records;
    }

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

    int compareStr(string a, string b)
    {
        int z = 1;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] != b[i])
            {
                z = 0;
                break;
            }
        }
        return z;
    }

    bool isNumber(const string &s)
    {
        for (char const &ch : s)
        {
            if (std::isdigit(ch) == 0)
                return false;
        }
        return true;
    }

    string check(SymbolTable *table, string name, string scope)
    {

        // check integer

        // cout << "Name: " << name << "\tScope: " << scope <<endl;
        vector<SymbolTable *> res = table->tables;
        string anotherName = "";
        int nullchar = 0;
        for (int i = 0; i < name.length(); i++)
        {
            if (name[i] == '\0' || name[i] == ' ')
            {
                // cout << "Null Char" << i << "  " <<  name <<endl;
                nullchar = 1;
                break;
            }
        }

        if (nullchar == 1)
        {
            for (int i = 1; i < name.length(); i++)
            {
                anotherName = anotherName + name[i];
            }
            name = anotherName;
            // cout << "Null Removed "<< name << endl;
        }

        // cout << "----------------------\n";

        for (int i = 0; i < res.size(); i++)
        {
            vector<Record *> tmpRecords = res[i]->getRecords();
            string tmpScope = res[i]->getName();
            string type = tmpRecords[0]->type;
            string tmpName = tmpRecords[0]->name;
            string tmpValue = tmpRecords[0]->value;

            // cout << "---------------start loop ----------------\n";

            // cout << "Cond scope: " << scope << endl;
            // cout << "Cond name: " << name << endl;

            // cout << "tmpScope: " << tmpScope << endl;
            // cout << "type: " << type << endl;
            // cout << "tmpName: " << tmpName << endl;
            // cout << "tmpValue: " << tmpValue << endl;

            // cout << "---------------stop loop ----------------\n";

            if (compareStr(tmpName, name) == 1 && scope == tmpScope)
            {
                // cout << "TmpName: " << tmpName << "Scope: " << tmpScope << endl;
                // cout << "Name1: " << name << "Scope1: " << scope << endl;
                return tmpValue;
            }
        }
        return "None:None";
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
