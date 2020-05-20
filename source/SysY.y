%{
    #include<stdio.h>
    #include<unistd.h>
    #include"lex.yy.c"
    void yyerror(const char* fmt, ...);
%}

%error-verbose
%locations

%union {
    GrammarTree grammar_tree;
}

%token <grammar_tree> SPSEMICOLON SPCOMMA SPDOT SPLEFTBRACE SPRIGHTBRACE
%token <grammar_tree> OPLEFTPRNT OPRIGHTPRNT OPLEFTBRACKET OPRIGHTBRACKET
%token <grammar_tree> OPPLUS OPMINUS OPMULTIPLY OPDIVIDE OPMOD OPASSIGN
%token <grammar_tree> OPAND OPOR OPNOT
%token <grammar_tree> OPEQUAL OPNOTEQUAL OPGREAT OPLIGHT OPGREATEQ OPLIGHTEQ
%token <grammar_tree> TYPEVOID TYPEINTEGER KEYCONST
%token <grammar_tree> KEYIF KEYELSE KEYFOR KEYWHILE KEYBREAK KEYCONTINUE
%token <grammar_tree> KEYRETURN 
%token <grammar_tree> CONSTANTNULL CONSTANTINTD CONSTANTINTH CONSTANTOCT
%token <grammar_tree> IDENTIFIER

%type <grammar_tree> CompUnit Decl ConstDecl VarDecl BType ConstDef ConstDefs ArrayDef ConstInitVal ConstInitVals ConstInitValList
%type <grammar_tree> VarDef VarDefs InitVal InitVals InitValList FuncDef FuncDef FuncType FuncFParams ArrayExps 
%type <grammar_tree> Block BlockItems BlockItem Stmt Exp Exps Cond LVal PrimaryExp Number IntConst UnaryExp UnaryOp 
%type <grammar_tree> FuncRParams MulExp AddExp RelExp EqExp LAndExp LOrExp ConstExp

%right OPASSIGN
%left OPOR
%left OPAND
%left OPLIGHT OPLIGHTEQ OPGREAT OPGREATEQ OPEQUAL OPNOTEQUAL
%left OPPLUS OPMINUS
%left OPMULTIPLY OPDIVIDE OPMOD
%right OPNOT
%left SPDOT
%left OPRIGHTBRACKET
%right OPLEFTBRACKET
%left OPRIGHTPRNT
%right OPLEFTPRNT

%nonassoc LOWER_THAN_ELSE
%nonassoc KEYELSE 

%%
CompUnit： CompUnit  Decl 
          | CompUnit FuncDef 
          | Decl
          | FuncDef
          ;
/*声明*/
Decl:  ConstDecl 
      | VarDecl
      ;

/*常量声明*/ 
ConstDecl: KEYCONST BType ConstDef ConstDefs SPSEMICOLON
          ;
/*常量列表，自行添加的*/
ConstDefs: 
          | ConstDefs SPCOMMA ConstDef
          ;

/*基本类型*/ 
BType:TYPEINTEGER
      ;

/*常数定义*/ 
ConstDef: IDENTIFIER ArrayDef OPASSIGN ConstInitVal
         ;
ArrayDef:
        | ArrayDef OPLEFTBRACKET ConstExp OPRIGHTBRACKET
        ;
/*常量初值*/ 
ConstInitVal:ConstExp 
             | SPLEFTBRACE ConstInitVals SPRIGHTBRACE
             ;
/*常量初值列表，自己添加的*/
ConstInitVals: 
              | ConstInitVal ConstInitValList
              ;
/*常量初值列表中间用量，自己添加的*/
ConstInitValList:
                |ConstInitValList SPCOMMA ConstInitVal
                ;

/*变量声明*/ 
VarDecl: BType VarDef VarDefs SPSEMICOLON
        ;
/*变量定义*/
VarDef:IDENTIFIER ArrayDef
       | IDENTIFIER ArrayDef OPASSIGN InitVal
/*变量声明列表，自行添加*/
VarDefs:
       | VarDefs SPCOMMA VarDef
       ;
/*变量初值*/ 
InitVal: Exp 
       | SPLEFTBRACE InitVals SPRIGHTBRACE
       ;
/*变量初值列表，自己添加的*/
InitVals: 
        | InitVal InitValList
        ;
/*变量初值列表中间用量，自己添加的*/
InitValList:
            |InitVals SPCOMMA InitVal
            ;

