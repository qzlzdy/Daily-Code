#include "ParserException.h"
#include <iostream>
using namespace std;

ParserException::ParserException(Token* miss,string errorMessage){
	_msg = errorMessage;
	_currToken = miss;
}

ParserException::ParserException(string errorMessage){
	_msg = errorMessage;
	_currToken = nullptr;
}

void ParserException::getMessage(){
	if(_currToken != nullptr){
		cout<<"Encountered \""<<_currToken->image;
		cout<<"\" on column "<<_currToken->beginCol;
		cout<<". "<<_msg<<endl;
	}else
		cout<<_msg<<endl;
}
