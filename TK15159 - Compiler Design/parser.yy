%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

%code requires{
  #include <string>
  #include "Node.h"
}
%code{
  #define YY_DECL yy::parser::symbol_type yylex()

  YY_DECL;
  
  Node* root;
  
  extern int node_id;
  
}
%token <std::string> IDENTIFIER LSQUAREP AND RSQUAREP LESSER GREATER OR ASSIGNOP MULTOP DIVISIONOP INT PLUSOP MINUSOP PERIOD LENGTH TRUE FALSE THIS NEW INTEGER BOOLEAN LP RP NOT COMMA LBRACKET RBRACKET IF ELSE WHILE PRINT SEMICOLON EQUALS RETURN PUBLIC CLASS EXTENDS STATIC VOID MAIN STRINGS STRING
%token END 0 "end of file"
%type <Node *> identifier program expression expressionList statement statementList type varDeclaration varDeclarationList methodDeclaration parameterList extends methodDeclarationList classDeclaration classDeclarationList mainClass

%right EQUALS
%left LSQUAREP
%left AND
%left PLUSOP MINUSOP
%left MULTOP
%left DIVISIONOP
%left PERIOD
%left NOT
%nonassoc LESSER


%%

program: mainClass { $$ = $1; printf("R1 ");}
      | program classDeclarationList END{
                        printf("R2 Rules \n");
                        $$ = new Node("Program", "");
                        $$->children.push_back($1);
                        if($2) $$->children.push_back($2);
                        root = $$;
                      }
        ;

mainClass: CLASS identifier LBRACKET PUBLIC STATIC VOID MAIN LP STRING LSQUAREP RSQUAREP identifier RP LBRACKET statement RBRACKET RBRACKET{
                        printf("R3 ");
                        $$ = new Node("MainClass", "");
                        $$->children.push_back(new Node("", "CLASS")); 
                        $$->children.push_back($2);
                        $$->children.push_back(new Node("LBRACKET", "{"));
                        $$->children.push_back(new Node("", "PUBLIC"));
                        $$->children.push_back(new Node("", "STATIC"));
                        $$->children.push_back(new Node("", "VOID"));
                        $$->children.push_back(new Node("", "MAIN"));
                        $$->children.push_back(new Node("LP", "(")); 
                        $$->children.push_back(new Node("", "String"));
                        $$->children.push_back(new Node("LSQUAREP", "["));
                        $$->children.push_back(new Node("RSQUAREP", "]"));       
                        $$->children.push_back($12);
                        $$->children.push_back(new Node("RP", ")"));
                        $$->children.push_back(new Node("LBRACKET", "{"));  
                        $$->children.push_back($15);
                        $$->children.push_back(new Node("RBRACKET", "}"));
                        $$->children.push_back(new Node("RBRACKET", "}")); 
                      }
        ;

extends: {}
        | EXTENDS identifier { 
                        printf("R4 ");
                        $$ = new Node("Extends", "");
                        $$->children.push_back(new Node("", "EXTENDS")); 
                        $$->children.push_back($2);
                      }
        
        ; 

