#include "..\TAC.h"
#include "..\SymbolTable.h"
#include "..\stack.h"
#include "..\AST.h"
#include "DAG.h"
#include <vector>

void DAG(basic_block* head, Node* nodehead) {
	TACCode* traverse = NULL;
	nodehead = (Node*)malloc(sizeof(Node));
	for (traverse = head->begin; traverse != head->end; traverse = traverse->next) {
		if (traverse->code.optype == ASSIGN) {
			traverse->code.dest
		}
	}
}


Node* SearchDAG(Node* nodehead, ScopeItem dest) {
	int len = nodehead->id.size();
	int k = 0;
	for (k = 0; k < len; k++) {
		if (SearchDAG(nodehead->id[k], dest) != NULL) {
			return SearchDAG(nodehead->id[k], dest);
		}
	}
	if(nodehead->SaveType== VARIABLE)
}