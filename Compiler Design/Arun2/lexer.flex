%top{
#include "parser.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
#include "Node.h"
} 
%option noyywrap nounput batch noinput stack

            
identifier [A-Za-z]([A-Za-z]|[0-9]|_)*
integer_literal 0|[1-9](0|[1-9])*

ws [ \t\n\r]
comment "//".*

%x STRING

%%

"["                     {return yy::parser::make_LBRACKET(yytext);}
"]"                     {return yy::parser::make_RBRACKET(yytext);}
"{"                     {return yy::parser::make_LBRACE(yytext);}
"}"                     {return yy::parser::make_RBRACE(yytext);}
"("                     {return yy::parser::make_LPAREN(yytext);}
")"                     {return yy::parser::make_RPAREN(yytext);}
";"                     {return yy::parser::make_SEMICOLON(yytext);}
","                     {return yy::parser::make_COMMA(yytext);}
"="                     {return yy::parser::make_EQUAL(yytext);}
"&&"                    {return yy::parser::make_AND(yytext);}
"<"                     {return yy::parser::make_LSS(yytext);}
"+"                     {return yy::parser::make_PLUS(yytext);}
"-"                     {return yy::parser::make_MINUS(yytext);}
"*"                     {return yy::parser::make_TIMES(yytext);}
"."                     {return yy::parser::make_PERIOD(yytext);}
"!"                     {return yy::parser::make_EXCLAMATION(yytext);}

"int"|"INT"             {return yy::parser::make_INT(yytext);}
"boolean"|"BOOLEAN"     {return yy::parser::make_BOOLEAN(yytext);}

"true"                  {return yy::parser::make_TRUE(yytext);}
"false"                 {return yy::parser::make_FALSE(yytext);}

"class"                 {return yy::parser::make_CLASS(yytext);}
"public"                {return yy::parser::make_PUBLIC(yytext);}
"static"                {return yy::parser::make_STATIC(yytext);}
"extends"               {return yy::parser::make_EXTENDS(yytext);}
"void"                  {return yy::parser::make_VOID(yytext);}
"main"                  {return yy::parser::make_MAIN(yytext);}
"return"                {return yy::parser::make_RETURN(yytext);}
"length"                {return yy::parser::make_LENGTH(yytext);}
"this"                  {return yy::parser::make_THIS(yytext);}
"new"                   {return yy::parser::make_NEW(yytext);}
"String"                   {return yy::parser::make_WORDSTRING(yytext);}
"System.out.println"    {return yy::parser::make_PRINTLN(yytext);}

"if"                    {return yy::parser::make_IF(yytext);}
"else"                  {return yy::parser::make_ELSE(yytext);}
"while"                 {return yy::parser::make_WHILE(yytext);}

{identifier}            {return yy::parser::make_IDENTIFIER(yytext);}
{integer_literal}       {return yy::parser::make_INTEGER_LITERAL(yytext);}     

["]                     {BEGIN STRING;}
<STRING>["]             {BEGIN INITIAL;}
<STRING>[^"]*           {return yy::parser::make_STRING(yytext);}

{ws}                    
{comment}  

.                       {printf("UNKNOWN CHARACTER: %s\n", yytext); return 1;}

<<EOF>>                 return yy::parser::make_END();
%%