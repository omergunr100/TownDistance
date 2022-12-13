#include "Stack.h"

int Stack::Pop()
{
	if (!isEmpty())
	{
		return m_arr[--m_head];
	}
	return -1;
}

int Stack::Top()
{
	if (!isEmpty())
	{
		int temp = m_arr[m_head-1];
		return temp;
	}
	return -1;
}

void Stack::Push(int town)
{
	if (!isFull())
		m_arr[m_head++] = town;
}
