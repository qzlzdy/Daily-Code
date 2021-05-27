#ifndef NODE_H_
#define NODE_H_

template<class T>
class Node{
public:
	Node(T d);
	T data;		//������
	Node<T>* next;		//ָ����
};

template<class T>
Node<T>::Node(T d){
	data = d;
	next = nullptr;
}

#endif /* NODE_H_ */
