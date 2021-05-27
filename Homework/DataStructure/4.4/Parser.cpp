#include <iostream>
#include <string>
#include "Parser.h"
#include "Constants.h"
#include "ParserException.h"
using namespace std;

Parser::Parser(TokenMgr& tm,ResultGen& rg):_tm(tm),_rg(rg){
	_prevToken = nullptr;
	_currToken = _tm.getNextToken();
}

Parser::~Parser(){
	if(_currToken != nullptr)
		delete _currToken;
	if(_prevToken != nullptr)
		delete _prevToken;
}

void Parser::advance(){
	if(_prevToken != nullptr)
		delete _prevToken;
	_prevToken = _currToken;
	_currToken = _tm.getNextToken();
}

void Parser::consume(int expected){
	if(expected == _currToken->kind)
		advance();
	else
		throw ParserException(_currToken,"Expecting " + tokenImage[expected]);
}

void Parser::parse(){
	try{
		program();
		_rg.endcode();
	}catch(ParserException& e){
		e.getMessage();
	}
}

void Parser::program(){
	express();
	consume(END);
}

void Parser::express(){
	int sym = 1;
	if(_currToken->kind == SUB){
		sym = -1;
		consume(SUB);
	}
	if(_currToken->kind == ID){
		_rg.pushID(sym * stoi(_currToken->image));
		consume(ID);
	}else if(_currToken->kind == LEFTPAREN){
		consume(LEFTPAREN);
		int op = oper();
		express();
		express();
		consume(RIGHTPAREN);
		_rg.compute(op);
	}else
		throw ParserException(_currToken,"Expecting \"(\" or <ID>");
}

int Parser::oper(){
	switch(_currToken->kind){
	case ADD:
		consume(ADD);
		return ADD;
	case SUB:
		consume(SUB);
		return SUB;
	case MUL:
		consume(MUL);
		return MUL;
	case DIV:
		consume(DIV);
		return DIV;
	default:
		throw ParserException(_currToken,"Expecting opeartor");
	}
}
