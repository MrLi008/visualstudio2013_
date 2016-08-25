# include "stdafx.h"

# include <io.h>
# include <fstream>


void showfiles(vector<string> file){

	vector<string>::iterator it;
	for (it = file.begin(); it != file.end(); it++){
		cout << "filename: " << (*it).c_str() << endl;
	}
	cout << "endding..." << endl;
}

void getfilefromdir(string filepath, vector<string>& vfiles){



	long hFile = 0;

	struct _finddata_t fileinfo;
	string p;

	hFile = _findfirst(p.assign(filepath).append("\\*").c_str(), &fileinfo);


	if ((hFile) != -1){
		do{
			if ((fileinfo.attrib & _A_SUBDIR)){
				cout << "This is direction: <" << fileinfo.name << ">" << endl;
			}
			else{
				vfiles.push_back(p.assign(filepath).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
	showfiles(vfiles);
}


void findfrom(const vector<string> files, string str){
	
	ifstream input;

	input.open("D:\\exe\\hehe.txt", ios::in);

	char ch;
	while (input >> ch){
		if (ch == 13){
			cout << endl;
		}
		else{
			cout << ch;
		}
	}
	cout << endl << "end" << endl;


}