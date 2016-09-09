/*******************************************************************
 *
 * 功能描述:
 * 1, 根据二维数组建立邻接表
 * 2, 打印邻接表
 * 3, 计算最短路径? 
 *		由raw所指的节点的value是节点的编号
 *		由col所指的节点的value是路径的权, 即出发点是raw下节点, pointIndex为终点
 */



#ifndef MY_FILENAME_DIRECTEDGRAPH
#define MY_FILENAME_DIRECTEDGRAPH

//#include "ObjectEnablePrint.h"



#include "DirectedGraphNode.h"
//#include "funcs.h"
#include <list>

#endif
#pragma once

class DirectedGraph :
	public ObjectEnablePrint
{
public:
	DirectedGraph();
	DirectedGraph(int graph[5][5], int columns, int raws);

	~DirectedGraph();

	void print();


//private:
	void printNode(DirectedGraphNode* node);

	// 寻找最短路径
	DirectedGraph* getShortestWay( int from, int to );

private:
	// 搜索算法
	int getMaxWeightValueByDepthErgodic( DirectedGraphNode* , int, int, list<int>*);
	//DirectedGraph* getMaxWeightValueBySpanErgodic();

	// 比较算法的结果是否相同
	bool compare( DirectedGraph*, DirectedGraph* );

	DirectedGraphNode* getRawNodeOfFrom( DirectedGraphNode*, int );
private:
	// 节点编号从0开始
	// 跟节点, col表示具有连接, 由raw所指到此col的权
	DirectedGraphNode* root;
	const int biggest = 100000;

};