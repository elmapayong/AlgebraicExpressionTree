#include <iostream>
#include <string>
#include "ExpressionTree.h"

#include <ctype.h>

using namespace std;

int main(){
	string exp = "35+(6*7)";
	string lala = "!";

	ExpressionTree str;
	//Node *tree = str.makeTree(exp);

	vector<expression> list;
	list = str.makeExpList(exp);

	cout << list[0].value << " " << list[list.size()-1].value << endl;
	

	//cout << isdigit(str[2]);

	//for (string::const_iterator k = str.begin(); k != str.end(); k++){
	//	isNum &&= isdigit(*k);
	//	cout << isNum << endl;
	//}

	//string::const_iterator k = str.begin() + 3;
	//string *p;

	//int i = stoi(str, nullptr, 10);
	//cout << i << endl;


	//char curr;
	//int start;
	//string temp;

	//cout << str.length() << endl;

	//for(int i = 0; i < str.length(); i++){
	//	curr = str[i];
	//	//it's a number
	//	if (isdigit(curr)){
	//		start = i;
	//		//find where the number ends
	//		while ((++i) < str.length() && isdigit(str[i])){}
	//		cout << "curr i: " << i << "  ";
	//		temp = str.substr(start, (i - start));
	//		cout << temp << endl;
	//		--i;
	//	}

	//}

	//char currChar;
	//int start, strLength, temp;
	//strLength = exp.length();

	//for (int i = 0; i < strLength; i++){
	//	currChar = exp[i];

	//	//found a number
	//	if (isdigit(currChar)){
	//		start = i;
	//		//find where the number ends
	//		while ((++i) < strLength && isdigit(exp[i])){}

	//		//convert found number(str) to int
	//		temp = stoi(exp.substr(start, (i - start)), nullptr, 10);
	//		cout << temp << endl;




	//		--i;
	//	}

	//}




	




	system("pause");
}