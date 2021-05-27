#ifndef SRC_TOKENMGR_H_
#define SRC_TOKENMGR_H_
#include <string>
#include "Token.h"
using namespace std;

class TokenMgr {
public:
	TokenMgr(string str);
	Token* getNextToken();	//获得下一个Token
private:
	void getNextChar();		//处理下一个字符
	string _str;
	string _buff;
	string::iterator _curr;
	int _currCol;
	Token* _token;
};

#endif /* SRC_TOKENMGR_H_ */
