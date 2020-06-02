/* utf-8 */
%error-verbose
%locations

%{
    //#include<stdio.h>
    //#include<unistd.h>
    #include <iostream>
    //#include"lex.yy.cc"
    //#include "grammartree.cpp"
    #include "grammartree.h"
    using namespace std;
    //extern "C"
    
    //int yyparse();
    extern int yylineno; //共用
    extern int yylex();
    extern FILE *yyin;
    extern char *yytext;
    extern int yydebug;
    extern int yywrap(void);
    void yyerror(const char* fmt, ...);
    
    
    
%}

%union {

    class ASTTree *ast_Tree;
}



%type <ast_Tree> Compiler CompUnits CompUnit Decl ConstDecl VarDecl ConstDef ConstDefs ArrayDef ConstInitVal ConstInitValList
%type <ast_Tree> VarDef VarDefs InitVal InitVals FuncDef FuncFParams FuncFParam ArrayExps 
%type <ast_Tree> Block BlockItems BlockItem Stmt Exp Exps Cond LVal PrimaryExp Number IntConst UnaryExp UnaryOp 
%type <ast_Tree> FuncRParams MulExp AddExp RelExp EqExp LAndExp LOrExp ConstExp

%token <ast_Tree> SPSEMICOLON SPCOMMA SPDOT SPLEFTBRACE SPRIGHTBRACE
%token <ast_Tree> OPLEFTPRNT OPRIGHTPRNT OPLEFTBRACKET OPRIGHTBRACKET
%token <ast_Tree> OPPLUS OPMINUS OPMULTIPLY OPDIVIDE OPMOD OPASSIGN
%token <ast_Tree> OPAND OPOR OPNOT
%token <ast_Tree> OPEQUAL OPNOTEQUAL OPGREAT OPLIGHT OPGREATEQ OPLIGHTEQ
%token <ast_Tree> TYPEVOID TYPEINTEGER KEYCONST
%token <ast_Tree> KEYIF KEYELSE KEYWHILE KEYBREAK KEYCONTINUE
%token <ast_Tree> KEYRETURN KEYGETINT KEYGETCHAR KEYGETARRAY KEYPUTINT KEYPUTCHAR KEYPUTARRAY KEYPUTF
%token <ast_Tree> KEYSTOPTIME KEYSTARTTIME
%token <ast_Tree> CONSTANTINTD CONSTANTINTH CONSTANTOCT
%token <ast_Tree> IDENTIFIER


%left OPOR 
%left OPAND 
%left OPEQUAL OPNOTEQUAL 
%right OPASSIGN 
%left OPLIGHT OPLIGHTEQ OPGREAT OPGREATEQ 
%left OPPLUS OPMINUS 
%left OPMULTIPLY OPDIVIDE OPMOD 
%right OPNOT 
%left OPRIGHTBRACKET OPLEFTBRACKET OPRIGHTPRNT OPLEFTPRNT SPDOT

%nonassoc KEYELSE 

%%
/*add new*/
Compiler: CompUnits { ASTTree *asttree = new ASTTree("Compiler", 1, $1);$$ = asttree; asttree->TraverseGrammerTree(0);}
        ;
CompUnits:{ ASTTree *asttree = new ASTTree("CompUnit",0, -1);$$ = asttree;}
         | CompUnit CompUnits{ ASTTree *asttree = new ASTTree("CompUnits", 2, $1,$2);$$ = asttree; }
         ;
CompUnit: Decl{ ASTTree *asttree = new ASTTree("CompUnit", 1, $1);$$ = asttree;}
         | FuncDef { ASTTree *asttree = new ASTTree("CompUnit", 1, $1);$$ = asttree; }
         ;
/*声明*/
Decl:  ConstDecl { ASTTree *asttree = new ASTTree("Decl", 1, $1);$$ = asttree; }
      | VarDecl{ ASTTree *asttree = new ASTTree("Decl", 1, $1);$$ = asttree; }
      ;