classDeclarationList: classDeclaration { $$ = $1; printf("R5 ");}
        | classDeclarationList classDeclaration {
                        printf("R6 ");
                        $$ = new Node("ClassDeclarationList", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                      }
        ;

classDeclaration: CLASS identifier extends LBRACKET varDeclarationList methodDeclarationList RBRACKET{
                        printf("R7 ");
                        $$ = new Node("ClassDeclaration", "");
                        $$->children.push_back(new Node("", "CLASS")); 
                        $$->children.push_back($2);
                        if($3) $$->children.push_back($3);
                        $$->children.push_back(new Node("LBRACKET", "{"));
                        if($5) $$->children.push_back($5);
                        if($6) $$->children.push_back($6);
                        $$->children.push_back(new Node("RBRACKET", "}"));
                      }
        |         CLASS identifier extends LBRACKET methodDeclarationList RBRACKET{
                        printf("R8 ");
                        $$ = new Node("ClassDeclaration", "");
                        $$->children.push_back(new Node("", "CLASS")); 
                        $$->children.push_back($2);
                        if($3) $$->children.push_back($3);
                        $$->children.push_back(new Node("LBRACKET", "{"));
                        if($5) $$->children.push_back($5);
                        $$->children.push_back(new Node("RBRACKET", "}"));
                      }
        |          CLASS identifier extends LBRACKET varDeclarationList RBRACKET{
                        printf("R9 ");
                        $$ = new Node("ClassDeclaration", "");
                        $$->children.push_back(new Node("", "CLASS")); 
                        $$->children.push_back($2);
                        if($3) $$->children.push_back($3);
                        $$->children.push_back(new Node("LBRACKET", "{"));
                        if($5) $$->children.push_back($5);
                        $$->children.push_back(new Node("RBRACKET", "}"));
                      }
        |         CLASS identifier extends LBRACKET RBRACKET{
                        printf("R10 ");
                        $$ = new Node("ClassDeclaration", "");
                        $$->children.push_back(new Node("", "CLASS")); 
                        $$->children.push_back($2);
                        if($3) $$->children.push_back($3);
                        $$->children.push_back(new Node("LBRACKET", "{"));
                        $$->children.push_back(new Node("RBRACKET", "}"));
                      }
        ;

varDeclarationList: varDeclaration { $$ = $1; printf("R11 ");}
        | varDeclarationList varDeclaration {
                        printf("R12 ");
                        $$ = new Node("VarDeclarationList", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                      }
        ;
 
varDeclaration:  type identifier  SEMICOLON{
                        printf("R13 ");
                        $$ = new Node("VarDeclaration", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back(new Node("SEMICOLON", ";")); 
                      }
        ;

methodDeclarationList: methodDeclaration { $$ = $1; printf("R14 ");}
        | methodDeclarationList methodDeclaration { 
                        printf("R15 ");
                        $$ = new Node("MethodDeclarationList", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        }
        
        ;

methodDeclaration: PUBLIC type identifier LP parameterList RP LBRACKET varDeclarationList statementList RETURN expression SEMICOLON RBRACKET{
                        printf("R16 ");
                        $$ = new Node("MethodDeclaration", "");
                        $$->children.push_back(new Node("", "public")); 
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("LP", "("));
                        if($5) $$->children.push_back($5);
                        $$->children.push_back(new Node("RP", ")"));
                        $$->children.push_back(new Node("LBRACKET", "{"));
                        if($8) $$->children.push_back($8);
                        if($9) $$->children.push_back($9);
                        $$->children.push_back(new Node("", "return"));
                        $$->children.push_back($11);
                        $$->children.push_back(new Node("SEMICOLON", ";"));
                        $$->children.push_back(new Node("RBRACKET", "}"));
                      }
        |           PUBLIC type identifier LP parameterList RP LBRACKET statementList RETURN expression SEMICOLON RBRACKET{
                        printf("R17 ");
                        $$ = new Node("MethodDeclaration", "");
                        $$->children.push_back(new Node("", "public")); 
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("LP", "("));
                        if($5) $$->children.push_back($5);
                        $$->children.push_back(new Node("RP", ")"));
                        $$->children.push_back(new Node("LBRACKET", "{"));
                        if($8) $$->children.push_back($8);
                        $$->children.push_back(new Node("", "return"));
                        $$->children.push_back($10);
                        $$->children.push_back(new Node("SEMICOLON", ";"));
                        $$->children.push_back(new Node("RBRACKET", "}"));
                      }       
         |           PUBLIC type identifier LP parameterList RP LBRACKET varDeclarationList RETURN expression SEMICOLON RBRACKET{
                        printf("R17 ");
                        $$ = new Node("MethodDeclaration", "");
                        $$->children.push_back(new Node("", "public")); 
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("LP", "("));
                        if($5) $$->children.push_back($5);
                        $$->children.push_back(new Node("RP", ")"));
                        $$->children.push_back(new Node("LBRACKET", "{"));
                        if($8) $$->children.push_back($8);
                        $$->children.push_back(new Node("", "return"));
                        $$->children.push_back($10);
                        $$->children.push_back(new Node("SEMICOLON", ";"));
                        $$->children.push_back(new Node("RBRACKET", "}"));
                      }
        |           PUBLIC type identifier LP parameterList RP LBRACKET RETURN expression SEMICOLON RBRACKET{
                        printf("R18 ");
                        $$ = new Node("MethodDeclaration", "");
                        $$->children.push_back(new Node("", "public")); 
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("LP", "("));
                        if($5) $$->children.push_back($5);
                        $$->children.push_back(new Node("RP", ")"));
                        $$->children.push_back(new Node("LBRACKET", "{"));
                        $$->children.push_back(new Node("", "return"));
                        $$->children.push_back($9);
                        $$->children.push_back(new Node("SEMICOLON", ";"));
                        $$->children.push_back(new Node("RBRACKET", "}"));
                      }
        ;

