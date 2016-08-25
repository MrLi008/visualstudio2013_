# include "stdafx.h"
# include "declarefunctions.h"
# include <list>

void printstringlengthof(int length, char* charactors, int indexofcharactor, list<char> listofcharactors, int max=0){
	//int max = 0;
	max = max < length ? length : max;
	if (indexofcharactor < strlen(charactors) && length > 0){
	//	cout << *(charactors + indexofcharactor) << " ";
		listofcharactors.push_back(*(charactors + indexofcharactor));
		printstringlengthof(length - 1, charactors, indexofcharactor, listofcharactors, max);
		/*cout << endl;*/
		if (listofcharactors.size() >= max){
			list<char>::iterator it;
			cout << "::";
			for (it = listofcharactors.begin(); it != listofcharactors.end(); it++){
				cout << *it;
			}
			cout << endl;
		}
		/*for (int i = 0; i <= length; i++){
		listofcharactors.pop_back();
		}*/
		// listofcharactors.clear();
		listofcharactors.pop_back();
		// cout << endl;
		printstringlengthof(length, charactors, indexofcharactor + 1, listofcharactors, max);
	}
	else{
		//list<char>::iterator it;
		//cout << "::";
		//for (it = listofcharactors.begin(); it != listofcharactors.end(); it++){
		//	cout << *it;
		//}
		///*for (int i = 0; i <= length; i++){
		//	listofcharactors.pop_back();
		//}*/
		//listofcharactors.clear();
		//cout << endl;
		return;
	}
	// cout << endl << "length: " << length << ", index: " << listofcharactors.size() << endl;
	/*if (length > 0){

	}*/
	/*else{
		cout << endl;
	}*/
	
	
	/*else{
		cout << "index is endding" << endl;
	}*/
	
}

int testproductcharactors(){
	// 26个字母
	const int numofcharactors = 26;
	// 9数字
	const int numofinteger = 10;
	// 模板字符的总长度
	int lenofcharactors = 2 * numofcharactors;


	char* charactors = new char[lenofcharactors + numofinteger];


	for (int i = 0; i < numofcharactors; i++){

		// 依次给charactors 赋值
		*(charactors + i) = i + 'A';
		*(charactors + i + numofcharactors) = i + 'a';

	}
	for (int i = 0; i < numofinteger; i++){
		*(charactors + i + lenofcharactors) = i + '0';
	}

	lenofcharactors = lenofcharactors + numofinteger;

	// *(charactors + lenofcharactors) = '\0';
	for (int i = 0; i < lenofcharactors; i++){
		cout << *(charactors + i) << "\t";
	}
	cout << "endding" << endl;

	// print a string of length as 6

	printstringlengthof(8, charactors, 0, list<char>());
	
	cout << "endding" << endl;


	delete charactors;
	charactors = NULL;

	return 0;
}