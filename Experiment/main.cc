#include <iostream>
#include "parser.tab.hh"

extern Node *root;
extern FILE *yyin;
SymbolTable *table = new SymbolTable();

void yy::parser::error(std::string const &err)
{
  std::cout << "Cannot generate a syntax tree for this input: " << err << std::endl;
}

void lookAt(Node *root, int depth = 0)
{
  table->insert(root->type, root->value, root->type, root->value);
  // if (!table->lookup(root->value))
  // {
  //   table->insert(root->type, root->value, root->type, root->value);
  // }
  // else
  // {
  //   cout << "Error The Variable" << root->value << "is Aldredy Declared" << endl;
  // }
  for (auto i = root->children.begin(); i != root->children.end(); i++)
  {
    lookAt((*i), depth + 1);
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
    lookAt(temp); // this basically does a post order traversel and populates the symbol table

    table->print_table(); // this prints the symbol table
    // root->print_tree(); // uncomment this to print the AST(abstract syntax tree)
    root->generate_tree();
  }

  return 0;
}