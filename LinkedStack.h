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
		top = nullptr;
	}

	Stack(const Stack<T>& obj) {
		if (obj.top == nullptr)
			top = nullptr;
	}

	~Stack() {
		while (top != nullptr) {
			StackNode<T>* nextNode = top->next;
			delete top;
			top = nextNode;
		}
	}

	void push(const T& item) {
		StackNode<T>* nodeToPush = new StackNode(item);
		nodeToPush->next = top;
		top = nodeToPush;

		size++;
	}

	T pop() {
		if (isEmpty())
			throw runtime_error("Stack Underflow!");

		StackNode<T>* nodeToPop = top;
		top = top->next;
		T valueToPop = nodeToPop->value;
		delete nodeToPop;

		size--;

		return valueToPop;
	}

	T peek() {
		if (isEmpty())
			throw runtime_error("Stack Underflow!");

		return top->value;
	}

	bool isEmpty() {
		return top == nullptr;
	}

	int getSize() {
		return size;
	}
private:
	StackNode<T>* top;
	int size;
};

#endif 
