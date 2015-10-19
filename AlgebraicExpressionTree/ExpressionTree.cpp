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
	int indexOfLowest = -1;
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


	if (begin == end){
		//only contains a number
		if (list[i].isNum == true){
			temp = new Node(list[i].value, true);
			return temp;
		}
	}
	//find left and right sides
	else{
		do{
			//found operator or parenthesis
			if (list[i].isNum == false){
				//found parenthesis
				if (list[i].value == ')'){
					i = skipInsideParenthesis(list, begin, --i);
					//no matching '('
					if (i == -1){
						return nullptr;
					}
				}
				//shouldn't come across '(' without first hitting a ')'
				//no matching parenthesis error
				else if (list[i].value == '('){
					return nullptr;
				}

				else if (list[i].value == '+' || list[i].value == '-'){
					foundLowest = true;
					indexOfLowest = i;
				}
				//found higher precedence (/ or *), save it if it's the first
				//one found but keep looking for a lower one
				else{
					//first one found
					if (indexOfLowest == -1){
						indexOfLowest = i;
					}

					//ignore all other / * found because
					//they're a higher precedence than
					//previous one found
				}
			}
			--i;

		} while (!foundLowest && i >= begin);

		//operator with no left or right operand
		if ((indexOfLowest - 1) < begin || (indexOfLowest + 1) > end){
			return nullptr;
		}
		//operator is next to another operator
		else if (list[indexOfLowest - 1].isNum == false || list[indexOfLowest + 1].isNum == false){
			return nullptr;
		}
		else{
			//make the operation a root
			Node *root = new Node(list[indexOfLowest].value, false);

			//recursively find the left and right sides
			root->left = orderTree(list, begin, (indexOfLowest - 1));
			root->right = orderTree(list, (indexOfLowest + 1), end);

			//left or right side is invalid
			if (root->left == nullptr || root->right == nullptr){
				delete root->left;
				delete root->right;
				delete root;
				return nullptr;
			}
			else{
				return root;
			}
		}
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
int ExpressionTree::skipInsideParenthesis(vector<expression> list, int begin, int end){
	int i = end;

	do{
		//found another parenthesis
		if (list[i].value == ')'){
			i = skipInsideParenthesis(list, begin, --i);
			//no matching '('
			if (i == -1){
				return -1;
			}
		}
	} while (--i >= begin && list[i].value != '(');

	++i;
	//no matching '(' found
	if (i == begin && list[i].value != '('){
		return -1;
	}
	else{
		return i;
	}
}


int ExpressionTree::getAnswer(Node *root){
	int left = 0, right = 0, answer = 0;
	
	//tree is empty
	if (root == nullptr){
		return 0;
	}
	else{
		//get left operand
		if (root->left->isNumber() == false){
			left = getAnswer(root->left);
		}
		else{
			left = root->left->getValue();
		}

		//get right operand
		if (root->right->isNumber() == false){
			right = getAnswer(root->right);
		}
		else{
			right = root->right->getValue();
		}

		switch (root->getValue()){
		case '*':
			answer = left * right;
			cout << left << " * " << right << " = " << answer << endl;
			break;
		case '/':
			answer = left / right;
			cout << left << " / " << right << " = " << answer << endl;
			break;
		case '+':
			answer = left + right;
			cout << left << " + " << right << " = " << answer << endl;
			break;
		case '-':
			answer = left - right;
			cout << left << " - " << right << " = " << answer << endl;
			break;
		}

		return answer;
	}
}
