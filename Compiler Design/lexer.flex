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

"["                     {return yy::parser::make_LSQUAREP(yytext);}
"]"                     {return yy::parser::make_RSQUAREP(yytext);}
"{"                     {return yy::parser::make_LBRACKET(yytext);}
"}"                     {return yy::parser::make_RBRACKET(yytext);}
"("                     {return yy::parser::make_LP(yytext);}
")"                     {return yy::parser::make_RP(yytext);}
";"                     {return yy::parser::make_SEMICOLON(yytext);}
","                     {return yy::parser::make_COMMA(yytext);}
"="                     {return yy::parser::make_EQUALS(yytext);}
"&&"                    {return yy::parser::make_AND(yytext);}
"||"                    {return yy::parser::make_OR(yytext);}
"<"                     {return yy::parser::make_LESSER(yytext);}
">"                     {return yy::parser::make_GREATER(yytext);}
"=="                    {return yy::parser::make_ASSIGNOP(yytext);}
"+"                     {return yy::parser::make_PLUSOP(yytext);}
"-"                     {return yy::parser::make_MINUSOP(yytext);}
"*"                     {return yy::parser::make_MULTOP(yytext);}
"/"                     {return yy::parser::make_DIVISIONOP(yytext);}
"."                     {return yy::parser::make_PERIOD(yytext);}
"!"                     {return yy::parser::make_NOT(yytext);}

"int"|"INT"             {return yy::parser::make_INTEGER(yytext);}
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
"String"                   {return yy::parser::make_STRING(yytext);}
"System.out.println"    {return yy::parser::make_PRINT(yytext);}

"if"                    {return yy::parser::make_IF(yytext);}
"else"                  {return yy::parser::make_ELSE(yytext);}
"while"                 {return yy::parser::make_WHILE(yytext);}

{identifier}            {return yy::parser::make_IDENTIFIER(yytext);}
{integer_literal}       {return yy::parser::make_INT(yytext);}     

["]                     {BEGIN STRING;}
<STRING>["]             {BEGIN INITIAL;}
<STRING>[^"]*           {return yy::parser::make_STRINGS(yytext);}

{ws}                    
{comment}  

.                       {printf("UNKNOWN CHARACTER: %s\n", yytext); return 1;}

<<EOF>>                 return yy::parser::make_END();
%%