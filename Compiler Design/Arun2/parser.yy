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
%token <std::string> IDENTIFIER LBRACKET AND RBRACKET LSS TIMES INTEGER_LITERAL PLUS MINUS PERIOD LENGTH TRUE FALSE THIS NEW INT BOOLEAN LPAREN RPAREN EXCLAMATION COMMA LBRACE RBRACE IF ELSE WHILE PRINTLN SEMICOLON EQUAL RETURN PUBLIC CLASS EXTENDS STATIC VOID MAIN STRING WORDSTRING
%token END 0 "end of file"
%type <Node *> identifier program expression expressionList statement statementList type varDeclaration varDeclarationList methodDeclaration parameterList extends methodDeclarationList classDeclaration classDeclarationList mainClass

%right EQUAL
%left LBRACKET
%left AND
%left PLUS MINUS
%left TIMES
%left PERIOD
%left EXCLAMATION
%nonassoc LSS


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

mainClass: CLASS identifier LBRACE PUBLIC STATIC VOID MAIN LPAREN WORDSTRING LBRACKET RBRACKET identifier RPAREN LBRACE statement RBRACE RBRACE{
                        printf("R3 ");
                        $$ = new Node("MainClass", "");
                        $$->children.push_back(new Node("", "CLASS")); 
                        $$->children.push_back($2);
                        $$->children.push_back(new Node("LBRACE", "{"));
                        $$->children.push_back(new Node("", "PUBLIC"));
                        $$->children.push_back(new Node("", "STATIC"));
                        $$->children.push_back(new Node("", "VOID"));
                        $$->children.push_back(new Node("", "MAIN"));
                        $$->children.push_back(new Node("LPAREN", "(")); 
                        $$->children.push_back(new Node("", "String"));
                        $$->children.push_back(new Node("LBRACKET", "["));
                        $$->children.push_back(new Node("RBRACKET", "]"));       
                        $$->children.push_back($12);
                        $$->children.push_back(new Node("RPAREN", ")"));
                        $$->children.push_back(new Node("LBRACE", "{"));  
                        $$->children.push_back($15);
                        $$->children.push_back(new Node("RBRACE", "}"));
                        $$->children.push_back(new Node("RBRACE", "}")); 
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

classDeclaration: CLASS identifier extends LBRACE varDeclarationList methodDeclarationList RBRACE{
                        printf("R7 ");
                        $$ = new Node("ClassDeclaration", "");
                        $$->children.push_back(new Node("", "CLASS")); 
                        $$->children.push_back($2);
                        if($3) $$->children.push_back($3);
                        $$->children.push_back(new Node("LBRACE", "{"));
                        if($5) $$->children.push_back($5);
                        if($6) $$->children.push_back($6);
                        $$->children.push_back(new Node("RBRACE", "}"));
                      }
        |         CLASS identifier extends LBRACE methodDeclarationList RBRACE{
                        printf("R8 ");
                        $$ = new Node("ClassDeclaration", "");
                        $$->children.push_back(new Node("", "CLASS")); 
                        $$->children.push_back($2);
                        if($3) $$->children.push_back($3);
                        $$->children.push_back(new Node("LBRACE", "{"));
                        if($5) $$->children.push_back($5);
                        $$->children.push_back(new Node("RBRACE", "}"));
                      }
        |          CLASS identifier extends LBRACE varDeclarationList RBRACE{
                        printf("R9 ");
                        $$ = new Node("ClassDeclaration", "");
                        $$->children.push_back(new Node("", "CLASS")); 
                        $$->children.push_back($2);
                        if($3) $$->children.push_back($3);
                        $$->children.push_back(new Node("LBRACE", "{"));
                        if($5) $$->children.push_back($5);
                        $$->children.push_back(new Node("RBRACE", "}"));
                      }
        |         CLASS identifier extends LBRACE RBRACE{
                        printf("R10 ");
                        $$ = new Node("ClassDeclaration", "");
                        $$->children.push_back(new Node("", "CLASS")); 
                        $$->children.push_back($2);
                        if($3) $$->children.push_back($3);
                        $$->children.push_back(new Node("LBRACE", "{"));
                        $$->children.push_back(new Node("RBRACE", "}"));
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

methodDeclaration: PUBLIC type identifier LPAREN parameterList RPAREN LBRACE varDeclarationList statementList RETURN expression SEMICOLON RBRACE{
                        printf("R16 ");
                        $$ = new Node("MethodDeclaration", "");
                        $$->children.push_back(new Node("", "public")); 
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("LPAREN", "("));
                        if($5) $$->children.push_back($5);
                        $$->children.push_back(new Node("RPAREN", ")"));
                        $$->children.push_back(new Node("LBRACE", "{"));
                        if($8) $$->children.push_back($8);
                        if($9) $$->children.push_back($9);
                        $$->children.push_back(new Node("", "return"));
                        $$->children.push_back($11);
                        $$->children.push_back(new Node("SEMICOLON", ";"));
                        $$->children.push_back(new Node("RBRACE", "}"));
                      }
        |           PUBLIC type identifier LPAREN parameterList RPAREN LBRACE statementList RETURN expression SEMICOLON RBRACE{
                        printf("R17 ");
                        $$ = new Node("MethodDeclaration", "");
                        $$->children.push_back(new Node("", "public")); 
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("LPAREN", "("));
                        if($5) $$->children.push_back($5);
                        $$->children.push_back(new Node("RPAREN", ")"));
                        $$->children.push_back(new Node("LBRACE", "{"));
                        if($8) $$->children.push_back($8);
                        $$->children.push_back(new Node("", "return"));
                        $$->children.push_back($10);
                        $$->children.push_back(new Node("SEMICOLON", ";"));
                        $$->children.push_back(new Node("RBRACE", "}"));
                      }       
         |           PUBLIC type identifier LPAREN parameterList RPAREN LBRACE varDeclarationList RETURN expression SEMICOLON RBRACE{
                        printf("R17 ");
                        $$ = new Node("MethodDeclaration", "");
                        $$->children.push_back(new Node("", "public")); 
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("LPAREN", "("));
                        if($5) $$->children.push_back($5);
                        $$->children.push_back(new Node("RPAREN", ")"));
                        $$->children.push_back(new Node("LBRACE", "{"));
                        if($8) $$->children.push_back($8);
                        $$->children.push_back(new Node("", "return"));
                        $$->children.push_back($10);
                        $$->children.push_back(new Node("SEMICOLON", ";"));
                        $$->children.push_back(new Node("RBRACE", "}"));
                      }
        |           PUBLIC type identifier LPAREN parameterList RPAREN LBRACE RETURN expression SEMICOLON RBRACE{
                        printf("R18 ");
                        $$ = new Node("MethodDeclaration", "");
                        $$->children.push_back(new Node("", "public")); 
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("LPAREN", "("));
                        if($5) $$->children.push_back($5);
                        $$->children.push_back(new Node("RPAREN", ")"));
                        $$->children.push_back(new Node("LBRACE", "{"));
                        $$->children.push_back(new Node("", "return"));
                        $$->children.push_back($9);
                        $$->children.push_back(new Node("SEMICOLON", ";"));
                        $$->children.push_back(new Node("RBRACE", "}"));
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
        | INT { $$ = new Node("TYPE", $1); printf("R22 ");}
        | BOOLEAN { $$ = new Node("TYPE", $1); printf("R23 ");}
        | INT LBRACKET RBRACKET {
                        printf("R24 ");
                        $$ = new Node("TypeVector", ""); 
                        $$->children.push_back(new Node("Type", "INT"));
                        $$->children.push_back(new Node("LBRACKET", "["));
                        $$->children.push_back(new Node("RBRACKET", "]"));
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

statement: LBRACE statementList RBRACE {
                        printf("R27 ");
                        $$ = new Node("Statement", ""); 
                        $$->children.push_back(new Node("LBRACE", "{"));
                        $$->children.push_back($2);
                        $$->children.push_back(new Node("RBRACE", "}"));
                      }
        | IF LPAREN expression RPAREN statement ELSE statement{
                        printf("R28 ");
                        $$ = new Node("IFStatement", ""); 
                        $$->children.push_back(new Node("IF", "if"));
                        $$->children.push_back(new Node("LPAREN", "("));
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("RPAREN", ")"));
                        $$->children.push_back($5);
                        $$->children.push_back(new Node("ELSE", "else"));
                        $$->children.push_back($7);
                      }
        | WHILE LPAREN expression RPAREN statement{
                        printf("R29 ");
                        $$ = new Node("WHILEStatement", ""); 
                        $$->children.push_back(new Node("WHILE", "while"));
                        $$->children.push_back(new Node("LPAREN", "("));
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("RPAREN", ")"));
                        $$->children.push_back($5);
                      }
        | PRINTLN LPAREN expression RPAREN SEMICOLON {
                        printf("R30 ");
                        $$ = new Node("PrintStatement", ""); 
                        $$->children.push_back(new Node("PRINT", "System.out.println"));
                        $$->children.push_back(new Node("LPAREN", "("));
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("RPAREN", ")"));
                        $$->children.push_back(new Node("SEMICOLON", ";"));
                      }
        | identifier EQUAL expression SEMICOLON{
                        printf("R31 ");
                        $$ = new Node("AssignmentStatement", "");
                        $$->children.push_back($1); 
                        $$->children.push_back(new Node("EQUAL", "="));
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("SEMICOLON", ";"));
                      }
        | identifier LBRACKET expression RBRACKET EQUAL expression SEMICOLON {
                        printf("R32 ");
                        $$ = new Node("VectorAssignmentStatement", "");
                        $$->children.push_back($1); 
                        $$->children.push_back(new Node("LBRACKET", "["));
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("RBRACKET", "]"));
                        $$->children.push_back(new Node("EQUAL", "="));
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
        | INTEGER_LITERAL { $$ = new Node("INTEGER", $1); printf("R36 ");} 
        | TRUE { $$ = new Node("LITERAL", $1); printf("R37 ");} 
        | FALSE { $$ = new Node("LITERAL", $1); printf("R38 ");} 
        | THIS { $$ = new Node("", $1); printf("R39 ");}  
        | expression LSS expression             {
                        printf("R40 ");
                        $$ = new Node("lssExpression", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("LSS", "<"));
                        $$->children.push_back($3);
                      
                      }
        | expression AND expression             {
                        printf("R41 ");
                        $$ = new Node("AndExpression", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("AND", "&&"));
                        $$->children.push_back($3);
                     
                      }
        | expression TIMES expression             {
                        printf("R42 ");
                        $$ = new Node("MultExpression", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("TIMES", "*"));
                        $$->children.push_back($3);
        
                      }
        | expression PLUS expression             {
                        printf("R43 ");
                        $$ = new Node("PlusExpression", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("PLUS", "+"));
                        $$->children.push_back($3);
        
                      }
        | expression MINUS expression             {
                        printf("R44 ");
                        $$ = new Node("MinusExpression", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("MINUS", "-"));
                        $$->children.push_back($3);
        
                      }
        | expression LBRACKET expression RBRACKET{
                        printf("R45 ");
                        $$ = new Node("VectorAccessExpression", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("LBRACKET", "["));
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("RBRACKET", "]"));
                      }
        | expression PERIOD LENGTH                {
                        printf("R46 ");
                        $$ = new Node("LengthExpression", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("PERIOD", "."));
                        $$->children.push_back(new Node("LENGTH", "length"));
                      }   
        | NEW INT LBRACKET expression RBRACKET                    {
                        printf("R47 ");
                        $$ = new Node("NewVectorExpression", "");
                        $$->children.push_back(new Node("NEW", "new"));
                        $$->children.push_back(new Node("INT", "int")); 
                        $$->children.push_back(new Node("LBRACKET", "["));
                        $$->children.push_back($4);
                        $$->children.push_back(new Node("RBRACKET", "]")); 
                      }  
        | NEW identifier LPAREN RPAREN           {
                        printf("R48 ");
                        $$ = new Node("NewClassExpression", "");
                        $$->children.push_back(new Node("NEW", "new"));
                        $$->children.push_back($2);
                        $$->children.push_back(new Node("LPAREN", "(")); 
                        $$->children.push_back(new Node("RPAREN", ")"));
                      }  
        | EXCLAMATION expression                 {
                        printf("R49 ");
                        $$ = new Node("ExclamationExpression", "");
                        $$->children.push_back(new Node("EXCLAMATION", "!"));
                        $$->children.push_back($2);
                      }  
        | LPAREN expression RPAREN                {
                        printf("R50 ");
                        $$ = new Node("ParenExpression", "");
                        $$->children.push_back(new Node("LPAREN", "("));
                        $$->children.push_back($2);
                        $$->children.push_back(new Node("RPAREN", ")"));
                      } 
        | expression PERIOD identifier LPAREN expressionList RPAREN{
                        printf("R51 ");
                        $$ = new Node("MethodCallExpression", "");
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("PERIOD", "."));
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("LPAREN", "("));
                        $$->children.push_back($5);
                        $$->children.push_back(new Node("RPAREN", ")"));
                      } 
        | expression PERIOD identifier LPAREN RPAREN{
                        printf("R52 ");
                        $$ = new Node("MethodCallExpressionWithoutArgs", "");
                        $$->children.push_back($1);
                        $$->children.push_back(new Node("PERIOD", "."));
                        $$->children.push_back($3);
                        $$->children.push_back(new Node("LPAREN", "("));
                        $$->children.push_back(new Node("RPAREN", ")"));
                      } 
        ;

identifier: IDENTIFIER {  $$ = new Node("Identifier", $1); printf("R53 %s ",$1.c_str());};