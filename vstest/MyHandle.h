#pragma once
#include "stdafx.h"

// 近乎自动的内存管理


template< class T>
class MyHandle
{
public:
	MyHandle<T>(void){
		p = NULL;
		cout << "initialize this instance!" << endl;
	}
	MyHandle(const MyHandle& s){
		cout << "This is in MyHandle<Integer>(const MyHandle& s)" << endl;
		p = NULL;
		if (s.p != NULL){
			p = s.p->clone();
		}
	}

	MyHandle<T>(T* t){
		if (t == NULL){
			this->p = NULL;
		}
		else{
			this->p = t;
		}
	}
	

	~MyHandle<T>(){
		if (p != NULL){
			delete p;
			p = NULL;
			cout << "p is not NULL." << endl;
		}
		else{
			cout << "p is NULL." << endl;
		}
		cout << "delete this instance" << endl;
	}

	MyHandle& operator=(const MyHandle<T>& rhs)const {
		cout << "=|left: " << this << ", right: " << rhs;
		if (&rhs != this){
			delete p;
			p = rhs.p ? rhs.p->clone() : 0;
		}
		return *this;
	}

	bool operator==(const MyHandle<T>& rhs)const {
		cout << "left: " << this << ", right: " << rhs << endl;
		return (rhs.p == p);
		/*if (*this == *rhs){
			return true;
		}
		return false;*/
	}
	operator bool() const{
		cout << "In bool: " << this << endl;
		return p;
	}
	T& operator*() const{
		cout << "*|: " << this << endl;
		if (p != NULL){
			return *p;
		}
		throw runtime_error("Ubound Handle");
	}
	T* operator->() const{
		cout << "->|:" << this << endl;
		if (p != NULL){
			return p;
		}
		throw runtime_error("Ubound Handle");
	}




public:
	T* p;
};

