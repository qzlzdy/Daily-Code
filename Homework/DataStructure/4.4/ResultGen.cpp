#include "ResultGen.h"
#include "Constants.h"
#include "ParserException.h"
#include <iostream>
using namespace std;

ResultGen::ResultGen(){
	_enable = true;
	_size = 0;
}

void ResultGen::pushID(int ID){
	_S.push(ID);
}

void ResultGen::endcode(){
	if(!_S.empty() && _enable)
		cout<<_S.top()<<endl;
}

void ResultGen::compute(int op){
	if(!_enable)
		return;
	int a = _S.top();
	_S.pop();
	int b = _S.top();
	_S.pop();
	switch(op){
	case ADD:
		_S.push(b + a);
		break;
	case SUB:
		_S.push(b - a);
		break;
	case MUL:
		_S.push(b * a);
		break;
	case DIV:
		if(a == 0)
			throw ParserException("Division by zero!");
		_S.push(b / a);
		break;
	}
}

void ResultGen::stop(){
	_enable = false;
}
