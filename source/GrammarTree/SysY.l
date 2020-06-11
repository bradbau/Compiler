/* utf-8 */

%{
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
{SPSEMICOLON} {printf("<;>\n");return SPSEMICOLON; }
{SPCOMMA} { printf("<,>\n");return SPCOMMA; }
{SPDOT} {  printf("<.>\n");return SPDOT; }
{SPLEFTBRACE} {printf("<{>\n");return SPLEFTBRACE; }
{SPRIGHTBRACE} { printf("<}>\n");return SPRIGHTBRACE; }
{OPLEFTPRNT} { printf("<(>\n");return OPLEFTPRNT; }
{OPRIGHTPRNT} {  printf("<)>\n");return OPRIGHTPRNT; }
{OPLEFTBRACKET} {  printf("<[>\n");return OPLEFTBRACKET; }
{OPRIGHTBRACKET} { printf("<]>\n");return OPRIGHTBRACKET; }
{OPPLUS} { printf("<+>\n");return OPPLUS; }
{OPMINUS} {  printf("<->\n");return OPMINUS; }
{OPMULTIPLY} { printf("<*>\n");return OPMULTIPLY; }
{OPDIVIDE} { printf("</>\n");return OPDIVIDE; }
{OPMOD} {   printf("<%%>\n");return OPMOD; }
{OPASSIGN} {  printf("<=>\n");return OPASSIGN; }
{OPAND} {  printf("<&&>\n");return OPAND; }
{OPOR} {  printf("<||>\n");return OPOR; }
{OPNOT} { printf("<!>\n");return OPNOT; }
{OPEQUAL} { printf("<==>\n");return OPEQUAL; }
{OPNOTEQUAL} {  printf("<!=>\n");return OPNOTEQUAL; }
{OPGREAT} {  printf("<>>\n");return OPGREAT; }
{OPLIGHT} { printf("<<>\n");return OPLIGHT; }
{OPGREATEQ} {  printf("<>=>\n");return OPGREATEQ; }
{OPLIGHTEQ} { printf("<<=>\n");return OPLIGHTEQ; }
{TYPEVOID} { printf("<void>\n");return TYPEVOID; }
{TYPEINTEGER} {printf("<int>\n");return TYPEINTEGER; }
{KEYIF} { printf("<if>\n");return KEYIF; }
{KEYELSE} {  printf("<else>\n");return KEYELSE; }
{KEYWHILE} { printf("<while>\n");return KEYWHILE; }
{KEYBREAK} { printf("<break>\n");return KEYBREAK; }
{KEYCONTINUE} {printf("<continue>\n");return KEYCONTINUE ; }
{KEYCONST} {  printf("<const>\n");return KEYCONST ; }
{KEYGETINT}  { printf("<getint>\n");return KEYGETINT; }    
{KEYGETCHAR}    { printf("<getchar>\n");return KEYGETCHAR; }
{KEYGETARRAY}   {  printf("<getarray>\n");return KEYGETARRAY; }
{KEYPUTINT}      { printf("<putint>\n");return KEYPUTINT; }
{KEYPUTCHAR}     {printf("<putchar>\n");return KEYPUTCHAR; }
{KEYPUTARRAY}    { printf("<putarray>\n");return KEYPUTARRAY; }
{KEYPUTF}         { printf("<putf>\n");return KEYPUTF; }
{KEYSTARTTIME}    {  printf("<starttime>\n");return KEYSTARTTIME; }
{KEYSTOPTIME}     { printf("<stoptime>\n");return SPSEMICOLON; }
{KEYRETURN} {printf("<return>\n");return KEYRETURN; }
{CONSTANTINTD} { printf("<intd>\n");ASTTree *asttree = new ASTTree("CONSTANTINTD", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return CONSTANTINTD; }
{CONSTANTINTH} { printf("<inth>\n");ASTTree *asttree = new ASTTree("CONSTANTINTH", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return CONSTANTINTH; }
{CONSTANTOCT} {  printf("<into>\n");ASTTree *asttree = new ASTTree("CONSTANTOCT", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree;return CONSTANTOCT ; }
{IDENTIFIER} { printf("<id,%s>\n",yytext);ASTTree *asttree = new ASTTree("IDENTIFIER", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return IDENTIFIER; }

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