/*函数定义*/ 
FuncDef:FuncType IDENTIFIER OPLEFTPRNT OPRIGHTPRNT Block
        |FuncType IDENTIFIER OPLEFTPRNT FuncFParams OPRIGHTPRNT Block
        ;
/*函数类型*/ 
FuncType: TYPEVOID | TYPEINTEGER;
/*函数形参表*/ 
FuncFParams:FuncFParam 
            | FuncFParams SPCOMMA FuncFParam
            ;
/*函数形参*/ 
FuncFParam: BType IDENTIFIER
          | BType IDENTIFIER OPLEFTBRACKET OPRIGHTBRACKET ArrayExps
          ;
/*数组维度*/
ArrayExps:
         |ArrayExps OPLEFTBRACKET Exp OPRIGHTBRACKET
         ;
/*语句块*/ 
Block:SPLEFTBRACE BlockItems SPRIGHTBRACE;
/*语句块列表*/
BlockItems: 
           |BlockItems BlockItem 
           ;
/*语句块项*/ 
BlockItem:Decl 
         | Stmt
         ;
/*语句*/ 
Stmt: LVal OPASSIGN Exp SPSEMICOLON 
      | SPSEMICOLON 
      | Exp SPSEMICOLON 
      | Block
      | KEYIF OPLEFTPRNT Cond OPRIGHTPRNT Stmt 
      | KEYIF OPLEFTPRNT Cond OPRIGHTPRNT Stmt KEYELSE Stmt 
      | KEYWHILE OPLEFTPRNT Cond OPRIGHTPRNT Stmt
      | KEYBREAK SPSEMICOLON 
      | KEYCONTINUE SPSEMICOLON
      | KEYRETURN  SPSEMICOLON
      | KEYRETURN  Exp SPSEMICOLON
      ;

/*表达式*/ 
/*注：SysY 表达式是 int 型表达式*/
Exp: AddExp; 

/*条件表达式*/ 
Cond: LOrExp;
/*左值表达式*/ 
LVal: IDENTIFIER ArrayExps;
/*基本表达式*/ 
PrimaryExp: OPLEFTPRNT Exp OPRIGHTPRNT 
          | LVal 
          | Number
          ;
/*数值*/ 
Number: IntConst;
/*还有完善！！！！！！！！！！！！！！！*/
IntConst: CONSTANTOCT 
          |CONSTANTINTD   
          |CONSTANTINTH
          ; 
/*一元表达式*/ 
UnaryExp: PrimaryExp 
         | IDENTIFIER OPLEFTPRNT OPRIGHTPRNT 
         | IDENTIFIER OPLEFTPRNT FuncRParams OPRIGHTPRNT 
         | UnaryOp UnaryExp
         ;
/*单目运算符*/
/*注：'!'仅出现在条件表达式中*/ 
UnaryOp: OPPLUS | OPMINUS | OPNOT; 
/*函数实参表*/ 
FuncRParams: Exp Exps;
/*表达式表*/
Exps:
     |Exps SPCOMMA Exp
     ;
/*乘除模表达式*/ 
MulExp: UnaryExp 
       | MulExp OPMULTIPLY UnaryExp
       | MulExp OPDIVIDE UnaryExp
       | MulExp OPMOD UnaryExp
       ;
/*加减表达式*/ 
AddExp: MulExp 
       | AddExp OPPLUS MulExp
       | AddExp OPMINUS MulExp
       ;
/*关系表达式*/ 
RelExp: AddExp 
       | RelExp OPLIGHT AddExp
       | RelExp OPGREAT AddExp
       | RelExp OPGREATEQ AddExp
       | RelExp OPLIGHTEQ AddExp
       ;
/*相等性表达式*/ 
EqExp: RelExp 
      | EqExp OPEQUAL RelExp
      | EqExp OPNOTEQUAL RelExp
      ;
/*逻辑与表达式*/ 
LAndExp: EqExp 
        | LAndExp OPAND EqExp
        ;
/*逻辑或表达式*/ 
LOrExp: LAndExp 
        | LOrExp OPOR LAndExp
        ;
/*常量表达式*/ 
ConstExp: AddExp;

%%

#include<stdarg.h>

void yyerror(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "Error type B at Line %d Column %d: ", yylineno, yylloc.first_column);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, ".\n");
}

