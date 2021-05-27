#ifndef SRC_CONSTANTS_H_
#define SRC_CONSTANTS_H_
#include <string>
using namespace std;

int const ADD = 0;
int const SUB = 1;
int const MUL = 2;
int const DIV = 3;
int const ID = 4;
int const LEFTPAREN = 5;
int const RIGHTPAREN = 6;
int const ERROR = 7;
int const END = 8;
string const tokenImage[] = {
		"\"+\"",
		"\"-\"",
		"\"*\"",
		"\"/\"",
		"<ID>",
		"\"(\"",
		"\")\"",
		"<ERROR>",
		"<END>"
};

#endif /* SRC_CONSTANTS_H_ */
