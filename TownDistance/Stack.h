#pragma once

class Stack {
	int* m_arr;
	int m_head;
	int m_size;

public:
	Stack(int _size) : m_size(_size), m_head(0) { m_arr = new int[_size]; }
	bool isEmpty() { return m_head == 0; }
	bool isFull() { return m_head == m_size; }
	int Pop();
	int Top();
	void Push(int town);
};