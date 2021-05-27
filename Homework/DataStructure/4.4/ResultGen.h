#ifndef SRC_RESULTGEN_H_
#define SRC_RESULTGEN_H_
#include <stack>
using namespace std;

class ResultGen {
public:
	ResultGen();
	void pushID(int ID);	//添加操作数
	void endcode();		//表达式结束，输出最终结果
	void compute(int op);	//进行op操作
	void stop();	//停止工作
private:
	stack<int> _S;
	int _size;
	bool _enable;
};

#endif /* SRC_RESULTGEN_H_ */
