#include <iostream>
#include <regex>
#include "parser.tab.hh"
#include <stack>
#include "Helpers.h"

extern Node *root;
extern FILE *yyin;

void yy::parser::error(std::string const &err)
{
  std::cout << "Cannot generate a syntax tree for this input: " << err << std::endl;
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
    write(temp, &outStream);
    outStream.close();
    cout << "\n\n---Abstract Syntax Tree---\n\n";
    root->print_tree();
    root->generate_tree();
    cout << "\n\n---End of Abstract Syntax Tree\n\n";
    read();
    cout << "\n\n------Symbol Table-----\n\n"
         << endl;
    table->print_table(table);
    cout << "\n\n------End Of Symbol Table-----\n\n"
         << endl;
    // getEquation();
    makeTAC(table);
    // getMul();
  }
  return 0;
}