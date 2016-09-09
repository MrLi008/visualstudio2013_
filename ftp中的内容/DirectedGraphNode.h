
#ifndef MY_FILENAME_DIRECTEDGRAPHNODE
#define MY_FILENAME_DIRECTEDGRAPHNODE


#include"ObjectEnablePrint.h"
//#include"funcs.h"

#endif


#pragma once
// need files

// declare the class
class DirectedGraphNode :
	public ObjectEnablePrint
{
public:
	DirectedGraphNode();
	DirectedGraphNode(int pValue);
	~DirectedGraphNode();
	void print(void);

public:

	void setPointIndex( int ppointIndex );
	int getPointIndex();

	void setValue(int pValue);
	int getValue();

	void setCol(DirectedGraphNode* pcol);
	void setRaw(DirectedGraphNode* praw);

	DirectedGraphNode* getCol();
	DirectedGraphNode* getRaw();

	void search();
	void unsearch();
	bool isSearch();

private:
	// 节点编号
	int pointIndex;
	/**
	 * true for 已被搜索
	 * false for 未被搜索
	 */
	bool isSearched;
	int value;// 权
	DirectedGraphNode* col;// 列
	DirectedGraphNode* raw;// 行
};

