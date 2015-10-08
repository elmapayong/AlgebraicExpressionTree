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
	
	//only contains a number
	if (begin == end){
		Node* temp = new Node(list[i].value, true);
		return temp;
	}
	//expressions given is inside parenthesis
	else if (list[begin].value == '('){
		if (list[end].value == ')'){
			++begin;
			--end;
			i = end;
		}
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

			--i;

		} while (!foundLowest && i != begin);
	}

	cout << "lowest found: " << indexOfLowest << endl;

	return nullptr;
}

//if it's an operation
	//if already found one:
		//if it's lower, replace lowest with that
		// then parse the left and right of it
			//attach left
			//attach right
	//if haven't found one
		//then set it as lowest
//if it's a parenthesis
	//keep going left until you find the end

//if nothing was found, it means it's a number node
	//make a number node and return it
	





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
