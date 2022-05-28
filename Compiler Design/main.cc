#include <iostream>
#include "parser.tab.hh"

extern Node *root;
extern FILE *yyin;


void yy::parser::error(std::string const &err)
{
  std::cout << "Cannot generate a syntax tree for this input: " << err << std::endl;
}
SymbolTable *root;
counter = 0;
string type1 = "";
string type2 = "";
string type3 = "";
string value1 = "";
string value2 = "";
string value3 = "";
void lookAt(Node *root, int depth = 0)
{
  string type = root->type;
  string value = root->value;

  if (type1 == "" || value1 == "") {
    if (type == "") {
      type1 = "999";
    } else {
      type1 = type;
    }
    if (value == "") {
      value1 = "999";
    } else {
      value1 = value;
    }
  }

if ((type2 == "" || value2 == "") && (type1 != "" && value1 != "")) {
    if (type == "") {
      type2 = "999";
    } else {
      type2 = type;
    }
    if (value == "") {
      value2 = "999";
    } else {
      value2 = value;
    }
  }

if ((type3 == "" || value3 == "") && (type2 != "" && value2 != "") && (type1 != "" && value1 != "")) {
    if (type == "") {
      type3 = "999";
    } else {
      type3 = type;
    }
    if (value == "") {
      value3 = "999";
    } else {
      value3 = value;
    }
  }

  if ((type2 != "" && value2 != "") && (type1 != "" && value1 != "") && (type3 != "" && value3 != "")) {
    SymbolTable *table = new SymbolTable(); // creating a symboltable object
    if(value == "CLASS" ||)
    table->insert(type, value);
    pre = table;
    if (counter == 0){
      root = table;
      counter++;
    } else {
      table->changeScope(pre);
    }
  }
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
    // lookAt(temp); // this does a post order traversel and populates the symbol table
    // table->print_table(); // uncomment this to print the SymbolTable
    root->print_tree(); // uncomment this to print the AST(abstract syntax tree)
    // root->generate_tree();
    // char java[100] = "java ";
    // const char *result = strcat(const_cast<char *>(java), argv[1]);
    // cout << "\n\n Output is " << endl;
    // system(result);
  }
  return 0;
}