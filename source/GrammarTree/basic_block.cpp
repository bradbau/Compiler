#include "TAC.h"
#include "SymbolTable.h"
#include "stack.h"
#include "AST.h"
#include <vector>

TAC::DivideBlock(TACCode* codelist) {
    TACCode* traverse = NULL;
    basic_block* head = (basic_block*)malloc(sizeof(basic_block));
    head->begin = codelist;
    for (traverse = head; traverse->next != NULL; traverse = traverse->next) {
        traverse->code
    }
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
