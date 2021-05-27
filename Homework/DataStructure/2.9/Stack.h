#ifndef STACK_H_
#define STACK_H_
#include "Node.h"
#include "Maze.h"

template<class T>
class Stack {
public:
	Stack();	//O(1)
	~Stack();	//O(n)
	T top();	//·ÃÎÊÕ»¶¥	O(1)
	void push(T p);		//Ñ¹Õ»	O(1)
	void pop();		//µ¯³ö	O(1)
	bool empty();	//·µ»ØÊÇ·ñÎª¿ÕÕ»	O(1)
	void clear();	//Çå¿Õ	O(n)
	friend class Maze;
private:
	Node<T>* _top;
	int _size;
};

template<class T>
Stack<T>::Stack(){
	_top = new Node<T>(T());
	_size = 0;
}

template<class T>
Stack<T>::~Stack(){
	clear();
	delete _top;
}

template<class T>
T Stack<T>::top(){
	return _top->next->data;
}

template<class T>
void Stack<T>::push(T p){
	Node<T>* P = new Node<T>(p);
	P->next = _top->next;
	_top->next = P;
	_size++;
}

template<class T>
void Stack<T>::pop(){
	Node<T> *P = _top->next;
	_top->next = P->next;
	_size--;
	delete P;
}

template<class T>
bool Stack<T>::empty(){
	return _size == 0;
}

template<class T>
void Stack<T>::clear(){
	while(_size)
		pop();
}

#endif /* STACK_H_ */
