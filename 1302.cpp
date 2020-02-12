#include <iostream>
using namespace std;
const int mod = 4096;
int getHash(char* str) {
	int idx = 0, ret = 5381;
	while (str[idx] != 0) {
		ret = (ret << 5) + ret + str[idx++];
		ret %= mod;
	}
	return ret;
}

int _strlen(char* a) {
	int idx = 0;
	while (a[idx] != 0) ++idx;
	return idx;
}
void _strcpy(char* a, char* b) {
	int idx = 0;
	while (b[idx] != 0) {
		a[idx] = b[idx];
		++idx;
	}
	a[idx] = 0;
}
int _strcmp(char* a, char* b) {
	int idx = 0;
	int aLen = _strlen(a), bLen = _strlen(b);
	while (a[idx] != 0 && b[idx] != 0) {
		if (a[idx] < b[idx]) return -1;
		else if (a[idx] > b[idx]) return 1;
		++idx;
	}
	if (a[idx] != 0) return 1;
	if (b[idx] != 0) return -1;
	return 0;
}
int N, nodeCnt;

struct Node {
	char str[55];
	int cnt;
	Node* prev;
	Node* next;
}nodes[1005];

Node* getNodes(char* str) {
	Node* ret = &nodes[nodeCnt++];
	ret->cnt = 1;
	_strcpy(ret->str, str);
	return ret;
}

struct List {
	Node head, tail;
	void init() {
		head.next = &tail; head.prev = nullptr;
		tail.prev = &head; tail.next = nullptr;
	}
	void insert(char* str) {
		Node* now = head.next;
		while (now != &tail) {
			if (_strcmp(now->str, str) == 0) {
				now->cnt++;
				return;
			}
			now = now->next;
		}
		Node* newNode = getNodes(str);
		newNode->next = head.next; newNode->prev = &head;
		newNode->next->prev = newNode; newNode->prev->next = newNode;
	}

}table[mod];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < mod; i++) table[i].init();
	cin >> N;
	char ch[55];
	for (int i = 1; i <= N; i++) {
		cin >> ch;
		int hash = getHash(ch);
		table[hash].insert(ch);
	}
	int maxV = 0;
	char ans[55];
	_strcpy(ans, nodes[0].str);
	maxV = nodes[0].cnt;
	for (int i = 1; i < nodeCnt; i++) {
		if (maxV == nodes[i].cnt) {
			int tmp = _strcmp(ans, nodes[i].str);
			if (tmp == 1) {
				_strcpy(ans, nodes[i].str);
			}
		}
		else if (maxV < nodes[i].cnt) {
			maxV = nodes[i].cnt;
			_strcpy(ans, nodes[i].str);
		}
	}
	cout << ans;
}