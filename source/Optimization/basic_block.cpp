#include "TAC.h"
#include "SymbolTable.h"
#include "stack.h"
#include "AST.h"
#include <vector>

basic_block* TAC::SearchBlock(basic_block* head, Label label) {     //寻找DF label的基本块
    TAC* tac = new TAC();
    int k = 0;
    if (head->begin->code.optype == LABELDF && head->begin->code.dest.Type == LABEL 
        && head->begin->code.dest.labelvalue == label) {
        return head;
    }
    else {
        for (k = 0; k < head->next.size(); k++) {
            if (tac->SearchBlock(head->next[k]) != NULL) {
                return SearchBlock(head->next[k]);
            }
        }   
    }
    return NULL;
}

basic_block* TAC::DivideBlock(TACCode* entrance) {
    TAC* tac = new TAC();
    TACCode* traverse = NULL;
    basic_block* head = (basic_block*)malloc(sizeof(basic_block));
    basic_block* process = head;
    basic_block* nextone = NULL;
    head->begin = entrance;
    TACCode* begin = entrance;   //基本块开始位置
    TACCode* end = NULL;         //基本块结束位置
    for (traverse = head; traverse != NULL; traverse = traverse->next) {
        if (traverse->code.optype == IFLTGOTO || traverse->code.optype == IFLEGOTO || traverse->code.optype == IFGTGOTO ||
                traverse->code.optype == IFGEGOTO || traverse->code.optype == IFEQGOTO || traverse->code.optype == IFNEQGOTO) {
                process->end = traverse;
                if (traverse->next != NULL) {
                    nextone = (basic_block*)malloc(sizeof(basic_block));
                    nextone->begin = traverse + 1;
                    process->next.push_back(nextone);           //顺序的下一个基本块
                    process = nextone;
                }
                process->next.push_back(tac->SearchBlock(head, traverse->code.dest.labelvalue));                  //跳转的下一个基本块
        }
        else if (traverse->code.optype == GOTO) {
            process->end = traverse;
            if (traverse->next != NULL) {
                nextone = (basic_block*)malloc(sizeof(basic_block));
                nextone->begin = traverse + 1;
                process->next.push_back(tac->SearchBlock(head, traverse->code.dest.labelvalue));                    //跳转的下一个基本块
                process = nextone;
            }
        }
        else if (traverse->code.optype == LABELDF) {
                process->end = traverse->prev;
                if (traverse->next != NULL) {
                    nextone = (basic_block*)malloc(sizeof(basic_block));
                    nextone->begin = traverse;
                    process->next.push_back(nextone);
                    process = nextone;
                }
                else {
                    nextone = (basic_block*)malloc(sizeof(basic_block));
                    nextone->begin = traverse;
                    nextone->end = traverse;
                    process->next.push_back(nextone);
                    //process = nextone;
                }
        }
    }
    return head;
}


int main(int argc, char** argv)
{
    if (argc > 1)
    {
        if (!(yyin = fopen(argv[1], "r"))
        {
            perror(argv[1]);
            return 1;
        }
    }
    yyparse();
    return 0;
}
