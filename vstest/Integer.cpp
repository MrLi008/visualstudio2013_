#include "stdafx.h"
#include "Integer.h"


Integer::Integer(){
	this->value = 0;;
}

Integer::Integer(int val){
	this->value = val;
}


Integer::~Integer(){
	cout << "delete Integer:" << this->value << endl;
}

void Integer::printInteger(){
	cout << "value: " << this->value << endl;
}

//bool Integer::operator==(const Integer& anotherInteger) const{
//	return this->value == anotherInteger.value;
//}

Integer* Integer::clone(){
	return new Integer(this->value);
}