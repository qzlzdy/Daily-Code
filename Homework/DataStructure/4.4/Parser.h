/*
 * ‘¥”Ô—‘Œƒ∑®£∫
 * program: express <END>
 * express: "(" operator express express ")" | ("-") <ID>
 * operator: "+" | "-" | "*" | "/"
 */

#ifndef SRC_PARSER_H_
#define SRC_PARSER_H_
#include "TokenMgr.h"
#include "ResultGen.h"

class Parser {
public:
	Parser(TokenMgr& tm,ResultGen& rg);
	~Parser();
	void parse();
private:
	void advance();
	void consume(int expected);
	void program();
	void express();
	int oper();
	TokenMgr& _tm;
	ResultGen& _rg;
	Token* _currToken;
	Token* _prevToken;
};

#endif /* SRC_PARSER_H_ */
;
