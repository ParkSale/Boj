#include <iostream>
using namespace std;
const int mod = 4096;
char arr[1005][15];
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
void qsort(int s, int e) {
	if (s >= e) return;
	int pivot = s, i = s, j = e;
	while (i < j) {
		while (_strcmp(arr[pivot], arr[j]) == -1) --j;
		while (i < j && _strcmp(arr[pivot], arr[i]) == 1) ++i;
		swap(arr[i], arr[j]);
	}
	swap(arr[i], arr[pivot]);
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
	char str[16];
	Node* prev;
	Node* next;
	Node* up;
	Node* down;
}nodes[10005];
Node dummy;
int nodeCnt;

Node* getNodes(char* str) {
	Node* ret = &nodes[nodeCnt++];
	_strcpy(ret->str, str);
	ret->up = &dummy; ret->down = &dummy;
	ret->prev = &dummy; ret->next = &dummy;
	return ret;
}

struct List {
	Node head, tail;

	void init() {
		head.next = &tail; tail.prev = &head;
		head.prev = nullptr; tail.next = nullptr;
	}

	Node* insert(char* str) {
		Node* now = head.next;
		while (now != &tail) {
			if (_strcmp(now->str, str) == 0) {
				return now;
			}
			now = now->next;
		}
		Node* newNode = getNodes(str);
		newNode->next = &tail; newNode->prev = tail.prev;
		newNode->next->prev = newNode; newNode->prev->next = newNode;
		return newNode;
	}
}table[mod];

char parentNumber[1005], parentIdx;

void dfs(Node* now, int k) {
	while (now != &dummy) {
		for (int i = 0; i < k; i++) cout << "--";
		cout << now->str << "\n";
		if (now->down != &dummy) {
			dfs(now->down, k + 1);
		}
		now = now->next;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	dummy.next = nullptr; dummy.prev = nullptr; dummy.up = nullptr; dummy.down = nullptr;
	for (int i = 0; i < mod; i++) table[i].init();
	char ch[15], parent[15];
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		int step = 1;
		Node* now = nullptr;
		while (n--) {
			cin >> ch;
			if (step == 1) {
				int v = nodeCnt;
				int idx = 0;
				while (ch[idx] != 0) {
					parent[idx] = ch[idx];
					++idx;
				}
				parent[idx] = 0;
				now = table[getHash(parent)].insert(ch);
				if (v != nodeCnt) {
					for (int k = 0; k <= idx; k++) {
						arr[parentIdx][k] = parent[k];
					}
					++parentIdx;
				}
				++step;
			}
			else {
				Node* newNode = getNodes(ch);
				if (now->down == &dummy) {
					now->down = newNode;
					newNode->up = now;
					now = newNode;
				}
				else {
					now = now->down;
					Node* head = now->up;
					bool flag = 0;
					while (now->next != &dummy) {
						int v = _strcmp(now->str, newNode->str);
						if (v == 0) {
							flag = 1;
							break;
						}
						if (v == 1) {
							newNode->next = now; newNode->prev = now->prev;
							newNode->next->prev = newNode; newNode->prev->next = newNode;
							if (newNode->prev == &dummy) {
								newNode->up = head;
								newNode->up->down = newNode;
							}
							now = newNode;
							flag = 1;
							break;
						}
						now = now->next;
					}
					if (flag) continue;
					int v = _strcmp(now->str, newNode->str);
					if (v == 0) continue;
					else if (v == 1) {
						newNode->next = now; newNode->prev = now->prev;
						newNode->next->prev = newNode; newNode->prev->next = newNode;
						if (newNode->prev == &dummy) {
							newNode->up = head;
							newNode->up->down = newNode;
						}
						now = newNode;
					}
					else {
						newNode->prev = now; newNode->next = now->next;
						newNode->next->prev = newNode; newNode->prev->next = newNode;
						now = newNode;
					}
				}
			}
		}
	}
	qsort(0, parentIdx - 1);
	for (int i = 0; i < parentIdx; i++) {
		int hash = getHash(arr[i]);
		Node* now = table[hash].head.next;
		while (now != &table[hash].tail) {
			if (_strcmp(now->str, arr[i]) == 0) {
				cout << now->str << "\n";
				if (now->down != &dummy) dfs(now->down, 1);
				break;
			}
			now = now->next;
		}
	}
}