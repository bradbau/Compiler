%{
    #include<stdio.h>
    #include<stdlib.h>

    int yycolumn = 1;    
    #define YY_USER_ACTION \
      yylloc.first_line = yylloc.last_line = yylineno; \
      yylloc.first_column = yycolumn; \
      yylloc.last_column = yycolumn + yyleng - 1; \
      yycolumn += yyleng;
%}

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
OPMOD           "%"   //new
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
KEYCONST        "const"  //new
KEYIF           "if"
KEYELSE         "else"
KEYWHILE        "while"
KEYBREAK        "break"
KEYCONTINUE     "continue" //new
KEYRETURN       "return"
CONSTANTNULL    "null"
CONSTANTOCT     [+-]?0[0-7]*      //new
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
{SPSEMICOLON} { yylval.grammar_tree = CreateGrammarTree("SPSEMICOLON", 0, yylineno, yylloc.first_column); return SPSEMICOLON; }
{SPCOMMA} { yylval.grammar_tree = CreateGrammarTree("SPCOMMA", 0, yylineno, yylloc.first_column); return SPCOMMA; }
{SPDOT} { yylval.grammar_tree = CreateGrammarTree("SPDOT", 0, yylineno, yylloc.first_column); return SPDOT; }
{SPLEFTBRACE} { yylval.grammar_tree = CreateGrammarTree("SPLEFTBRACE", 0, yylineno, yylloc.first_column); return SPLEFTBRACE; }
{SPRIGHTBRACE} { yylval.grammar_tree = CreateGrammarTree("SPRIGHTBRACE", 0, yylineno, yylloc.first_column); return SPRIGHTBRACE; }
{OPLEFTPRNT} { yylval.grammar_tree = CreateGrammarTree("OPLEFTPRNT", 0, yylineno, yylloc.first_column); return OPLEFTPRNT; }
{OPRIGHTPRNT} { yylval.grammar_tree = CreateGrammarTree("OPRIGHTPRNT", 0, yylineno, yylloc.first_column); return OPRIGHTPRNT; }
{OPLEFTBRACKET} { yylval.grammar_tree = CreateGrammarTree("OPLEFTBRACKET", 0, yylineno, yylloc.first_column); return OPLEFTBRACKET; }
{OPRIGHTBRACKET} { yylval.grammar_tree = CreateGrammarTree("OPRIGHTBRACKET", 0, yylineno, yylloc.first_column); return OPRIGHTBRACKET; }
{OPPLUS} { yylval.grammar_tree = CreateGrammarTree("OPPLUS", 0, yylineno, yylloc.first_column); return OPPLUS; }
{OPMINUS} { yylval.grammar_tree = CreateGrammarTree("OPMINUS", 0, yylineno, yylloc.first_column); return OPMINUS; }
{OPMULTIPLY} { yylval.grammar_tree = CreateGrammarTree("OPMULTIPLY", 0, yylineno, yylloc.first_column); return OPMULTIPLY; }
{OPDIVIDE} { yylval.grammar_tree = CreateGrammarTree("OPDIVIDE", 0, yylineno, yylloc.first_column); return OPDIVIDE; }
{OPMOD} {  return OPMOD; }
{OPASSIGN} { yylval.grammar_tree = CreateGrammarTree("OPASSIGN", 0, yylineno, yylloc.first_column); return OPASSIGN; }
{OPAND} { yylval.grammar_tree = CreateGrammarTree("OPAND", 0, yylineno, yylloc.first_column); return OPAND; }
{OPOR} { yylval.grammar_tree = CreateGrammarTree("OPOR", 0, yylineno, yylloc.first_column); return OPOR; }
{OPNOT} { yylval.grammar_tree = CreateGrammarTree("OPNOT", 0, yylineno, yylloc.first_column); return OPNOT; }
{OPEQUAL} { yylval.grammar_tree = CreateGrammarTree("OPEQUAL", 0, yylineno, yylloc.first_column); return OPEQUAL; }
{OPNOTEQUAL} { yylval.grammar_tree = CreateGrammarTree("OPNOTEQUAL", 0, yylineno, yylloc.first_column); return OPNOTEQUAL; }
{OPGREAT} { yylval.grammar_tree = CreateGrammarTree("OPGREAT", 0, yylineno, yylloc.first_column); return OPGREAT; }
{OPLIGHT} { yylval.grammar_tree = CreateGrammarTree("OPLIGHT", 0, yylineno, yylloc.first_column); return OPLIGHT; }
{OPGREATEQ} { yylval.grammar_tree = CreateGrammarTree("OPGREATEQ", 0, yylineno, yylloc.first_column); return OPGREATEQ; }
{OPLIGHTEQ} { yylval.grammar_tree = CreateGrammarTree("OPLIGHTEQ", 0, yylineno, yylloc.first_column); return OPLIGHTEQ; }
{TYPEVOID} { yylval.grammar_tree = CreateGrammarTree("TYPEVOID", 0, yylineno, yylloc.first_column); return TYPEVOID; }
{TYPEINTEGER} { yylval.grammar_tree = CreateGrammarTree("TYPEINTEGER", 0, yylineno, yylloc.first_column); return TYPEINTEGER; }
{KEYIF} { yylval.grammar_tree = CreateGrammarTree("KEYIF", 0, yylineno, yylloc.first_column); return KEYIF; }
{KEYELSE} { yylval.grammar_tree = CreateGrammarTree("KEYELSE", 0, yylineno, yylloc.first_column); return KEYELSE; }
{KEYFOR} { yylval.grammar_tree = CreateGrammarTree("KEYFOR", 0, yylineno, yylloc.first_column); return KEYFOR; }
{KEYWHILE} { yylval.grammar_tree = CreateGrammarTree("KEYWHILE", 0, yylineno, yylloc.first_column); return KEYWHILE; }
{KEYBREAK} { yylval.grammar_tree = CreateGrammarTree("KEYBREAK", 0, yylineno, yylloc.first_column); return KEYBREAK; }
{KEYCONTINUE} {  return KEYCONTINUE ; }
{KEYCONST} {  return KEYCONST ; }
{KEYRETURN} { yylval.grammar_tree = CreateGrammarTree("KEYRETURN", 0, yylineno, yylloc.first_column); return KEYRETURN; }
{CONSTANTNULL} { yylval.grammar_tree = CreateGrammarTree("CONSTANTNULL", 0, yylineno, yylloc.first_column); return CONSTANTNULL; }
{CONSTANTINTD} { yylval.grammar_tree = CreateGrammarTree("CONSTANTINTD", 0, yylineno, yylloc.first_column); return CONSTANTINTD; }
{CONSTANTINTH} { yylval.grammar_tree = CreateGrammarTree("CONSTANTINTH", 0, yylineno, yylloc.first_column); return CONSTANTINTH; }
{CONSTANTOCT} {  return CONSTANTOCT ; }
{IDENTIFIER} { yylval.grammar_tree = CreateGrammarTree("IDENTIFIER", 0, yylineno, yylloc.first_column); return IDENTIFIER; }
{COMMENT} {}
{SPACE} {}
{EOL} { yycolumn = 1; }
{WRONGSTRING} { printf("Lexical lrror at Line %d column %d: Missing \"\"\".\n", yylineno, yylloc.last_column); exit(-1); }
{WRONGIDENTIFIER} { printf("Lexical Error at Line %d column %d: Wrong format of identifier.\n", yylineno, yylloc.first_column); exit(-1); }
{AERROR} { printf("Lexical Error at Line %d column %d: Mysterious characters \"%s\".\n", yylineno, yylloc.first_column, yytext); exit(-1); }
%%
