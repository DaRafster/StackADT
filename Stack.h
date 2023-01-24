#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
public:
	Stack() {
		capacity = 10;
		s = new T[capacity];
		size = 0;
	}

	~Stack() {
		delete[] s;
	}

	void push(const T& item) {
		if (getSize() == capacity)
			expand();

		s[size++] = item;
	}
	 
	T pop() {
		if (isEmpty())
			throw runtime_error("Stack Underflow!");

		return s[--size];
	}

	T top() {
		if (isEmpty())
			throw runtime_error("Stack Underflow!");

		return s[size--];
	}

	bool isEmpty() {
		return size == 0;
	}

	int getSize() {
		return size;
	}
private:

	void expand() {
		capacity *= 2;

		T temp = new T[capacity];

		for (int i = 0; i < size; i++)
			temp[i] = s[i]

		delete[] s;
		s = temp;
	}

	T* s;
	int size;
	int capacity;
};

#endif 
