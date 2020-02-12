#include <iostream>
using namespace std;
const int mod = 4096;
int getHash(char* str) {
	int idx = 0, ret = 5381;
	while (str[idx] != 0) {
		ret = (ret << 5) + ret + str[idx];
		++idx;
		ret %= mod;
	}
	return ret;
}

void _strcpy(char* a, char* b) {
	int idx = 0;
	while (b[idx] != 0) {
		a[idx] = b[idx];
		++idx;
	}
	a[idx] = 0;
}

bool _strcmp(char* a, char* b) {
	int idx = 0;
	while (a[idx] != 0 && b[idx] != 0) {
		if (a[idx] != b[idx]) return 0;
		++idx;
	}
	if (a[idx] != b[idx]) return 0;
	return 1;
}
struct Node {
	char str[505];
	Node* prev;
	Node* next;
}nodes[10005];

int nodeCnt;

Node* getNodes(char* str) {
	Node* ret = &nodes[nodeCnt++];
	_strcpy(ret->str, str);
	return ret;
}
struct List {
	Node head, tail;

	void init() {
		head.next = &tail; tail.prev = &head;
		head.prev = nullptr; tail.next = nullptr;
	}

	void insert(char* str) {
		Node* newNode = getNodes(str);
		newNode->prev = &head; newNode->next = head.next;
		newNode->prev->next = newNode; newNode->next->prev = newNode;
	}

	bool find(char* str) {
		Node* now = head.next;
		while (now != &tail) {
			if (_strcmp(now->str, str)) {
				return 1;
			}
			now = now->next;
		}
		return 0;
	}
}table[mod];
int N, M;
char ch[505];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < mod; i++) table[i].init();
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> ch;
		table[getHash(ch)].insert(ch);
	}
	int cnt = 0;
	for (int i = 1; i <= M; i++) {
		cin >> ch;
		if (table[getHash(ch)].find(ch)) {
			cnt++;
		}
	}
	cout << cnt;
}