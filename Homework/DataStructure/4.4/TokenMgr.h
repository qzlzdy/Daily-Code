#ifndef SRC_TOKENMGR_H_
#define SRC_TOKENMGR_H_
#include <string>
#include "Token.h"
using namespace std;

class TokenMgr {
public:
	TokenMgr(string str);
	Token* getNextToken();	//�����һ��Token
private:
	void getNextChar();		//������һ���ַ�
	string _str;
	string _buff;
	string::iterator _curr;
	int _currCol;
	Token* _token;
};

#endif /* SRC_TOKENMGR_H_ */
