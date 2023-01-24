#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

template <typename T>
class StackNode {
public:
	StackNode() {};
	StackNode(const T& v) {
		value = b;
		next = nullptr;
	}

	T value;
	StackNode<T>* next;
};

template <typename T>
class Stack {
public:
	Stack() {
		size = 0;
		s = nullptr;
	}

	~Stack() {
		delete[] s;
	}

	void push(const T& item) {
		StackNode<T>* nodeToPush = new StackNode(item);
		nodeToPush->next = top;
		top = nodeToPush;
	}
private:
	StackNode<T>* top;
	int size;
};

#endif 