#include <iostream>
#include "parser.tab.hh"

extern Node *root;
extern FILE *yyin;

SymbolTable *table = new SymbolTable(); // creating a symboltable object

void yy::parser::error(std::string const &err)
{
  std::cout << "Cannot generate a syntax tree for this input: " << err << std::endl;
}

void lookAt(Node *root)
{
  /* for each detected scope in tree create a new scope object i.e table.enterScope()
   * where do we shift scope is the problem
   * the main problem is we need to know that the variable is identifier and the scope is class or method
   */
  string type = root->type;
  string value = root->value;
  string id = to_string(root->id);

  
  cout << "Type is : " << type << "\n"
       << "Value is : " << value << endl;

  for (auto i = root->children.begin(); i != root->children.end(); i++)
  {
    lookAt((*i));
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
    // root->print_tree();
    root->generate_tree();
    lookAt(temp);
    table->printTable();
  }
  return 0;
}