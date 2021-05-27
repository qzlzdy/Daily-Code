#include <iostream>
#include <string>
#include "TokenMgr.h"
#include "ResultGen.h"
#include "Parser.h"
#include "ParserException.h"
using namespace std;

int main(){
	string str;
	while(getline(cin,str)){
		TokenMgr tm(str);
		ResultGen rg;
		Parser parser(tm,rg);
		parser.parse();
	}
}
