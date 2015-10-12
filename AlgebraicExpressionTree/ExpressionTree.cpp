#include "ExpressionTree.h"



Node* ExpressionTree::makeTree(const std::string expStr){
	Node *root;
	int begin = 0;
	int end;

	vector<expression> list = parseExp(expStr);
	end = list.size() - 1;

	root = orderTree(list, begin, end);

	return root;
}


Node* ExpressionTree::orderTree(vector<expression> list, int begin, int end){
	int indexOfLowest = 0;
	int i = end;
	bool foundOp = false;
	bool foundLowest = false;
	Node *temp = nullptr;
	

	//expression given is inside parenthesis
	if (list[begin].value == '(' && list[end].value == ')'){
		//adjust to only look inside its contents
		++begin;
		--end;
		i = end;

		//nothing inside parenthesis
		if (end < begin){
			return nullptr;
		}
	}


	//only contains a number
	if (begin == end){
		temp = new Node(list[i].value, true);
		return temp;
	}
	//find left and right sides
	else{
		do{
			//found operator
			if (list[i].isNum == false){
				if (list[i].value == '+' || list[i].value == '-'){
					foundLowest = true;
					indexOfLowest = i;
				}
				//found higher precedence, save it but
				//keep looking for a lower one
				else{
					indexOfLowest = i;
				}
			}
			//found parenthesis
			if (list[i].value == ')'){
				i = skipInsideParanthesis(list, begin, --i);
				//no matching '('
				if (i == -1){
					return nullptr;
				}
			}
			--i;

		} while (!foundLowest && i != begin);

		////make operation root
		//

		////find and attach left side
		//Node *left = orderTree(list, begin, (i - 1));
		//Node *right = orderTree(list, (i + 1), end);
		
	}

	//reaches here if invalid. returns nullptr
	return temp;
}




vector<expression> ExpressionTree::parseExp(const std::string exp){
//	char currChar;
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


//returns -1 if corresponding ( not found in range
//else returns index of (
int ExpressionTree::skipInsideParanthesis(vector<expression> list, int begin, int end){
	int i = end;

	do{
		//found another parenthesis
		if (list[i].value == ')'){
			i = skipInsideParanthesis(list, begin, --i);
			//no matching '('
			if (i == -1){
				return -1;
			}
		}
	} while (list[--i].value != '(' && i >= begin);

	//no matching '(' found
	if (i == begin){
		return -1;
	}
	else{
		return i;
	}
}
