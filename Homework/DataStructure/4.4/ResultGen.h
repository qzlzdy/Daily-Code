#ifndef SRC_RESULTGEN_H_
#define SRC_RESULTGEN_H_
#include <stack>
using namespace std;

class ResultGen {
public:
	ResultGen();
	void pushID(int ID);	//��Ӳ�����
	void endcode();		//���ʽ������������ս��
	void compute(int op);	//����op����
	void stop();	//ֹͣ����
private:
	stack<int> _S;
	int _size;
	bool _enable;
};

#endif /* SRC_RESULTGEN_H_ */
