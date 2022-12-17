#pragma once

class List {
public:
	struct ListNode {
		int data;
		struct ListNode* next;

		ListNode(int _data, ListNode* _next) : data(_data), next(_next) {}
	};
private:
	ListNode* m_head;

public:
	List() { m_head = nullptr; }
	~List();
	
	void addRoad(int town);
	ListNode* getHead() { return m_head; }
};