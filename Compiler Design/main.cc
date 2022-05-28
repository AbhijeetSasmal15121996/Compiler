#include <iostream>
#include <regex>
#include "parser.tab.hh"
#include <cctype>

extern Node *root;
extern FILE *yyin;
SymbolTable *table = new SymbolTable();
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

void yy::parser::error(std::string const &err)
{
  std::cout << "Cannot generate a syntax tree for this input: " << err << std::endl;
}

string split(string temp)
{
  int count = 0;
  string t = "";
  for (int i = 0; i < temp.length(); i++)
  {
    if (temp[i] == ':')
    {
      count = 1;
      i++;
    }
    if (count == 0)
      continue;
    else
      t = t + temp[i];
  }
  return t;
}

void read()
{
  string temp;
  int counter = 0;
  int Class, method, variable = 0;
  string mdata;
  ifstream input("output.txt");
  while (getline(input, temp))
  {
    counter++;
    if (Class == 1)
    {
      table->insertRecord("Class", "Class", split(temp));
      Class = 0;
    }
    int found = temp.find("CLASS");
    if ((found != string::npos))
    {
      Class = 1;
    }

    int found1 = temp.find("Method");
    if (found1 != string::npos)
    {
      method = counter;
    }

    if (method!=0 && (counter-method)==2)
    {
      mdata=temp;
    }
    if (method!=0 && (counter-method)==3)
    {
      SymbolTable *tmp = new SymbolTable();
      
      table->insertRecord("Method", mdata, split(temp));
    }


  }
  input.close();
}

int main(int argc, char **argv)
{
  // Reads from file if a file name is passed as an argument. Otherwise, reads from stdin.
  if (argc > 1)
  {
    if (!(yyin = fopen(argv[1], "r")))
    {
      perror(argv[1]);
      return 1;
    }
  }

  yy::parser parser;
  if (!parser.parse())
  {
    Node *temp = root;
    ofstream outStream;
    outStream.open("output.txt");
    outStream << "\t"
              << "Type"
              << "\t"
              << "Value" << endl;
    write(temp, &outStream);
    outStream.close();

    read();

    table->print_table(table);
  }
  return 0;
}