#include <iostream>
#include "TokenMgr.h"
#include "Constants.h"

TokenMgr::TokenMgr(string str){
	_str = str;
	_curr = _str.begin();
	_token = nullptr;
	_currCol = 1;
}

bool isDigit(char d){
	return d >= '0' && d <= '9';
}

Token* TokenMgr::getNextToken(){
	while(*_curr == ' ')
		getNextChar();
	_token = new Token();
	//表达式结束
	if(_curr == _str.end()){
		_token->kind = END;
		_token->image = "<END>";
		_token->beginCol = _currCol;
	//操作数情况
	}else if(isDigit(*_curr)){
		_buff = "";
		do{
			_buff += *_curr;
			_token->beginCol = _currCol;
			getNextChar();
		}while(isDigit(*_curr));
		_token->kind = ID;
		_token->image = _buff;
	//操作符情况
	}else{
		switch(*_curr){
		case '+':
			_token->kind = ADD;
			_token->image = "+";
			break;
		case '-':
			_token->kind = SUB;
			_token->image = "-";
			break;
		case '*':
			_token->kind = MUL;
			_token->image = "*";
			break;
		case '/':
			_token->kind = DIV;
			_token->image = "/";
			break;
		case '(':
			_token->kind = LEFTPAREN;
			_token->image = "(";
			break;
		case ')':
			_token->kind = RIGHTPAREN;
			_token->image = ")";
			break;
		default:
			_token->kind = ERROR;
			_token->image = "<ERROR>";
			break;
		}
		_token->beginCol = _currCol;
		getNextChar();
	}
	return _token;
}

void TokenMgr::getNextChar(){
	if(_curr != _str.end()){
		_curr++;
		_currCol++;
	}
}
