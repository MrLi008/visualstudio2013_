/*******************************************************************
 *
 * ��������:
 * 1, ���ݶ�ά���齨���ڽӱ�
 * 2, ��ӡ�ڽӱ�
 * 3, �������·��? 
 *		��raw��ָ�Ľڵ��value�ǽڵ�ı��
 *		��col��ָ�Ľڵ��value��·����Ȩ, ����������raw�½ڵ�, pointIndexΪ�յ�
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

	// Ѱ�����·��
	DirectedGraph* getShortestWay( int from, int to );

private:
	// �����㷨
	int getMaxWeightValueByDepthErgodic( DirectedGraphNode* , int, int, list<int>*);
	//DirectedGraph* getMaxWeightValueBySpanErgodic();

	// �Ƚ��㷨�Ľ���Ƿ���ͬ
	bool compare( DirectedGraph*, DirectedGraph* );

	DirectedGraphNode* getRawNodeOfFrom( DirectedGraphNode*, int );
private:
	// �ڵ��Ŵ�0��ʼ
	// ���ڵ�, col��ʾ��������, ��raw��ָ����col��Ȩ
	DirectedGraphNode* root;
	const int biggest = 100000;

};