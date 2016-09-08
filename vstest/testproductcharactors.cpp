# include "stdafx.h"
# include "declarefunctions.h"
# include <list>

void printstringlengthof(int length, char* charactors, int indexofcharactor, list<char> listofcharactors, int max=0){
	//int max = 0;
	max = max <= length ? length : max;
	if ( indexofcharactor < 62 && length > 0){
	//	cout << *(charactors + indexofcharactor) << " ";
		listofcharactors.push_back(*(charactors + indexofcharactor));
		printstringlengthof(length - 1, charactors, 0, listofcharactors, max);
		/*cout << endl;*/
		ofstream output("stringSet.txt", ios::app);
		if (true || listofcharactors.size() >= max){
			list<char>::iterator it;
		//	cout << "::";
			for (it = listofcharactors.begin(); it != listofcharactors.end(); it++){
		//		cout << *it;
				output << *it;
			}
			output << "\r\n";
			// cout << endl;
			//cout << "list:" << listofcharactors.size() << ", max: " << max << "length:" << length << "\n";
		}
		output.close();
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
	int length = lenofcharactors + numofinteger;

	char* charactors = new char[length];


	for (int i = 0; i < numofcharactors; i++){

		// 依次给charactors 赋值
		*(charactors + i) = i + 'A';
		*(charactors + i + numofcharactors) = i + 'a';

	}
	for (int i = 0; i < numofinteger; i++){
		*(charactors + i + lenofcharactors) = i + '0';
	}

	*(charactors + lenofcharactors + numofcharactors) = '\0';
	

	// lenofcharactors = lenofcharactors + numofinteger;

	// *(charactors + lenofcharactors) = '\0';
	for (int i = 0; i < length; i++){
		cout << *(charactors + i) << ",";
	}
	cout << "\nendding: "<< strlen(charactors) << endl;

	// print a string of length as 6
	for (int i = 0; i < 6; i++){
		printstringlengthof(i+6 , charactors, 0, list<char>());
		cout << "bit: " << i << endl;
	}
	cout << "endding" << endl;

	cout << sizeof(charactors);
	delete charactors;
	charactors = NULL;

	return 0;
}