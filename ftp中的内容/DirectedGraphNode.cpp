#include "DirectedGraphNode.h"
#include "funcs.h"


DirectedGraphNode::DirectedGraphNode()
{
	pointIndex = 0;
	value = 0;
	col = NULL;
	raw = NULL;
	isSearched = false;
}
DirectedGraphNode::DirectedGraphNode(int pValue){
	pointIndex = 0;
	value = pValue;
	col = NULL;
	raw = NULL;
	isSearched = false;
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
	cout << "{" << pointIndex << ": " << value<< "|" << isSearched << "}";
}


int DirectedGraphNode::getPointIndex() {
	return pointIndex;
}
void DirectedGraphNode::setPointIndex( int ppointIndex ) {
	pointIndex = ppointIndex;
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


void DirectedGraphNode::search() {
	isSearched = true;
}

void DirectedGraphNode::unsearch() {
	isSearched = false;
}

bool DirectedGraphNode::isSearch() {
	return isSearched;
}

//// add
// 考虑到:
	// 1, 对类内部, 不递归访问.
	// 2, 只实现对这个类的实例的节点的访问, 不实现对这个类的属性相关节点的访问
	// 3, 递归的访问交由上层包装类来完成
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