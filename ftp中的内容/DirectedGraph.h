
#ifndef MY_FILENAME_DIRECTEDGRAPH
#define MY_FILENAME_DIRECTEDGRAPH

//#include "ObjectEnablePrint.h"



#include "DirectedGraphNode.h"
//#include "funcs.h"

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

private:
	DirectedGraphNode* root;
	const int biggest = 100000;

};