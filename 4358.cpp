#include <iostream>
using namespace std;
const int mod = 4096;

void _strcpy(char* a, char* b) {
	int idx = 0;
	while (a[idx] != b[idx]) {
		a[idx] = b[idx];
		++idx;
	}
	a[idx] = 0;
}

int _strcmp(char* a, char* b) {
	int idx = 0;
	while (a[idx] != 0 && b[idx] != 0) {
		if (a[idx] > b[idx]) return 1;
		if (a[idx] < b[idx]) return -1;
		++idx;
	}
	if (a[idx] != 0) return 1;
	if (b[idx] != 0) return -1;
	return 0;
}

struct info {
	char str[31];
	double num;
}I[10005];

void swap(info& a, info& b) {
	info t = a;
	a = b;
	b = t;
}

void qsort(int s, int e) {
	if (s >= e) return;
	int pivot = s;
	int i = s, j = e;
	while (i < j) {
		while (_strcmp(I[pivot].str, I[j].str) == -1) --j;
		while (i < j && _strcmp(I[i].str, I[pivot].str) == -1) ++i;
		swap(I[i], I[j]);
	}
	swap(I[i], I[pivot]);
	qsort(s, i - 1);
	qsort(i + 1, e);
}
int getHash(char* str) {
	int idx = 0, ret = 5381;
	while (str[idx] != 0) {
		ret = (ret << 5) + ret + str[idx];
		ret %= mod;
		++idx;
	}
	return ret;
}

struct Node {
	char str[31];
	int cnt;
	Node* prev;
	Node* next;
}nodes[10005];

int nodeCnt;

Node* getNodes(char* str) {
	Node* ret = &nodes[nodeCnt++];
	_strcpy(ret->str, str);
	ret->cnt = 1;
	return ret;
}
struct List {
	Node head, tail;

	void init() {
		head.next = &tail; tail.prev = &head;
		head.prev = nullptr; tail.next = nullptr;
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
	char ch[31];
	int total = 0;
	while (cin.getline(ch, 31, '\n')) {
		total++;
		int hash = getHash(ch);
		table[hash].insert(ch);
	}
	cout << fixed;
	cout.precision(4);
	cout.setf(ios::showpoint);
	for (int i = 0; i < nodeCnt; i++) {
		_strcpy(I[i].str, nodes[i].str);
		I[i].num = (double)(nodes[i].cnt * 100) / total;
	}
	qsort(0, nodeCnt - 1);
	for (int i = 0; i < nodeCnt; i++) {
		cout << I[i].str << " " << I[i].num << "\n";
	}
}