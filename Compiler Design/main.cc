#include <iostream>
#include "parser.tab.hh"

extern Node *root;
extern FILE *yyin;

void write(Node *root, ofstream *ofstream)
{
  string id = to_string(root->id);
  string type = root->type;
  string value = root->value;
  *ofstream << type << "\t" << value << endl;
  for (auto i = root->children.begin(); i != root->children.end(); i++)
  {
    write((*i), ofstream);
  }
}

void yy::parser::error(std::string const &err)
{
  std::cout << "Cannot generate a syntax tree for this input: " << err << std::endl;
}

// void lookAt(Node *root)
// {
//   string type = root->type;
//   string value = root->value;
//   table->insert(type, value, type, value);
//   for (auto i = root->children.begin(); i != root->children.end(); i++)
//   {
//     lookAt((*i));
//   }
// }

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
    // lookAt(temp); // this does a post order traversel and populates the symbol table
    write(temp, &outStream);
    outStream.close();
    // print_symbol(root1); // uncomment this to print the SymbolTable
    // root->print_tree();  // uncomment this to print the AST(abstract syntax tree)
  }
  return 0;
}