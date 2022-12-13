#include "List.h"

void List::addRoad(int town)
{
	if (m_head == nullptr) {
		m_head = new List::ListNode(town, nullptr);
		return;
	}

	List::ListNode * curr = m_head, * next = curr->next;
	bool finished = false;
	while (!finished && next != nullptr) {
		if (next->data < town) {
			curr = next;
			next = curr->next;
		}
		else if (next->data == town)
			finished = true;
		else {
			List::ListNode* node = new List::ListNode(town, nullptr);
			node->next = next;
			curr->next = node;
			finished = true;
		}
	}
	if (!finished) {
		if (m_head->data == town)
			return;
		else if (m_head->data > town) {
			List::ListNode* node = new List::ListNode(town, m_head);
			m_head = node;
		}
		else
			curr->next = new List::ListNode(town, nullptr);
	}
}
