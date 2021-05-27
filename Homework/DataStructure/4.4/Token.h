#ifndef SRC_TOKEN_H_
#define SRC_TOKEN_H_
#include <string>
using namespace std;

class Token{
public:
	Token();
	int kind;
	int beginCol;
	string image;
};

#endif /* SRC_TOKEN_H_ */
