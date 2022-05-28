#include <iostream>
#include "parser.tab.hh"
#include "SymbolTable.h"

extern Node *root;
extern FILE *yyin;

void yy::parser::error(std::string const &err)
{
  std::cout << "Cannot generate a syntax tree for this input: " << err << std::endl;
}
SymbolTable *root1;
SymbolTable *pre;
int counter = 0;
int clstate = 0;
int methstate = 0;
int varstate = 0;
Node *meth[4];
Node *cla[2];
Node *var[2];

void lookAt(Node *root, int depth = 0)
{
  string type = root->type;
  string value = root->value;

  if (value == "CLASS" || type == "CLASS")
  {
    if (clstate > 2)
    {
      clstate = 0;
    }
    cla[clstate] = root;
    clstate++;
    *meth = NULL;
    *var = NULL;
  }

  if (value == "Method Declaration" || type == "Method Declaration")
  {
    if (methstate > 3)
    {
      methstate = 0;
    }
    meth[methstate] = root;
    methstate++;
    *cla = NULL;
    *var = NULL;
  }

  if (value == "Variable Declaration" || type == "Variable Declaration")
  {
    if (varstate > 3)
    {
      varstate = 0;
    }
    var[varstate] = root;
    varstate++;
    *meth = NULL;
    *cla = NULL;
  }

  if (cla[1] != NULL)
  {
    SymbolTable *table = new SymbolTable(); // creating a symboltable object
    table->insert(cla[0]);
    table->insert(cla[1]);
    if (pre == NULL)
    {
      pre = table;
      root1 = pre;
    }
    else
    {
      pre->changeScope(table);
      pre = table;
    }
  }

  if (meth[3] != NULL)
  {
    SymbolTable *table = new SymbolTable(); // creating a symboltable object
    table->insert(meth[0]);
    table->insert(meth[1]);
    table->insert(meth[2]);
    table->insert(meth[3]);
    if (pre == NULL)
    {
      pre = table;
      root1 = pre;
    }
    else
    {
      pre->changeScope(table);
      pre = table;
    }
  }

  if (var[1] != NULL)
  {
    SymbolTable *table = new SymbolTable(); // creating a symboltable object
    table->insert(var[0]);
    table->insert(var[1]);
    if (pre == NULL)
    {
      pre = table;
      root1 = pre;
    }
    else
    {
      pre->changeScope(table);
      pre = table;
    }
  }

  for (auto i = root->children.begin(); i != root->children.end(); i++)
  {
    lookAt((*i), depth + 1);
  }
}

void print_symbol(SymbolTable *b)
{
  if (b == NULL)
  {
    return;
  }
  else
  {
    b->print_table();
    print_symbol(b->table.front());
  }
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
    lookAt(temp);        // this does a post order traversel and populates the symbol table
    print_symbol(root1); // uncomment this to print the SymbolTable
    // root->print_tree();  // uncomment this to print the AST(abstract syntax tree)
  }
  return 0;
}