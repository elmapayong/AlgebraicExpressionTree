#include "ExpressionTree.h"



Node* ExpressionTree::makeTree(vector<expression> list){
	Node *root;
	int begin = 0;
	int end = list.size() - 1;

	root = orderTree(list, begin, end);

	return root;
}


Node* orderTree(vector<expression> list, int begin, int end){
	
}





vector<expression> ExpressionTree::parseExp(const std::string exp){
	char currChar;
	int start, temp;
	int strLength = exp.length();
	vector<expression> expList;
	expression currExp;

	for (int i = 0; i < strLength; ++i){

		//eat white space
		if (exp[i] == ' '){
			++i;
		}

		//found a number
		else if (isdigit(exp[i])){
			start = i;
			//find where the number ends
			while ((++i) < strLength && isdigit(exp[i])){}

			//convert found number(str) to int
			temp = stoi(exp.substr(start, (i - start)), nullptr, 10);

			//attach number to list
			currExp.value = temp;
			currExp.isNum = true;
			expList.push_back(currExp);

			--i;
		}

		//found operator, includes parenthesis
		else if (exp[i] > 39 && exp[i] < 48 && exp[i] != ',' && exp[i] != '.'){
			//attach operation to list
			currExp.value = exp[i];
			currExp.isNum = false;
			expList.push_back(currExp);
		}

		//not valid
		else{
			expList.clear();
			return expList;
		}
	}

	return expList;
}
