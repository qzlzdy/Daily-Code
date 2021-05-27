#ifndef SRC_PARSEREXCEPTION_H_
#define SRC_PARSEREXCEPTION_H_
#include "Token.h"
#include <string>
using namespace std;

class ParserException {
public:
	ParserException(Token* miss,string errorMessage);
	ParserException(string errorMessage);
	void getMessage();
private:
	string _msg;	//¥ÌŒÛ–≈œ¢
	Token* _currToken;
};

#endif /* SRC_PARSEREXCEPTION_H_ */