/*常量声明*/ 
ConstDecl: KEYCONST TYPEINTEGER ConstDef ConstDefs SPSEMICOLON{ ASTTree *asttree = new ASTTree("ConstDecl", 5, $1, $2,$3,$4,$5);$$ = asttree; }
          ;
/*常量列表，自行添加的*/
ConstDefs: { ASTTree *asttree = new ASTTree("ConstDefs", 0, -1);$$ = asttree; }
          | ConstDefs SPCOMMA ConstDef { ASTTree *asttree = new ASTTree("ConstDefs", 3, $1, $2,$3);$$ = asttree; }
          ;
/*常数定义*/ 
ConstDef: IDENTIFIER ArrayDef OPASSIGN ConstInitVal{ ASTTree *asttree = new ASTTree("ConstDef", 4, $1, $2,$3,$4);$$ = asttree; }
         ;
ArrayDef:{ ASTTree *asttree = new ASTTree("ArrayDef", 0, -1);$$ = asttree; }
        | ArrayDef OPLEFTBRACKET ConstExp OPRIGHTBRACKET{ ASTTree *asttree = new ASTTree("ArrayDef", 4, $1, $2,$3,$4);$$ = asttree; }
        ;
/*常量初值*/ 
ConstInitVal:ConstExp { ASTTree *asttree = new ASTTree("ConstInitVal", 1, $1);$$ = asttree; }
             | SPLEFTBRACE SPRIGHTBRACE{ ASTTree *asttree = new ASTTree("ConstInitVal", 2, $1, $2);$$ = asttree; }
             | SPLEFTBRACE ConstInitVal ConstInitValList SPRIGHTBRACE{ ASTTree *asttree = new ASTTree("ConstInitVal", 4, $1, $2,$3,$4);$$ = asttree; }
             ;
/*常量初值列表中间用量，自己添加的*/
ConstInitValList:{ ASTTree *asttree = new ASTTree("ConstInitValList", 0, -1);$$ = asttree; }
                |ConstInitValList SPCOMMA ConstInitVal{ ASTTree *asttree = new ASTTree("ConstInitValList", 3, $1,$2,$3);$$ = asttree; }
                ;

/*变量声明*/ 
VarDecl: TYPEINTEGER VarDef VarDefs SPSEMICOLON{ ASTTree *asttree = new ASTTree("VarDecl", 4, $1,$2,$3,$4);$$ = asttree; }
        ;
/*变量定义*/
VarDef:IDENTIFIER ArrayDef{ ASTTree *asttree = new ASTTree("VarDef", 2, $1,$2);$$ = asttree; }
       | IDENTIFIER ArrayDef OPASSIGN InitVal{ ASTTree *asttree = new ASTTree("VarDef", 4, $1,$2,$3,$4);$$ = asttree; }
/*变量声明列表，自行添加*/
VarDefs:{ ASTTree *asttree = new ASTTree("VarDefs", 0, -1);$$ = asttree; }
       | VarDefs SPCOMMA VarDef{ ASTTree *asttree = new ASTTree("VarDefs", 3, $1,$2,$3);$$ = asttree; }
       ;
/*变量初值*/ 
InitVal: Exp { ASTTree *asttree = new ASTTree("InitVal", 1, $1);$$ = asttree; }
       | SPLEFTBRACE SPRIGHTBRACE{ ASTTree *asttree = new ASTTree("InitVal", 2, $1,$2);$$ = asttree; }
       | SPLEFTBRACE InitVal InitVals SPRIGHTBRACE{ ASTTree *asttree = new ASTTree("InitVal", 4, $1,$2,$3,$4);$$ = asttree; }
       ;
/*变量初值列表，自己添加的*/
InitVals: { ASTTree *asttree = new ASTTree("InitVals", 0, -1);$$ = asttree; }
        | InitVals SPCOMMA InitVal{ ASTTree *asttree = new ASTTree("InitVals", 3, $1,$2,$3);$$ = asttree; }
        ;

