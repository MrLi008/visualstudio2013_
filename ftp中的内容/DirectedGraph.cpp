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
	// 检测节点是否有效
	if ( from < 0 || to < 0 ) {
		cout << "节点编号无效";
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

	// 若未找到出发节点
	if ( i < from ) {
		cout << "未找到开始节点";
		return NULL;
	}

	// 到此, 已找到开始节点进行深度遍历或者广度遍历寻找目标节点
	// 深度
	list<int>* values = new list<int>();
	int v = getMaxWeightValueByDepthErgodic(start,to,0,values);
	cout << " 深度搜索得到的权值为: " << v;
	// 广度
	//DirectedGraph* result2 = getMaxWeightValueBySpanErgodic();

	// compare two results is same
	//cout << compare( result, result2 );

	return NULL;
}



/**
 * 参数解释
 * node: 保存了从起点到node->pointIndex的权
 * from: 当前起点编号
 * to: 目标节点编号
 * maxWeightValue: 最大权值
 */

int DirectedGraph::getMaxWeightValueByDepthErgodic( DirectedGraphNode* node, int to, int weightvalue, list<int>* values ) {
	// 如果未找到目标节点node就为空, 说明此路不通
	if ( node == NULL ) {
		return biggest + weightvalue;
	}
	// 如果node所指节点为目标节点, 说明搜索结束
	// 返回加权值
	if ( node->getPointIndex() == to ) {
		values->push_back( weightvalue + node->getValue( ));
	}
	// 未到达目标节点
	// 如果未被搜索
	if ( !node->isSearch( ) ) {
		node->search( );// 标记为已被搜索
		int value = weightvalue + node->getValue( );
		getMaxWeightValueByDepthErgodic( getRawNodeOfFrom( root, node->getPointIndex( ) ), to,value, values );
		// 标记为未被搜索
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