parameterList: {} 
        | type identifier{
                          printf("R19 ");
                          $$ = new Node("ParameterList", ""); 
                          $$->children.push_back($1);
                          $$->children.push_back($2);
                        } 
        | type identifier COMMA parameterList {
                          printf("R20 ");
                          $$ = new Node("ParameterList", ""); 
                          $$->children.push_back($1);
                          $$->children.push_back($2);
                          $$->children.push_back(new Node("COMMA", ","));
                          $$->children.push_back($4);
                        }
        ;

type:  identifier { $$ = $1; printf("R21 ");}
        | INTEGER { $$ = new Node("TYPE", $1); printf("R22 ");}
        | BOOLEAN { $$ = new Node("TYPE", $1); printf("R23 ");}
        | INTEGER LSQUAREP RSQUAREP {
                        printf("R24 ");
                        $$ = new Node("TypeVector", ""); 
                        $$->children.push_back(new Node("Type", "INT"));
                        $$->children.push_back(new Node("LSQUAREP", "["));
                        $$->children.push_back(new Node("RSQUAREP", "]"));
                      }
        ;
statementList:  statement { $$ = $1; printf("R25 ");}
        | statementList statement{
                        printf("R26 ");
                        $$ = new Node("StatementList", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                      }
        ;

statement: LBRACKET statementList RBRACKET {
                        printf("R27 ");
                        $$ = new Node("Statement", ""); 
                        $$->children.push_back(new Node("LBRACKET", "{"));
                        $$->children.push_back($2);
                        $$->children.push_back(new Node("RBRACKET", "}"));
                      }
        | IF LP expression RP statement ELSE statement{
                        printf("R28 ");
                        $$ = new Node("IFStatement", ""); 
                        $$->children.push_back(new Node("IF", "if"));
                        $$->children.push_back(new Node("LP", "("));
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("RP", ")"));
                        $$->children.push_back($5);
                        $$->children.push_back(new Node("ELSE", "else"));
                        $$->children.push_back($7);
                      }
        | WHILE LP expression RP statement{
                        printf("R29 ");
                        $$ = new Node("WHILEStatement", ""); 
                        $$->children.push_back(new Node("WHILE", "while"));
                        $$->children.push_back(new Node("LP", "("));
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("RP", ")"));
                        $$->children.push_back($5);
                      }
        | PRINT LP expression RP SEMICOLON {
                        printf("R30 ");
                        $$ = new Node("PrintStatement", ""); 
                        $$->children.push_back(new Node("PRINT", "System.out.println"));
                        $$->children.push_back(new Node("LP", "("));
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("RP", ")"));
                        $$->children.push_back(new Node("SEMICOLON", ";"));
                      }
        | identifier EQUALS expression SEMICOLON{
                        printf("R31 ");
                        $$ = new Node("AssignmentStatement", "");
                        $$->children.push_back($1); 
                        $$->children.push_back(new Node("EQUALS", "="));
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("SEMICOLON", ";"));
                      }
        | identifier LSQUAREP expression RSQUAREP EQUALS expression SEMICOLON {
                        printf("R32 ");
                        $$ = new Node("VectorAssignmentStatement", "");
                        $$->children.push_back($1); 
                        $$->children.push_back(new Node("LSQUAREP", "["));
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("RSQUAREP", "]"));
                        $$->children.push_back(new Node("EQUALS", "="));
                        $$->children.push_back($6);
                        $$->children.push_back(new Node("SEMICOLON", ";"));
                      }
        ;

expressionList: expression { $$ = $1; printf("R33 ");}
        | expression COMMA expressionList       {
                        printf("R34 ");
                        $$ = new Node("ExpressionList", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("COMMA", ","));
                        $$->children.push_back($3);
                      }
        ;

