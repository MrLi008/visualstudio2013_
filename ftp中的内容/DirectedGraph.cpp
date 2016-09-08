#include "DirectedGraph.h"
#include "funcs.h"


DirectedGraph::DirectedGraph()
{

	root = NULL;
}

DirectedGraph::DirectedGraph(int graph[5][5], int columns, int raws){

	root = new DirectedGraphNode();
	DirectedGraphNode* nextRaw = NULL;
	DirectedGraphNode* tempRaw = root;
	root->setValue(0);

	for (int i = 0; i < raws; i++){
		
		if (nextRaw == NULL){
			nextRaw = root;
			nextRaw->setValue(graph[i][0]);

		}
		else{
			nextRaw = new DirectedGraphNode(graph[i][0]);
		}

		DirectedGraphNode* next = NULL;
		DirectedGraphNode* temp = nextRaw;

		for (int j = 1; j < 5; j++){

			if (graph[i][j] != biggest){
				next = new DirectedGraphNode();
				next->setValue(graph[i][j]);
				temp->setCol(next);
				temp = next;
			}
		}

		tempRaw->setRaw(nextRaw);
		tempRaw = nextRaw;
	}
	print();

}

DirectedGraph::~DirectedGraph()
{
	delete root;
}

void DirectedGraph::print(){
	printNode(root);
}

void DirectedGraph::printNode(DirectedGraphNode* node){

	if (node != NULL){
		node->print();
		cout << " ";
		printNode(node->getCol());
		cout << endl;
		printNode(node->getRaw());
	}
}

