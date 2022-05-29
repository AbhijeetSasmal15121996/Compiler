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

  /*
   * Semantic analysis is not completed the symbol table is a part of semantic analysis
   * check wheather the lhs data type = rhs data type and same for methods also
   * data type of method must match return type of method if not show an error message and return
   * check for undefined variables and if are there just show error message
   */

  /*
   * Take out three adress code and print it to pdf
   * interpret it and get the result
   */

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
    cout << "\n\n---End of Abstract Syntax Tree\n\n";
    read();
    cout << "\n\n------Symbol Table-----\n\n"
         << endl;
    table->print_table(table);
    cout << "\n\n------End Of Symbol Table-----\n\n"
         << endl;
    // getEquation();
    // getMul();
  }
  return 0;
}