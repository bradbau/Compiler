%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "SysY.tab.h"
    //#include "grammartree.cpp"
    #include "grammartree.h"

    int yycolumn = 1;    
    #define YY_USER_ACTION \
      yylloc.first_line = yylloc.last_line = yylineno; \
      yylloc.first_column = yycolumn; \
      yylloc.last_column = yycolumn + yyleng - 1; \
      yycolumn += yyleng;
    typedef union {
        int i;
	      struct Grammartree *grammartree;
        class ASTTree *ast_Tree;
	  } YYLVAL;
    #define YYSTYPE YYLVAL
%}
%option c++
%option yylineno

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
CONSTANTOCT     [+-]?0[0-7]*      
CONSTANTINTD    [+-]?[1-9][0-9]*
CONSTANTINTH    [+-]?0[xX][0-9a-fA-F]+
IDENTIFIER      [a-zA-Z][a-zA-Z0-9]* 
COMMENT         (\/\/.*)|(\/\*((\*[^\/]?)|[^\*]*)*\*\/)
SPACE           " "|\t
EOL             \n
WRONGSTRING     \"[^\"\n]*$
WRONGIDENTIFIER [0-9_][a-zA-Z0-9_]* 
AERROR          .

%%
{SPSEMICOLON} { ASTTree *asttree = new ASTTree("SPSEMICOLON", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return SPSEMICOLON; }
{SPCOMMA} { ASTTree *asttree = new ASTTree("SPCOMMA", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return SPCOMMA; }
{SPDOT} { ASTTree *asttree = new ASTTree("SPDOT", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return SPDOT; }
{SPLEFTBRACE} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("SPLEFTBRACE", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return SPLEFTBRACE; }
{SPRIGHTBRACE} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("SPRIGHTBRACE", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return SPRIGHTBRACE; }
{OPLEFTPRNT} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("OPLEFTPRNT", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return OPLEFTPRNT; }
{OPRIGHTPRNT} { ASTTree* asttree = new ASTTree();asttree->CreateGrammarTree("OPRIGHTPRNT", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return OPRIGHTPRNT; }
{OPLEFTBRACKET} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("OPLEFTBRACKET", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return OPLEFTBRACKET; }
{OPRIGHTBRACKET} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("OPRIGHTBRACKET", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return OPRIGHTBRACKET; }
{OPPLUS} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("OPPLUS", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return OPPLUS; }
{OPMINUS} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("OPMINUS", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return OPMINUS; }
{OPMULTIPLY} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("OPMULTIPLY", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return OPMULTIPLY; }
{OPDIVIDE} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("OPDIVIDE", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return OPDIVIDE; }
{OPMOD} {  ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("OPMOD", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return OPMOD; }
{OPASSIGN} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("OPASSIGN", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return OPASSIGN; }
{OPAND} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("OPAND", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return OPAND; }
{OPOR} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("OPOR", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return OPOR; }
{OPNOT} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("OPNOT", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return OPNOT; }
{OPEQUAL} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("OPEQUAL", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return OPEQUAL; }
{OPNOTEQUAL} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("OPNOTEQUAL", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return OPNOTEQUAL; }
{OPGREAT} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("OPGREAT", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return OPGREAT; }
{OPLIGHT} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("OPLIGHT", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return OPLIGHT; }
{OPGREATEQ} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("OPGREATEQ", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return OPGREATEQ; }
{OPLIGHTEQ} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("OPLIGHTEQ", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return OPLIGHTEQ; }
{TYPEVOID} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("TYPEVOID", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return TYPEVOID; }
{TYPEINTEGER} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("TYPEINTEGER", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return TYPEINTEGER; }
{KEYIF} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("KEYIF", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return KEYIF; }
{KEYELSE} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("KEYELSE", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return KEYELSE; }
{KEYWHILE} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("KEYWHILE", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return KEYWHILE; }
{KEYBREAK} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("KEYBREAK", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return KEYBREAK; }
{KEYCONTINUE} {  ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("KEYCONTINUE", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree;return KEYCONTINUE ; }
{KEYCONST} {  ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("KEYCONST", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree;return KEYCONST ; }
{KEYRETURN} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("KEYRETURN", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return KEYRETURN; }
{CONSTANTINTD} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("CONSTANTINTD", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return CONSTANTINTD; }
{CONSTANTINTH} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("CONSTANTINTH", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return CONSTANTINTH; }
{CONSTANTOCT} {  ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("CONSTANTOCT", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree;return CONSTANTOCT ; }
{IDENTIFIER} { ASTTree *asttree = new ASTTree();asttree->CreateGrammarTree("IDENTIFIER", 0, yylineno, yylloc.first_column);yylval.ast_Tree = asttree; return IDENTIFIER; }
{COMMENT} {}
{SPACE} {}
{EOL} { yycolumn = 1; }
{WRONGSTRING} { printf("Lexical lrror at Line %d column %d: Missing \"\"\".\n", yylineno, yylloc.last_column); exit(-1); }
{WRONGIDENTIFIER} { printf("Lexical Error at Line %d column %d: Wrong format of identifier.\n", yylineno, yylloc.first_column); exit(-1); }
{AERROR} { printf("Lexical Error at Line %d column %d: Mysterious characters \"%s\".\n", yylineno, yylloc.first_column, yytext); exit(-1); }
%%

int yywrap()
{
return 1;
}
