#ifndef NODE_CPP
#define NODE_CPP

class Node{
public:
	Node *left, *right;

	Node(int value, bool isNum) :_value(value), _isNumber(isNum){
		left = nullptr;
		right = nullptr;
	}
	
	bool isNumber(){ return _isNumber; };
	int getValue(){ return _value; };

protected:
	bool _isNumber;
	int _value;
};

#endif