/*函数定义*/ 
FuncDef:TYPEVOID IDENTIFIER OPLEFTPRNT OPRIGHTPRNT Block{ ASTTree *asttree = new ASTTree("FuncDef", 5, $1,$2,$3,$4,$5);$$ = asttree; }
        |TYPEINTEGER IDENTIFIER OPLEFTPRNT OPRIGHTPRNT Block{ ASTTree *asttree = new ASTTree("FuncDef", 5, $1,$2,$3,$4,$5);$$ = asttree; }
        |TYPEVOID IDENTIFIER OPLEFTPRNT FuncFParams OPRIGHTPRNT Block{ ASTTree *asttree = new ASTTree("FuncDef", 6, $1,$2,$3,$4,$5,$6);$$ = asttree; }
        |TYPEINTEGER IDENTIFIER OPLEFTPRNT FuncFParams OPRIGHTPRNT Block{ ASTTree *asttree = new ASTTree("FuncDef", 6, $1,$2,$3,$4,$5,$6);$$ = asttree; }
        ;

/*函数形参*/ 
FuncFParam: TYPEINTEGER IDENTIFIER{ ASTTree *asttree = new ASTTree("FuncFParam", 2, $1,$2);$$ = asttree; }
          | TYPEINTEGER IDENTIFIER OPLEFTBRACKET OPRIGHTBRACKET ArrayExps{ ASTTree *asttree = new ASTTree("FuncFParam", 5, $1,$2,$3,$4,$5);$$ = asttree; }
          ;
/*函数形参表*/ 
FuncFParams: FuncFParam { ASTTree *asttree = new ASTTree("FuncFParams", 1, $1);$$ = asttree; }
            | FuncFParams SPCOMMA FuncFParam{ ASTTree *asttree = new ASTTree("FuncFParams", 3, $1,$2,$3);$$ = asttree; }
            ;
/*数组维度*/
ArrayExps:{ ASTTree *asttree = new ASTTree("ArrayExps", 0, -1);$$ = asttree; }
         |ArrayExps OPLEFTBRACKET Exp OPRIGHTBRACKET{ ASTTree *asttree = new ASTTree("ArrayExps", 4, $1,$2,$3,$4);$$ = asttree; }
         ;
/*语句块*/ 
Block:SPLEFTBRACE BlockItems SPRIGHTBRACE{ ASTTree *asttree = new ASTTree("Block", 3, $1,$2,$3);$$ = asttree; }
      ;
/*语句块列表*/
BlockItems:{ ASTTree *asttree = new ASTTree("BlockItems", 0, -1);$$ = asttree; } 
           | BlockItem BlockItems  { ASTTree *asttree = new ASTTree("BlockItems", 2, $1,$2);$$ = asttree; }
           ;
/*语句块项*/ 
BlockItem:Decl { ASTTree *asttree = new ASTTree("BlockItem", 1, $1);$$ = asttree; }
         | Stmt { ASTTree *asttree = new ASTTree("BlockItem", 1, $1);$$ = asttree; }
         ;
