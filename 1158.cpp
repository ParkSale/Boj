#include <iostream>
using namespace std;
struct Node {
	int num;
	Node* prev;
	Node* next;
}nodes[600005];
int nodeCnt;

Node* now;

struct List {
	int s;
	Node head, tail;

	void init() {
		head.next = &tail; tail.prev = &head;
		head.prev = &tail; tail.next = &head;
		s = 0;
	}

	void insert(int num) {
		Node* newNode = &nodes[nodeCnt++];
		newNode->num = num;
		newNode->next = &tail; newNode->prev = tail.prev;
		newNode->next->prev = newNode; newNode->prev->next = newNode;
		s++;
	}

}list;
int N, M;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	list.init();
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		list.insert(i);
	}
	now = list.head.next;
	cout << "<";
	while (list.s != 1) {
		int t = M - 1;
		while (t--) {
			if (now == &list.tail) now = list.head.next;
			now = now->next;
		}
		if (now == &list.tail) now = list.head.next;
		cout << now->num << ", ";
		now->prev->next = now->next; now->next->prev = now->prev;
		now = now->next;
		list.s--;
	}
	cout << list.head.next->num << ">";
}