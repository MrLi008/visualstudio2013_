#include "DirectedGraphNode.h"
#include "funcs.h"


DirectedGraphNode::DirectedGraphNode()
{
	value = 0;
}
DirectedGraphNode::DirectedGraphNode(int pValue){
	value = pValue;
}


DirectedGraphNode::~DirectedGraphNode()
{
	if (col != NULL){
		delete col;
	}
	if (raw != NULL){
		delete raw;
	}
}

void DirectedGraphNode::print(){
	// cout << "This is in Directed Graph class" << endl;
	cout << "val: " << value;
}

void DirectedGraphNode::setValue(int pValue){
	value = pValue;
}

int DirectedGraphNode::getValue(){
	return value;
}
void DirectedGraphNode::setCol(DirectedGraphNode* pcol){
	col = pcol;
}
void DirectedGraphNode::setRaw(DirectedGraphNode* praw){
	raw = praw;
}
DirectedGraphNode* DirectedGraphNode::getCol(){
	return col;
}
DirectedGraphNode* DirectedGraphNode::getRaw(){
	return raw;
}


//// add
// ���ǵ�:
	// 1, �����ڲ�, ���ݹ����.
	// 2, ֻʵ�ֶ�������ʵ���Ľڵ�ķ���, ��ʵ�ֶ�������������ؽڵ�ķ���
	// 3, �ݹ�ķ��ʽ����ϲ��װ�������
//bool DirectedGraphNode::addCol(DirectedGraphNode* next){
//	if (next == NULL){
//		return false;
//	}
//	DirectedGraphNode* temp = col->getCol();
//	next->setCol(temp);
//	col->setCol(next);
//	return true;
//}
//bool DirectedGraphNode::addRaw(DirectedGraphNode* next){
//	raw = next;
//	return true;
//}