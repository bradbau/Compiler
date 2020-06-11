/* utf-8 */
%error-verbose
%locations

%{
    //#include<stdio.h>
    //#include<unistd.h>
    #include <iostream>
    //#include"lex.yy.cc"
    //#include "grammartree.cpp"
    #include "AST.h"
    #include "SymbolTable.h"
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
Compiler: CompUnits {  ASTTree *asttree = new ASTTree("Compiler", 1, yylineno, $1);$$ = asttree;
                $1->TraverseGrammerTree(0);}
        ;
CompUnits:{ $$ = NULL;}
         | CompUnit CompUnits{ ASTTree *asttree = new ASTTree("CompUnits", 2, yylineno, $1,$2);
                        $$ = asttree; 
                        $$->si = mergeScope($1->si, $2->si);
                        }
         ;
CompUnit: Decl{ $$ = $1;
                //Decl的孙子节点VarDec将所有变量均定义成Local了，此处要手动将其改为Glocal
                ScopeItem *temp = $$->si;
                while(temp){
                        temp->stype = Global;
                        temp = temp->next;
                }
                }
        |TYPEVOID IDENTIFIER OPLEFTPRNT FuncFParams OPRIGHTPRNT Block{ ASTTree *asttree = new ASTTree("FuncDef", 2, yylineno, $4, $6);
                $$ = asttree; 
                $$->SetFuncType("void");
                $$->SetID($2->GetID());
                $4->si->depictor = $6->si;
                $$->si = addIntoScope(Global, $$->si, $2->GetID(), Function, "void", $4->si);
                }
        |TYPEINTEGER IDENTIFIER OPLEFTPRNT FuncFParams OPRIGHTPRNT Block{ ASTTree *asttree = new ASTTree("FuncDef", 2, yylineno, $4,$6);
                $$ = asttree; 
                $$->SetFuncType("int");
                $$->SetID($2->GetID());
                $4->si->depictor = $6->si;
                $$->si = addIntoScope(Global, $$->si, $2->GetID(), Function, "int", $4->si);
                }
        // |TYPEVOID IDENTIFIER OPLEFTPRNT OPRIGHTPRNT Block{ ASTTree *asttree = new ASTTree("FuncDef", 1, yylineno, $5);
        //         $$ = asttree; 
        //         $$->SetFuncType("void");
        //         $$->SetID($2->GetID());
        //         //由于没有形参节点，所以自己手动创建一个，名字为NULL意味着该函数实际上没有形参
        //         //这种方式创建的形参节点是不在符号表里面的，不过本身也没有引入新的符号，暂时不确定之后会不会有问题
        //         ASTTree *funcfparam = new ASTTree(NULL, 0, yylineno);
        //         funcfparam->si->depictor = $5->si;
        //         $$->si = addIntoScope(Global, $$->si, $2->GetID(), Function, "void", funcfparam->si);
        //         }
        // |TYPEINTEGER IDENTIFIER OPLEFTPRNT OPRIGHTPRNT Block{ ASTTree *asttree = new ASTTree("FuncDef", 1, yylineno, $5);
        //         $$ = asttree; 
        //         $$->SetFuncType("int");
        //         $$->SetID($2->GetID());
        //         ASTTree *funcfparam = new ASTTree(NULL, 0, yylineno);
        //         funcfparam->si->depictor = $5->si;
        //         $$->si = addIntoScope(Global, $$->si, $2->GetID(), Function, "int", funcfparam->si);
        //         }
         ;

/* 注意：涉及到数组的暂时先不管 */
/*函数形参*/ 
FuncFParam: TYPEINTEGER IDENTIFIER{ ASTTree *asttree = new ASTTree("FuncFParam", 0, yylineno);
                $$ = asttree; 
                $$->SetID($2->GetID());
                $$->SetFuncPType("int");
                $$->si = addIntoScope(Formal, $$->si, $2->GetID(), Variable, "int", NULL);
                }
          | TYPEINTEGER IDENTIFIER OPLEFTBRACKET OPRIGHTBRACKET ArrayExps{ 
                ASTTree *asttree = new ASTTree("FuncFParam", 1, yylineno, $5);
                $$ = asttree;
                $$->SetFuncPType("array");
                $$->SetID($2->GetID()); 
                }
          
          ;
/*函数形参表*/ 
FuncFParams: FuncFParam { $$ = $1;}
            | FuncFParam SPCOMMA FuncFParams{ ASTTree *asttree = new ASTTree("FuncFParams", 2, yylineno, $1, $3);
                        $$ = asttree; 
                        $$->si = mergeScope($1->si, $3->si);
                        }
            | {ASTTree *asttree = new ASTTree("FuncFParam", 0, yylineno);
                $$ = asttree;
                $$->SetID(NULL);
                $$->si = addIntoScope(Formal, NULL, NULL, Variable, NULL, NULL);
                }
            ;
            
/*声明*/
Decl:  KEYCONST TYPEINTEGER ConstDef ConstDefs SPSEMICOLON{ ASTTree *asttree = new ASTTree("ConstDecl", 2, yylineno, $3, $4);
                $$ = asttree; 
                $$->si = mergeScope($3->si, $4->si);
                }
      | TYPEINTEGER VarDef VarDefs SPSEMICOLON{ ASTTree *asttree = new ASTTree("VarDecl", 2, yylineno, $2,$3);
                $$ = asttree; 
                $$->si = mergeScope($2->si, $3->si);
                }
      ;

/*常量列表，自行添加的*/
ConstDefs: { $$ = NULL;}
          | SPCOMMA ConstDef ConstDefs{ ASTTree *asttree = new ASTTree("ConstDefs", 2, yylineno, $2,$3);
                $$ = asttree; 
                $$->si = mergeScope($2->si, $3->si);
                }
          ;

/*常数定义*/ 
ConstDef: VarDec OPASSIGN InitVal{ ASTTree *asttree = new ASTTree("ConstOpassign", 2, yylineno, $1, $3);
                $$ = asttree;
                $$->si = $1->si;
                }
         ;

//VarDec节点是Decl节点的孙子节点，而Decl极可能出现在CompUnit中也可能出现在Block中，所以定义的变量极有可能是Local也有可能是Global。但是我们在VarDec处不好进行区分。我们可以先统一定义成Local，最后再CompUnit处将其再改为Global
VarDec:   IDENTIFIER {$$ = $1;
                $$->si = addIntoScope(Local, $$->si, $1->GetID(), Variable, "TYPEINTEGER", NULL);
                }   //ID结点，标识符符号串存放结点的type_id
         | VarDec OPLEFTBRACKET Exp OPRIGHTBRACKET {ASTTree *asttree = new ASTTree("ArrayDec", 1, yylineno, $1);
                $$ = asttree;
                $$->SetIntValue($3->GetIntValue());
                $$->si = addIntoScope(Local, $$->si, $1->GetID(), Array, "TYPEINTEGER", NULL);
                }     //数组,数组名存放在$$->type_id
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
// VarDef:  IDENTIFIER ArrayDef{ ASTTree *asttree = new ASTTree("VarDef", 2, $1,$2);
//                 $$ = asttree; 
//                 $$->si = addIntoScope(Local, $$->si, $1->id, Variable, "TYPEINTEGER", NULL);
//                 }
//         | IDENTIFIER ArrayDef OPASSIGN InitVal{ ASTTree *asttree = new ASTTree("VarDef", 4, $1,$2,$3,$4);
//                 $$ = asttree; 
//                 $$->si = addIntoScope(Local, $$->si, $1->id, Variable, "TYPEINTEGER", NULL);
//                 }

/*变量定义*/
VarDef: VarDec{$$ = $1;}  
       | VarDec OPASSIGN InitVal{ ASTTree *asttree = new ASTTree("VarOPassign", 2, yylineno, $1,$3);
                $$ = asttree; 
                $$->si = $1->si;               
                }
       ;

/*变量声明列表，自行添加*/
VarDefs:{ $$ = NULL;}
       | SPCOMMA VarDef VarDefs{ ASTTree *asttree = new ASTTree("VarDefs", 2,yylineno,$2,$3);
                $$ = asttree; 
                $$->si = mergeScope($2->si, $3->si);
                }
       ;

/*数组维度*/
ArrayExps:{ $$ = NULL;}
         | OPLEFTBRACKET Exp OPRIGHTBRACKET ArrayExps{ ASTTree *asttree = new ASTTree("ArrayExps", 2, yylineno, $2,$4);$$ = asttree; }
         ;

/*语句块*/ 
Block:SPLEFTBRACE BlockItems SPRIGHTBRACE{ ASTTree *asttree = new ASTTree("Block", 1,yylineno, $2);
                $$ = asttree; 
                $$->si = $2->si;
                }
      ;
/*语句块列表*/
BlockItems:{ $$ = NULL} 
           | BlockItem BlockItems  { ASTTree *asttree = new ASTTree("BlockItems", 2, yylineno, $1,$2);
                $$ = asttree; 
                $$->si = mergeScope($1->si, $2->si);
                }
           ;
/*语句块项*/ 
BlockItem:Decl {$$ = $1;}
         | Stmt {$$ = $1; }
         ;
/*左值表达式*/ 
LVal: IDENTIFIER ArrayExps { printf("Lval\n");ASTTree *asttree = new ASTTree("LVal", 2, yylineno, $1,$2);$$ = asttree; }
      ;
/*语句*/ 
Stmt: LVal OPASSIGN Exp SPSEMICOLON { printf("stmt1\n");ASTTree *asttree = new ASTTree("Lval_Opassign_Stmt",2, yylineno, $1,$3);$$ = asttree; }
      | SPSEMICOLON { ASTTree *asttree = new ASTTree("Empty_Stmt",0, yylineno);$$ = asttree; }
      | Exp SPSEMICOLON {ASTTree *asttree = new ASTTree("Exp_Stmt", 1, yylineno, $1);$$ = asttree;  }
      | Block { ASTTree *asttree = new ASTTree("Block_Stmt", 1, yylineno, $1);
                $$ = asttree; 
                //内嵌域符号表
                $$->si = addIntoScope(Local, $$->si, NULL, Block, NULL, $1->si);
                }
      | KEYIF OPLEFTPRNT Cond OPRIGHTPRNT Stmt { ASTTree *asttree = new ASTTree("IF_Stmt", 2, yylineno, $3,$5);$$ = asttree; $$->si = $5->si;}
      | KEYIF OPLEFTPRNT Cond OPRIGHTPRNT Stmt KEYELSE Stmt { ASTTree *asttree = new ASTTree("IF_ELSE_Stmt", 3, yylineno,$3,$5,$7);$$ = asttree; $$->si = mergeScope($5->si, $7->si);}
      | KEYWHILE OPLEFTPRNT Cond OPRIGHTPRNT Stmt { ASTTree *asttree = new ASTTree("While_Stmt", 2, yylineno, $3,$5);$$ = asttree; $$->si = $5->si;}
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
Number:   CONSTANTOCT { ASTTree *asttree = new ASTTree("IntConst", 1, yylineno, $1);$$ = asttree; }
        | CONSTANTINTD  { ASTTree *asttree = new ASTTree("IntConst", 1, yylineno, $1);$$ = asttree; } 
        | CONSTANTINTH { ASTTree *asttree = new ASTTree("IntConst", 1, yylineno, $1);$$ = asttree; }
        ; 
/*函数实参表*/ 
FuncRParams: Exp Exps{ ASTTree *asttree = new ASTTree("FuncRParams", 2, yylineno, $1,$2);$$ = asttree; }
           ;
/*表达式*/ 
/*注：SysY 表达式是 int 型表达式*/
Exp: OPLEFTPRNT Exp OPRIGHTPRNT { ASTTree *asttree = new ASTTree("(Exp)", 1, yylineno,$2);$$ = asttree; }
   | LVal { ASTTree *asttree = new ASTTree("LVal_EXP", 1, yylineno, $1);$$ = asttree; }
   | Number{ $$ = $1; }
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
     |Exps SPCOMMA Exp{ ASTTree *asttree = new ASTTree("Exps", 2, yylineno, $1,$3);$$ = asttree; }
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
