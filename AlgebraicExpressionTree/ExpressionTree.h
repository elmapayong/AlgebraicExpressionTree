#ifndef EXPRESSIONTREE
#define EXPRESSIONTREE

#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include "Node.cpp"
using namespace std;

struct expression{
	int value;
	bool isNum;
};


class ExpressionTree{
public:
	Node* makeTree(const std::string);
	Node* orderTree(vector<expression>, int, int);
	vector<expression> parseExp(const std::string);
	int skipInsideParanthesis(vector<expression>, int, int);
private:
	void makeNode(int, bool);
};

#endif