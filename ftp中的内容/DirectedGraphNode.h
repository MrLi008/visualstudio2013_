
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
	// �ڵ���
	int pointIndex;
	/**
	 * true for �ѱ�����
	 * false for δ������
	 */
	bool isSearched;
	int value;// Ȩ
	DirectedGraphNode* col;// ��
	DirectedGraphNode* raw;// ��
};

