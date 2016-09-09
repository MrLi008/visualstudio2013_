#include "DirectedGraph.h"
#include "funcs.h"

#include <list>


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

		}
		else{
			nextRaw = new DirectedGraphNode();
		}
		nextRaw->setValue( 0 );
		nextRaw->setPointIndex( i );

		DirectedGraphNode* next = NULL;
		DirectedGraphNode* temp = nextRaw;

		for (int j = 0; j < 5; j++){

			if (graph[i][j] != biggest){
				next = new DirectedGraphNode();
				next->setPointIndex( j );
				next->setValue(graph[i][j]);
				temp->setCol(next);
				temp->setRaw( NULL );
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


DirectedGraph* DirectedGraph::getShortestWay( int from, int to ) {
	// ���ڵ��Ƿ���Ч
	if ( from < 0 || to < 0 ) {
		cout << "�ڵ�����Ч";
		return NULL;
	}

	


	DirectedGraphNode* start = root;
	int i = 0;
	for ( i = 0; i < from; i++ ) {
		if ( start == NULL ) {
			break;
		}
		start = start->getRaw( );
	}

	// ��δ�ҵ������ڵ�
	if ( i < from ) {
		cout << "δ�ҵ���ʼ�ڵ�";
		return NULL;
	}

	// ����, ���ҵ���ʼ�ڵ������ȱ������߹�ȱ���Ѱ��Ŀ��ڵ�
	// ���
	list<int>* values = new list<int>();
	int v = getMaxWeightValueByDepthErgodic(start,to,0,values);
	cout << " ��������õ���ȨֵΪ: " << v;
	// ���
	//DirectedGraph* result2 = getMaxWeightValueBySpanErgodic();

	// compare two results is same
	//cout << compare( result, result2 );

	return NULL;
}



/**
 * ��������
 * node: �����˴���㵽node->pointIndex��Ȩ
 * from: ��ǰ�����
 * to: Ŀ��ڵ���
 * maxWeightValue: ���Ȩֵ
 */

int DirectedGraph::getMaxWeightValueByDepthErgodic( DirectedGraphNode* node, int to, int weightvalue, list<int>* values ) {
	// ���δ�ҵ�Ŀ��ڵ�node��Ϊ��, ˵����·��ͨ
	if ( node == NULL ) {
		return biggest + weightvalue;
	}
	// ���node��ָ�ڵ�ΪĿ��ڵ�, ˵����������
	// ���ؼ�Ȩֵ
	if ( node->getPointIndex() == to ) {
		values->push_back( weightvalue + node->getValue( ));
	}
	// δ����Ŀ��ڵ�
	// ���δ������
	if ( !node->isSearch( ) ) {
		node->search( );// ���Ϊ�ѱ�����
		int value = weightvalue + node->getValue( );
		getMaxWeightValueByDepthErgodic( getRawNodeOfFrom( root, node->getPointIndex( ) ), to,value, values );
		// ���Ϊδ������
		node->unsearch( );
			
		return value;
	}
	return 0;

}

DirectedGraphNode* DirectedGraph::getRawNodeOfFrom( DirectedGraphNode* root, int pointIndex ) {
	DirectedGraphNode* node = root;
	for ( int i = 0; i < pointIndex; i++ ) {
		node = node->getRaw();
	}

	return node;
}

//
//DirectedGraph* DirectedGraph::getMaxWeightValueBySpanErgodic() {
//	return NULL;
//}