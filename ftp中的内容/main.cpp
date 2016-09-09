# include "funcs.h"

using namespace std;

//void printNode(DirectedGraphNode* node){
//	if (node != NULL){
//		node->print();
//		cout << " ";
//		printNode(node->getCol());
//		cout << endl<< "b";
//		printNode(node->getRaw());
//	}
//}

int main(void){


	
	// // Test: ObjectEnablePrint is ok?
	// ObjectEnablePrint* o = new ObjectEnablePrint();
	// o->print();

	//// Test: DirectedGraphNode is Ok?
	//DirectedGraphNode* o = new DirectedGraphNode();
	//o->print();
	//ObjectEnablePrint* oep = o;
	//oep->print();

	//// Test: 根据一个二维数组产生一个加权有向图
	//const int biggest = 100;
	//int a[][5] = {
	//	{ 1,	biggest,	6,			7,			8 },
	//	{ 2,	9,			10,			biggest,	11 },
	//	{ 3,	12,			biggest,	biggest,	biggest },
	//	{ 4,	biggest,	biggest,	biggest,	biggest },
	//	{ 5,	biggest,	biggest,	13,			biggest }
	//};

	//DirectedGraphNode* root = new DirectedGraphNode();
	//DirectedGraphNode* nextRaw = NULL;
	//DirectedGraphNode* tempRaw = root;
	//root->setValue(0);

	//for (int i = 0; i < 5; i++){
	//	// nextRaw = new DirectedGraphNode(a[i][0]);
	//	if (nextRaw == NULL){
	//		nextRaw = root;
	//		nextRaw->setValue(a[i][0]);

	//	}
	//	else{
	//		nextRaw = new DirectedGraphNode(a[i][0]);
	//	}
	//	DirectedGraphNode* next = NULL;
	//	DirectedGraphNode* temp = tempRaw;
	//	for (int j = 1; j < 5; j++){
	//		if (a[i][j] != biggest){
	//			next = new DirectedGraphNode();
	//			next->setValue(a[i][j]);
	//			temp->setCol(next);
	//			temp = next;
	//		}
	//	}
	//	tempRaw->setRaw(nextRaw);
	//	tempRaw = nextRaw;
	//}


	//printNode(root);

	//delete root;

	// Test: DirectedGraph

	const int biggest = 100000;
	int a[5][5] = {
			{ 1,	biggest,	6,			7,			8 },
			{ 2,	9,			10,			biggest,	11 },
			{ 3,	12,			biggest,	biggest,	biggest },
			{ 4,	biggest,	biggest,	biggest,	biggest },
			{ 5,	biggest,	biggest,	13,			biggest }
		};

	DirectedGraph* d = new DirectedGraph(a, 5, 5);
	d->print();

	delete d;



	system("pause");
	return 0;
}