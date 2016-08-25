
#include "stdafx.h"
//#include "MyHandle.h"
//
//template< class T>
//MyHandle<T>::MyHandle(void){
//	p = NULL;
//	cout << "initialize this instance" << endl;
//}

//template< class T>
//MyHandle<T>::MyHandle( MyHandle& s){
//	p = NULL;
//	if (s.p != NULL){
//		p = s.p->clone();
//	}
//}
//
//template< class T>
//MyHandle<T>& MyHandle<T>::operator=(const MyHandle<T>& rhs){
//	if (&rhs != this){
//		delete p;
//		p = rhs.p ? rhs.p->clone() : 0;
//	}
//	return *this;
//}
//
//template< class T>
//MyHandle<T>::~MyHandle<T>(){
//	if (p != NULL){
//		delete p;
//		p = NULL;
//	}
//}
//
//template< class T>
//MyHandle<T>::MyHandle<T>(T* t){
//	if (t == NULL){
//		this->p = NULL;
//	}
//	else{
//		this->p = t;
//	}
//}
//
//template<class T>
//T& MyHandle<T>::operator*()const {
//	if (p != NULL){
//		return *p;
//	}
//	throw runtime_error("Ubbound Handle");
//
//}
//
//template< class T>
//T* MyHandle<T>::operator->() const{
//	if (p != NULL){
//		return p;
//	}
//	throw runtime_error("Ubound Handle");
//}














