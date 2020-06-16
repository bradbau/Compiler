
%error-verbose
%locations

%{

    #include <iostream>
    #include "AST.h"
    using namespace std;

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



%type <ast_Tree> Compiler CompUnits CompUnit Decl ConstDef ConstDefs   
%type <ast_Tree> VarDef VarDefs InitVal InitValList FuncFParams FuncFParam ArrayExps 
%type <ast_Tree> Block BlockItems BlockItem Stmt Exp Exps Cond LVal Number  
%type <ast_Tree> FuncRParams RelExp EqExp VarDec

%token SPSEMICOLON SPCOMMA SPDOT SPLEFTBRACE SPRIGHTBRACE
%token OPLEFTPRNT OPRIGHTPRNT OPLEFTBRACKET OPRIGHTBRACKET
%token OPPLUS OPMINUS OPMULTIPLY OPDIVIDE OPMOD OPASSIGN
%token OPAND OPOR OPNOT
%token OPEQUAL OPNOTEQUAL OPGREAT OPLIGHT OPGREATEQ OPLIGHTEQ
%token TYPEVOID TYPEINTEGER KEYCONST
%token KEYIF KEYELSE KEYWHILE KEYBREAK KEYCONTINUE
%token KEYRETURN KEYGETINT KEYGETCHAR KEYGETARRAY KEYPUTINT KEYPUTCHAR KEYPUTARRAY KEYPUTF
%token KEYSTOPTIME KEYSTARTTIME
%token <ast_Tree> CONSTANTINTD CONSTANTINTH CONSTANTOCT STRING
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
Compiler: CompUnits {  ASTTree *asttree = new ASTTree("Compiler", 1, yylineno, $1);$$ = asttree;$$->TraverseGrammerTree(0);}
        ;
CompUnits:{ $$ = NULL;}
         | CompUnit CompUnits{ ASTTree *asttree = new ASTTree("CompUnits", 2, yylineno, $1,$2);$$ = asttree; }
         ;
/*组成，常量、变量声明或函数定义*/
CompUnit: Decl {$$=$1;} 
         | TYPEVOID IDENTIFIER OPLEFTPRNT FuncFParams OPRIGHTPRNT Block{ printf("funcdef1\n");ASTTree *asttree = new ASTTree("FuncDef", 2, yylineno, $4,$6);$$ = asttree; $$->SetFuncType("void");$$->SetID($2->GetID());}
         | TYPEINTEGER IDENTIFIER OPLEFTPRNT FuncFParams OPRIGHTPRNT Block{printf("funcdef2\n"); ASTTree *asttree = new ASTTree("FuncDef", 2, yylineno,$4, $6);$$ = asttree; $$->SetFuncType("int");$$->SetID($2->GetID()); }
         ;
/*声明*/
Decl: KEYCONST TYPEINTEGER ConstDef ConstDefs SPSEMICOLON{ ASTTree *asttree = new ASTTree("ConstDecl", 2, yylineno, $3,$4);$$ = asttree; }
     | TYPEINTEGER VarDef VarDefs SPSEMICOLON{ ASTTree *asttree = new ASTTree("VarDecl", 2, yylineno, $2,$3);$$ = asttree; }
     ;
/*常量列表，自行添加的*/
ConstDefs: { $$ = NULL;}
          |  SPCOMMA ConstDef ConstDefs { ASTTree *asttree = new ASTTree("ConstDefs", 2, yylineno, $2, $3);$$ = asttree; }
          ;

/*常数定义*/ 
ConstDef: VarDec OPASSIGN InitVal{ ASTTree *asttree = new ASTTree("ConstOpassign", 2, yylineno, $1, $3);$$ = asttree; }
         ;
/*常量/变量名称，由一个ID组成,包括数组*/
VarDec:   IDENTIFIER          {$$ = $1;}   //ID结点，标识符符号串存放结点的type_id
         | VarDec OPLEFTBRACKET Exp OPRIGHTBRACKET {ASTTree *asttree = new ASTTree("ArrayDec", 1, yylineno, $1);$$ = asttree;$$->SetIntValue($3->GetIntValue());}     //数组,数组名存放在$$->type_id
         ;

/*常量/变量初值*/ 
InitVal: Exp { ASTTree *asttree = new ASTTree("ConstInitVal", 1, yylineno, $1);$$ = asttree; }
             | SPLEFTBRACE SPRIGHTBRACE{ ASTTree *asttree = new ASTTree("ConstInitVal", 0, yylineno);$$ = asttree; }
             | SPLEFTBRACE InitVal InitValList SPRIGHTBRACE{ ASTTree *asttree = new ASTTree("ConstInitVal", 2, yylineno,  $2,$3);$$ = asttree; }
             ;
/*常量初值列表中间用量，自己添加的*/
InitValList:{ $$ = NULL;}
           |SPCOMMA InitVal InitValList { ASTTree *asttree = new ASTTree("ConstInitValList", 2, yylineno, $2,$3);$$ = asttree; }
           ;

/*变量定义*/
VarDef: VarDec{$$ = $1;}  
       | VarDec OPASSIGN InitVal{ ASTTree *asttree = new ASTTree("VarOPassign", 2, yylineno, $1,$3);$$ = asttree; }
       ;
/*变量声明列表，自行添加*/
VarDefs:{ $$ = NULL;}
        | SPCOMMA VarDef  VarDefs{ printf("VarDefs\n");ASTTree *asttree = new ASTTree("VarDefs", 2, yylineno, $2,$3);$$ = asttree; }
       ;

/*函数形参*/ 
FuncFParam: TYPEINTEGER IDENTIFIER{ ASTTree *asttree = new ASTTree("FuncFParam", 0, yylineno);$$ = asttree;$$->SetFuncPType("int");$$->SetID($2->GetID()); }
          | TYPEINTEGER IDENTIFIER OPLEFTBRACKET OPRIGHTBRACKET ArrayExps{ ASTTree *asttree = new ASTTree("FuncFParam", 1, yylineno, $5);$$ = asttree;$$->SetFuncPType("array");$$->SetID($2->GetID()); }
          ;
/*函数形参表*/ 
FuncFParams:{ printf("kong\n");ASTTree *asttree = new ASTTree("FuncFParams", 0, yylineno);$$ = asttree;}
            | FuncFParam { $$ = $1; }
            | FuncFParam SPCOMMA FuncFParams{ ASTTree *asttree = new ASTTree("FuncFParams", 2, yylineno, $1,$3);$$ = asttree; }
            ;
/*数组维度*/
ArrayExps:{ $$ = NULL;}
         | OPLEFTBRACKET Exp OPRIGHTBRACKET ArrayExps{ ASTTree *asttree = new ASTTree("ArrayExps", 2, yylineno, $2,$4);$$ = asttree; }
         ;
/*语句块*/ 
Block:SPLEFTBRACE BlockItems SPRIGHTBRACE{ ASTTree *asttree = new ASTTree("Block", 1, yylineno, $2);$$ = asttree; }
      ;
/*语句块列表*/
BlockItems:{ $$ = NULL;}
           | BlockItem BlockItems  { ASTTree *asttree = new ASTTree("BlockItems", 2, yylineno, $1,$2);$$ = asttree; }
           ;
/*语句块项*/ 
BlockItem:Decl { $$ = $1; }
         | Stmt { $$ = $1; }
         ;

/*左值表达式*/ 
LVal: IDENTIFIER ArrayExps { printf("Lval\n");ASTTree *asttree = new ASTTree("LVal", 2, yylineno, $1,$2);$$ = asttree; }
      ;
/*语句*/ 
Stmt: LVal OPASSIGN Exp SPSEMICOLON { printf("stmt1\n");ASTTree *asttree = new ASTTree("Lval_Opassign_Stmt",2, yylineno, $1,$3);$$ = asttree; }
      | SPSEMICOLON { ASTTree *asttree = new ASTTree("Empty_Stmt",0, yylineno);$$ = asttree; }
      | Exp SPSEMICOLON {ASTTree *asttree = new ASTTree("Exp_Stmt", 1, yylineno, $1);$$ = asttree;  }
      | Block { ASTTree *asttree = new ASTTree("Block_Stmt", 1, yylineno, $1);$$ = asttree; }
      | KEYIF OPLEFTPRNT Cond OPRIGHTPRNT Stmt { ASTTree *asttree = new ASTTree("IF_Stmt", 2, yylineno, $3,$5);$$ = asttree; }
      | KEYIF OPLEFTPRNT Cond OPRIGHTPRNT Stmt KEYELSE Stmt { ASTTree *asttree = new ASTTree("IF_ELSE_Stmt", 3, yylineno,$3,$5,$7);$$ = asttree; }
      | KEYWHILE OPLEFTPRNT Cond OPRIGHTPRNT Stmt { ASTTree *asttree = new ASTTree("While_Stmt", 2, yylineno, $3,$5);$$ = asttree; }
      | KEYBREAK SPSEMICOLON { ASTTree *asttree = new ASTTree("Break_Stmt", 0,yylineno);$$ = asttree; }
      | KEYCONTINUE SPSEMICOLON { ASTTree *asttree = new ASTTree("Continue_Stmt", 0,yylineno);$$ = asttree; }
      | KEYRETURN  SPSEMICOLON { ASTTree *asttree = new ASTTree("Return_Stmt", 0,yylineno);$$ = asttree; }
      | KEYRETURN  Exp SPSEMICOLON { ASTTree *asttree = new ASTTree("Return_Stmt", 1, yylineno, $2);$$ = asttree; }
      ;

/*条件表达式*/ 
Cond: EqExp { ASTTree *asttree = new ASTTree("Cond", 1, yylineno, $1);$$ = asttree; }
    | Cond OPAND Cond { ASTTree *asttree = new ASTTree("Cond_And", 2, yylineno, $1,$3);$$ = asttree; }
    | Cond OPOR Cond{ ASTTree *asttree = new ASTTree("Cond_Or", 2, yylineno, $1,$3);$$ = asttree; }
    ;

/*关系表达式*/ 
RelExp: Exp { $$=$1; }
       | RelExp OPLIGHT Exp { ASTTree *asttree = new ASTTree("OPLIGHT", 2, yylineno, $1,$3);$$ = asttree; }
       | RelExp OPGREAT Exp { ASTTree *asttree = new ASTTree("OPGREAT", 2, yylineno, $1,$3);$$ = asttree; }
       | RelExp OPGREATEQ Exp { ASTTree *asttree = new ASTTree("OPGREATEQ", 2, yylineno, $1,$3);$$ = asttree; }
       | RelExp OPLIGHTEQ Exp { ASTTree *asttree = new ASTTree("OPLIGHTEQ", 2, yylineno, $1,$3);$$ = asttree; }
       ;
/*相等性表达式*/ 
EqExp: RelExp { $$=$1; }
      | EqExp OPEQUAL RelExp { ASTTree *asttree = new ASTTree("OPEQUAL", 2, yylineno, $1,$3);$$ = asttree; }
      | EqExp OPNOTEQUAL RelExp { ASTTree *asttree = new ASTTree("OPNOTEQUAL", 2, yylineno, $1,$3);$$ = asttree; }
      ;

/*数值*/ 
Number:   CONSTANTOCT { ASTTree *asttree = new ASTTree("IntConst", 1, yylineno, $1);$$ = asttree; $$->SetIntValue($1->GetIntValue());printf("IntConst:%d\n",$$->GetIntValue());}
        | CONSTANTINTD  { ASTTree *asttree = new ASTTree("IntConst", 1, yylineno, $1);$$ = asttree;$$->SetIntValue($1->GetIntValue()); printf("IntConst:%d\n",$$->GetIntValue());} 
        | CONSTANTINTH { ASTTree *asttree = new ASTTree("IntConst", 1, yylineno, $1);$$ = asttree;$$->SetIntValue($1->GetIntValue());printf("IntConst:%d\n",$$->GetIntValue()); }
        ; 
/*函数实参表*/ 
FuncRParams: Exp Exps{ ASTTree *asttree = new ASTTree("FuncRParams", 2, yylineno, $1,$2);$$ = asttree; }
           ;
/*表达式*/ 
/*注：SysY 表达式是 int 型表达式*/
Exp: OPLEFTPRNT Exp OPRIGHTPRNT { ASTTree *asttree = new ASTTree("(Exp)", 1, yylineno,$2);$$ = asttree;$$->SetIntValue($2->GetIntValue()); }
   | LVal { ASTTree *asttree = new ASTTree("LVal_EXP", 1, yylineno, $1);$$ = asttree; }
   | STRING {$$=$1;printf("ExpString:%s\n",$$->GetString());}
   | Number{ $$ = $1;printf("ExpNumber:%d\n",$$->GetIntValue()); }
   | IDENTIFIER OPLEFTPRNT OPRIGHTPRNT { ASTTree *asttree = new ASTTree("funcall", 1, yylineno, $1);$$ = asttree; }
   | IDENTIFIER OPLEFTPRNT FuncRParams OPRIGHTPRNT { ASTTree *asttree = new ASTTree("funcall", 2, yylineno, $1,$3);$$ = asttree; }
   | OPPLUS Exp { ASTTree *asttree = new ASTTree("OPPLUS_Exp", 1, yylineno, $2);$$ = asttree; }
   | OPMINUS Exp { ASTTree *asttree = new ASTTree("OPMINUS_Exp", 1, yylineno, $2);$$ = asttree; }
   | OPNOT Exp { ASTTree *asttree = new ASTTree("OPNOT_Exp", 1, yylineno, $2);$$ = asttree; }
   | Exp OPMULTIPLY Exp { ASTTree *asttree = new ASTTree("MulExp", 2, yylineno, $1,$3);$$ = asttree; }
   | Exp OPDIVIDE Exp { ASTTree *asttree = new ASTTree("DIVIDEExp", 2, yylineno, $1,$3);$$ = asttree; }
   | Exp OPMOD Exp { ASTTree *asttree = new ASTTree("MODExp", 2, yylineno, $1,$3);$$ = asttree; }
   | Exp OPPLUS Exp { ASTTree *asttree = new ASTTree("PLUSExp", 2, yylineno, $1,$3);$$ = asttree; }
   | Exp OPMINUS Exp { ASTTree *asttree = new ASTTree("MINUSExp", 2, yylineno, $1,$3);$$ = asttree; }
   ;

/*表达式表*/
Exps:{ $$ = NULL;}
     |SPCOMMA Exp Exps{ ASTTree *asttree = new ASTTree("Exps", 2, yylineno, $2,$3);$$ = asttree; }
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