/*语句*/ 
Stmt: LVal OPASSIGN Exp SPSEMICOLON { ASTTree *asttree = new ASTTree("Stmt", 4, $1,$2,$3,$4);$$ = asttree; }
      | SPSEMICOLON { ASTTree *asttree = new ASTTree("Stmt", 1, $1);$$ = asttree; }
      | Exp SPSEMICOLON { ASTTree *asttree = new ASTTree("Stmt", 2, $1,$2);$$ = asttree; }
      | Block { ASTTree *asttree = new ASTTree("Stmt", 1, $1);$$ = asttree; }
      | KEYIF OPLEFTPRNT Cond OPRIGHTPRNT Stmt { ASTTree *asttree = new ASTTree("Stmt", 5, $1,$2,$3,$4,$5);$$ = asttree; }
      | KEYIF OPLEFTPRNT Cond OPRIGHTPRNT Stmt KEYELSE Stmt { ASTTree *asttree = new ASTTree("Stmt", 7,$1,$2,$3,$4,$5,$6,$7);$$ = asttree; }
      | KEYWHILE OPLEFTPRNT Cond OPRIGHTPRNT Stmt { ASTTree *asttree = new ASTTree("Stmt", 5,  $1,$2,$3,$4,$5);$$ = asttree; }
      | KEYBREAK SPSEMICOLON { ASTTree *asttree = new ASTTree("Stmt", 2, $1,$2);$$ = asttree; }
      | KEYCONTINUE SPSEMICOLON { ASTTree *asttree = new ASTTree("Stmt", 2, $1,$2);$$ = asttree; }
      | KEYRETURN  SPSEMICOLON { ASTTree *asttree = new ASTTree("Stmt", 2, $1,$2);$$ = asttree; }
      | KEYRETURN  Exp SPSEMICOLON { ASTTree *asttree = new ASTTree("Stmt", 3, $1,$2,$3);$$ = asttree; }
      ;

/*表达式*/ 
/*注：SysY 表达式是 int 型表达式*/
Exp: AddExp { ASTTree *asttree = new ASTTree("Exp", 1, $1);$$ = asttree; }
     ; 

/*条件表达式*/ 
Cond: LOrExp { ASTTree *asttree = new ASTTree("Cond", 1, $1);$$ = asttree; }
     ;
/*左值表达式*/ 
LVal: IDENTIFIER ArrayExps { ASTTree *asttree = new ASTTree("LVal", 2, $1,$2);$$ = asttree; }
      ;
/*基本表达式*/ 
PrimaryExp: OPLEFTPRNT Exp OPRIGHTPRNT { ASTTree *asttree = new ASTTree("PrimaryExp", 3, $1,$2,$3);$$ = asttree; }
          | LVal { ASTTree *asttree = new ASTTree("PrimaryExp", 1, $1);$$ = asttree; }
          | Number{ ASTTree *asttree = new ASTTree("PrimaryExp", 1, $1);$$ = asttree; }
          ;
/*数值*/ 
Number: IntConst{ ASTTree *asttree = new ASTTree("Number", 1, $1);$$ = asttree; }
      ;
/*还有完善！！！！！！！！！！！！！！！*/
IntConst: CONSTANTOCT { ASTTree *asttree = new ASTTree("IntConst", 1, $1);$$ = asttree; }
          |CONSTANTINTD  { ASTTree *asttree = new ASTTree("IntConst", 1, $1);$$ = asttree; } 
          |CONSTANTINTH { ASTTree *asttree = new ASTTree("IntConst", 1, $1);$$ = asttree; }
          ; 
/*一元表达式*/ 
UnaryExp: PrimaryExp { ASTTree *asttree = new ASTTree("UnaryExp", 1, $1);$$ = asttree; }
         | IDENTIFIER OPLEFTPRNT OPRIGHTPRNT { ASTTree *asttree = new ASTTree("UnaryExp", 3, $1,$2,$3);$$ = asttree; }
         | IDENTIFIER OPLEFTPRNT FuncRParams OPRIGHTPRNT { ASTTree *asttree = new ASTTree("UnaryExp", 4, $1,$2,$3,$4);$$ = asttree; }
         | UnaryOp UnaryExp { ASTTree *asttree = new ASTTree("UnaryExp", 2, $1,$2);$$ = asttree; }
         ;
/*单目运算符*/
/*注：'!'仅出现在条件表达式中*/ 
UnaryOp: OPPLUS { ASTTree *asttree = new ASTTree("UnaryOp", 1, $1);$$ = asttree; }
        | OPMINUS { ASTTree *asttree = new ASTTree("UnaryOp", 1, $1);$$ = asttree; }
        | OPNOT { ASTTree *asttree = new ASTTree("UnaryOp", 1, $1);$$ = asttree; }
        ; 
/*函数实参表*/ 
FuncRParams: Exp Exps{ ASTTree *asttree = new ASTTree("FuncRParams", 1, $1);$$ = asttree; }
            ;