expression: identifier { $$ = $1; printf("R35 ");}
        | INT { $$ = new Node("INTEGER", $1); printf("R36 ");} 
        | TRUE { $$ = new Node("LITERAL", $1); printf("R37 ");} 
        | FALSE { $$ = new Node("LITERAL", $1); printf("R38 ");} 
        | THIS { $$ = new Node("", $1); printf("R39 ");}  
        | expression LESSER expression             {
                        printf("R40 ");
                        $$ = new Node("LESSERExpression", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("LESSER", "<"));
                        $$->children.push_back($3);
                      
                      }
        | expression ASSIGNOP expression             {
                        printf("R40 ");
                        $$ = new Node("ASSIGNMENTExpression", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("ASSIGNMENT", "=="));
                        $$->children.push_back($3);
                      
                      }
        | expression GREATER expression             {
                        printf("R40 ");
                        $$ = new Node("GREATERExpression", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("GREATER", ">"));
                        $$->children.push_back($3);
                      
                      }
        | expression OR expression             {
                        printf("R40 ");
                        $$ = new Node("ORExpression", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("OR", "||"));
                        $$->children.push_back($3);
                      
                      }
        
        | expression AND expression             {
                        printf("R41 ");
                        $$ = new Node("AndExpression", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("AND", "&&"));
                        $$->children.push_back($3);
                     
                      }
        | expression MULTOP expression             {
                        printf("R42 ");
                        $$ = new Node("MultExpression", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("MULTOP", "*"));
                        $$->children.push_back($3);
        
                      }
        | expression DIVISIONOP expression             {
                        printf("R42 ");
                        $$ = new Node("DIVISIONExpression", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("DIVISION", "/"));
                        $$->children.push_back($3);
        
                      }
        | expression PLUSOP expression             {
                        printf("R43 ");
                        $$ = new Node("PlusExpression", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("PLUS", "+"));
                        $$->children.push_back($3);
        
                      }
        | expression MINUSOP expression             {
                        printf("R44 ");
                        $$ = new Node("MinusExpression", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("MINUS", "-"));
                        $$->children.push_back($3);
        
                      }
        | expression LSQUAREP expression RSQUAREP{
                        printf("R45 ");
                        $$ = new Node("VectorAccessExpression", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("LSQUAREP", "["));
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("RSQUAREP", "]"));
                      }
        | expression PERIOD LENGTH                {
                        printf("R46 ");
                        $$ = new Node("LengthExpression", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("PERIOD", "."));
                        $$->children.push_back(new Node("LENGTH", "length"));
                      }   
        | NEW INTEGER LSQUAREP expression RSQUAREP                    {
                        printf("R47 ");
                        $$ = new Node("NewVectorExpression", "");
                        $$->children.push_back(new Node("NEW", "new"));
                        $$->children.push_back(new Node("INT", "int")); 
                        $$->children.push_back(new Node("LSQUAREP", "["));
                        $$->children.push_back($4);
                        $$->children.push_back(new Node("RSQUAREP", "]")); 
                      }  
        | NEW identifier LP RP           {
                        printf("R48 ");
                        $$ = new Node("NewClassExpression", "");
                        $$->children.push_back(new Node("NEW", "new"));
                        $$->children.push_back($2);
                        $$->children.push_back(new Node("LP", "(")); 
                        $$->children.push_back(new Node("RP", ")"));
                      }  
        | NOT expression                 {
                        printf("R49 ");
                        $$ = new Node("NOTExpression", "");
                        $$->children.push_back(new Node("NOT", "!"));
                        $$->children.push_back($2);
                      }  
        | LP expression RP                {
                        printf("R50 ");
                        $$ = new Node("ParenExpression", "");
                        $$->children.push_back(new Node("LP", "("));
                        $$->children.push_back($2);
                        $$->children.push_back(new Node("RP", ")"));
                      } 
        | expression PERIOD identifier LP expressionList RP{
                        printf("R51 ");
                        $$ = new Node("MethodCallExpression", "");
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("PERIOD", "."));
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("LP", "("));
                        $$->children.push_back($5);
                        $$->children.push_back(new Node("RP", ")"));
                      } 
        | expression PERIOD identifier LP RP{
                        printf("R52 ");
                        $$ = new Node("MethodCallExpressionWithoutArgs", "");
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("PERIOD", "."));
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("LP", "("));
                        $$->children.push_back(new Node("RP", ")"));
                      } 
        ;

identifier: IDENTIFIER {  $$ = new Node("Identifier", $1); printf("R53 %s ",$1.c_str());};