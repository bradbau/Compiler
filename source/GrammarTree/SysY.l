
%{
    //#include<stdio.h>
    //#include<stdlib.h>
    #include <iostream>
    #include "SysY.tab.h"

    #include "AST.h"

    int yycolumn = 1; 

    #define YY_USER_ACTION \
      yylloc.first_line = yylloc.last_line = yylineno; \
      yylloc.first_column = yycolumn; \
      yylloc.last_column = yycolumn + yyleng - 1; \
      yycolumn += yyleng;
    typedef union {
        class ASTTree *ast_Tree;
	  } YYLVAL;
    #define YYSTYPE YYLVAL
%}
%x COMMENT
%option yylineno
%option noyywrap


SPSEMICOLON     ";"
SPCOMMA         ","
SPDOT           "."
SPLEFTBRACE     "{"
SPRIGHTBRACE    "}"
OPLEFTPRNT      "("
OPRIGHTPRNT     ")"
OPLEFTBRACKET   "["
OPRIGHTBRACKET  "]"
OPPLUS          "+"
OPMINUS         "-"
OPMULTIPLY      "*"
OPDIVIDE        "/"
OPMOD           "%"   
OPASSIGN        "="
OPAND           "&&"
OPOR            "||"
OPNOT           "!"
OPEQUAL         "=="
OPNOTEQUAL      "!="
OPGREAT         ">"
OPLIGHT         "<"
OPGREATEQ       ">="
OPLIGHTEQ       "<="
TYPEVOID        "void"
TYPEINTEGER     "int"
KEYCONST        "const"  
KEYIF           "if"
KEYELSE         "else"
KEYWHILE        "while"
KEYBREAK        "break"
KEYCONTINUE     "continue" 
KEYRETURN       "return"
KEYGETINT       "getint"
KEYGETCHAR      "getchar"
KEYGETARRAY     "getarray"
KEYPUTINT       "putint"
KEYPUTCHAR      "putchar"
KEYPUTARRAY     "putarray"
KEYPUTF         "putf"
KEYSTARTTIME    "starttime"
KEYSTOPTIME     "stoptime"
CONSTANTOCT     0[0-7]*      
CONSTANTINTD    [1-9][0-9]*
CONSTANTINTH    0[xX][0-9a-fA-F]+
IDENTIFIER      [a-zA-Z][a-zA-Z0-9]* 
SPACE           " "|\t
EOL             \n
WRONGSTRING     \"[^\"\n]*$
WRONGIDENTIFIER [0-9_][a-zA-Z0-9_]* 
AERROR          .

%%
\/\*		{BEGIN(COMMENT);}
<COMMENT>\*\/ {BEGIN(INITIAL);}
<COMMENT>([^*]|\n)+|.
<COMMENT><<EOF>>	{printf("%s: %d: Unterminated comment\n", yytext, yylineno);return 0;}
"//".*\n
{SPSEMICOLON} {return SPSEMICOLON; }
{SPCOMMA} { return SPCOMMA; }
{SPDOT} {  return SPDOT; }
{SPLEFTBRACE} {return SPLEFTBRACE; }
{SPRIGHTBRACE} { return SPRIGHTBRACE; }
{OPLEFTPRNT} { return OPLEFTPRNT; }
{OPRIGHTPRNT} {  return OPRIGHTPRNT; }
{OPLEFTBRACKET} {  return OPLEFTBRACKET; }
{OPRIGHTBRACKET} { return OPRIGHTBRACKET; }
{OPPLUS} { return OPPLUS; }
{OPMINUS} {  return OPMINUS; }
{OPMULTIPLY} { return OPMULTIPLY; }
{OPDIVIDE} { return OPDIVIDE; }
{OPMOD} {   return OPMOD; }
{OPASSIGN} {  return OPASSIGN; }
{OPAND} {  return OPAND; }
{OPOR} {  return OPOR; }
{OPNOT} { return OPNOT; }
{OPEQUAL} { return OPEQUAL; }
{OPNOTEQUAL} {  return OPNOTEQUAL; }
{OPGREAT} {  return OPGREAT; }
{OPLIGHT} { return OPLIGHT; }
{OPGREATEQ} {  return OPGREATEQ; }
{OPLIGHTEQ} { return OPLIGHTEQ; }
{TYPEVOID} { return TYPEVOID; }
{TYPEINTEGER} {return TYPEINTEGER; }
{KEYIF} { return KEYIF; }
{KEYELSE} {  return KEYELSE; }
{KEYWHILE} { return KEYWHILE; }
{KEYBREAK} { return KEYBREAK; }
{KEYCONTINUE} {return KEYCONTINUE ; }
{KEYCONST} {  return KEYCONST ; }
{KEYGETINT}  { return KEYGETINT; }    
{KEYGETCHAR}    { return KEYGETCHAR; }
{KEYGETARRAY}   {  return KEYGETARRAY; }
{KEYPUTINT}      { return KEYPUTINT; }
{KEYPUTCHAR}     {return KEYPUTCHAR; }
{KEYPUTARRAY}    { return KEYPUTARRAY; }
{KEYPUTF}         { return KEYPUTF; }
{KEYSTARTTIME}    {  return KEYSTARTTIME; }
{KEYSTOPTIME}     { return SPSEMICOLON; }
{KEYRETURN} {return KEYRETURN; }
{CONSTANTINTD} { ASTTree *asttree = new ASTTree("CONSTANTINTD", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return CONSTANTINTD; }
{CONSTANTINTH} { ASTTree *asttree = new ASTTree("CONSTANTINTH", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return CONSTANTINTH; }
{CONSTANTOCT} {  ASTTree *asttree = new ASTTree("CONSTANTOCT", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree;return CONSTANTOCT ; }
{IDENTIFIER} { ASTTree *asttree = new ASTTree("IDENTIFIER", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return IDENTIFIER; }

{SPACE} {}
{EOL} { yycolumn = 1; }
{WRONGSTRING} { printf("Lexical lrror at Line %d column %d: Missing \"\"\".\n", yylineno, yylloc.last_column); exit(-1); }
{WRONGIDENTIFIER} { printf("Lexical Error at Line %d column %d: Wrong format of identifier.\n", yylineno, yylloc.first_column); exit(-1); }
{AERROR} { printf("Lexical Error at Line %d column %d: Mysterious characters \"%s\".\n", yylineno, yylloc.first_column, yytext); exit(-1); }
%%
/*
int yywrap()
{
  return 1;
}*/