/*表达式表*/
Exps:{ ASTTree *asttree = new ASTTree("Exps", 0, -1);$$ = asttree; }
     |Exps SPCOMMA Exp{ ASTTree *asttree = new ASTTree("Exps", 3, $1,$2,$3);$$ = asttree; }
     ;
/*乘除模表达式*/ 
MulExp: UnaryExp { ASTTree *asttree = new ASTTree("MulExp", 1, $1);$$ = asttree; }
       | MulExp OPMULTIPLY UnaryExp { ASTTree *asttree = new ASTTree("MulExp", 3, $1,$2,$3);$$ = asttree; }
       | MulExp OPDIVIDE UnaryExp { ASTTree *asttree = new ASTTree("MulExp", 3, $1,$2,$3);$$ = asttree; }
       | MulExp OPMOD UnaryExp { ASTTree *asttree = new ASTTree("MulExp", 3, $1,$2,$3);$$ = asttree; }
       ;
/*加减表达式*/ 
AddExp: MulExp { ASTTree *asttree = new ASTTree("AddExp", 1, $1);$$ = asttree; }
       | AddExp OPPLUS MulExp { ASTTree *asttree = new ASTTree("AddExp", 3, $1,$2,$3);$$ = asttree; }
       | AddExp OPMINUS MulExp { ASTTree *asttree = new ASTTree("AddExp", 3, $1,$2,$3);$$ = asttree; }
       ;
/*关系表达式*/ 
RelExp: AddExp { ASTTree *asttree = new ASTTree("RelExp", 1, $1);$$ = asttree; }
       | RelExp OPLIGHT AddExp { ASTTree *asttree = new ASTTree("RelExp", 3, $1,$2,$3);$$ = asttree; }
       | RelExp OPGREAT AddExp { ASTTree *asttree = new ASTTree("RelExp", 3, $1,$2,$3);$$ = asttree; }
       | RelExp OPGREATEQ AddExp { ASTTree *asttree = new ASTTree("RelExp", 3, $1,$2,$3);$$ = asttree; }
       | RelExp OPLIGHTEQ AddExp { ASTTree *asttree = new ASTTree("RelExp", 3, $1,$2,$3);$$ = asttree; }
       ;
/*相等性表达式*/ 
EqExp: RelExp { ASTTree *asttree = new ASTTree("EqExp", 1, $1);$$ = asttree; }
      | EqExp OPEQUAL RelExp { ASTTree *asttree = new ASTTree("EqExp", 3, $1,$2,$3);$$ = asttree; }
      | EqExp OPNOTEQUAL RelExp { ASTTree *asttree = new ASTTree("EqExp", 3, $1,$2,$3);$$ = asttree; }
      ;
/*逻辑与表达式*/ 
LAndExp: EqExp { ASTTree *asttree = new ASTTree("LAndExp", 1, $1);$$ = asttree; }
        | LAndExp OPAND EqExp { ASTTree *asttree = new ASTTree("LAndExp", 3, $1,$2,$3);$$ = asttree; }
        ;
/*逻辑或表达式*/ 
LOrExp: LAndExp { ASTTree *asttree = new ASTTree("LOrExp", 1, $1);$$ = asttree; }
        | LOrExp OPOR LAndExp{ ASTTree *asttree = new ASTTree("LOrExp", 3, $1,$2,$3);$$ = asttree; }
        ;
/*常量表达式*/ 
ConstExp: AddExp { ASTTree *asttree = new ASTTree("ConstExp", 1, $1);$$ = asttree; }
         ;

%%

#include<stdarg.h>


int main(int argc, char *argv[]){
        //extern int yyparse(void);
        //extern int yylex(void);
	yyin=fopen(argv[1],"r");
	if (!yyin) return -1;
	yylineno=1;
	yyparse();
	return 0;
}
void yyerror(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "Error type B at Line %d Column %d: ", yylineno, yylloc.first_column);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, ".\n");
}
