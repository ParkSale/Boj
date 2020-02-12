#include <iostream>
using namespace std;
char str[100005];
int M;
struct Node {
	char ch;
	Node* prev;
	Node* next;
}nodes[600005];
int nodeCnt;

Node* now;

struct List {
	Node head, tail;

	void init() {
		head.next = &tail; tail.prev = &head;
		head.prev = nullptr; tail.next = nullptr;
	}

	void insert(char ch) {
		Node* newNode = &nodes[nodeCnt++];
		newNode->ch = ch;
		newNode->next = now->next; newNode->prev = now;
		newNode->next->prev = newNode; newNode->prev->next = newNode;
		now = newNode;
	}

}list;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> str >> M;
	int idx = 0;
	list.init();
	while (str[idx] != 0) {
		Node* newNode = &nodes[nodeCnt++];
		newNode->ch = str[idx];
		newNode->next = &list.tail; newNode->prev = list.tail.prev;
		newNode->next->prev = newNode; newNode->prev->next = newNode;
		now = newNode;
		++idx;
	}
	while (M--) {
		char ch;
		cin >> ch;
		if (ch == 'L') {
			if (now == &list.head) {
				continue;
			}
			else {
				now = now->prev;
			}
		}
		else if (ch == 'D') {
			if (now == list.tail.prev) {
				continue;
			}
			else {
				now = now->next;
			}
		}
		else if (ch == 'B') {
			if (now == &list.head) {
				continue;
			}
			else {
				now->prev->next = now->next; now->next->prev = now->prev;
				now = now->prev;
			}
		}
		else {
			char c;
			cin >> c;
			list.insert(c);
		}
	}
	Node* n = list.head.next;
	while (n != &list.tail) {
		cout << n->ch;
		n = n->next;
	}
}