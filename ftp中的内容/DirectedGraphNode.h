
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
	void setValue(int pValue);
	int getValue();

	void setCol(DirectedGraphNode* pcol);
	void setRaw(DirectedGraphNode* praw);

	DirectedGraphNode* getCol();
	DirectedGraphNode* getRaw();

private:
	int value;// È¨
	DirectedGraphNode* col;// ÁÐ
	DirectedGraphNode* raw;// ÐÐ
};

