#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include "List.h"
#include "Stack.h"

using std::vector;
using std::cin;
using std::cout;
using std::endl;

enum class COLOR{WHITE, BLACK};

int recursiveDistance(vector<List>& country, int x, int w, vector<COLOR> colors) {
	if (x == w)
		return 0;
	colors[x - 1] = COLOR::BLACK;

	List::ListNode* curr = country[x - 1].getHead();
	if (curr == nullptr)
		return -1;
	int distance = -2;
	while (curr != nullptr && distance < 0) {
		if (colors[curr->data - 1] == COLOR::WHITE)
			distance = recursiveDistance(country, curr->data, w, colors);
		curr = curr->next;
	}
	return distance == -1 ? distance : distance + 1;
}

int stackDistance(vector<List>& country, int x, int w, vector<COLOR> colors) {
	Stack s(country.size());

	s.Push(x);
	int curr, distance = 0;
	List::ListNode* node;
	while (!s.isEmpty()) {
		curr = s.Pop();
		colors[curr - 1] = COLOR::BLACK;
		if (curr == w) {
			while (!s.isEmpty()) {
				s.Pop();
				distance++;
			}
			return distance;
		}
		else {
			node = country[curr - 1].getHead();

			while (node != nullptr) {
				if (colors[node->data - 1] == COLOR::WHITE) {
					s.Push(curr);
					s.Push(node->data);
					node = nullptr;
				}
				else {
					node = node->next;
				}
			}
		}
	}
	return -1;
}

int main() {
	int numTowns, numRoads;
	cin >> numTowns;
	cin >> numRoads;

	vector<List> country;
	country.reserve(numTowns);
	vector<COLOR> colors;
	colors.reserve(numTowns);

	for (int i = 0; i < numTowns; i++) {
		country.emplace_back();
		colors.emplace_back(COLOR::WHITE);
	}

	for (int i = 0; i < numRoads; i++) {
		int a, b;
		cin >> a;
		cin >> b;
		if (a < 1 || b < 1 || a > numTowns || b > numTowns) {
			cout << "Error, user input doesn't match specifications!" << endl;
			exit(1);
		}
		country[a - 1].addRoad(b);
		country[b - 1].addRoad(a);
	}
	//int temp = recursiveDistance(country, 3, 4, colors);
	int temp = stackDistance(country, 2, 5, colors);
	cout << endl;
	cout << temp << endl;
}