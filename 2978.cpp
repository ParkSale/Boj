#include <bits/stdc++.h>
using namespace std;
const int mod = 10007;
int TC;
int N, M, K;
struct Node {
	string s;
	Node* next;
}nodes[10005];

int nodeCnt;
Node* getNodes(string s) {
	Node* ret = &nodes[nodeCnt++];
	ret->s = s;
	return ret;
}
struct List {
	Node head, tail;
	void init() {
		head.next = &tail;
	}
	void insert(string s) {
		Node* now = head.next;
		while (now != &tail) {
			if (now->s == s) {
				return;
			}
			now = now->next;
		}
		Node* newNode = getNodes(s);
		newNode->next = head.next;
		head.next = newNode;
	}

	bool find(string s) {
		Node* now = head.next;
		while (now != &tail) {
			if (now->s == s) {
				return 1;
			}
			now = now->next;
		}
		return 0;
	}
}table[mod];

string tmp;
bool flag = 0;
void init() {
	tmp = ""; flag = 0;
	nodeCnt = 0;
	for (int i = 0; i < mod; i++) {
		table[i].init();
	}
}

int getHash(string s) {
	int ret = 0, v = 1;
	for (int i = s.length() - 1; i >= 0; i--) {
		ret += (s[i] - 'a' + 1) * v;
		ret %= mod;
		v *= 31;
		v %= mod;
	}
	return ret;
}

void go(int n) {
	if (n == M) {
		int value = getHash(tmp);
		if (table[value].find(tmp) == 0) {
			flag = 1;
			return;
		}
		return;
	}
	for (int i = 0; i < K; i++) {
		if (flag) return;
		tmp.push_back('a' + i);
		go(n + 1);
		if (flag) return;
		tmp.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> TC;
	while (TC--) {
		cin >> N >> M >> K;
		string S;
		cin >> S;
		init();
		if (N < M) {
			tmp = "";
			for (int i = 0; i < M; i++) {
				tmp.push_back('a');
			}
			cout << tmp << "\n";
			continue;
		}
		int v = 1;
		for (int i = 1; i < M; i++) {
			v *= 31;
			v %= mod;
		}
		int value = getHash(S.substr(0, M));
		table[value].insert(S.substr(0, M));
		for (int i = 1; i < S.length() - M + 1; i++) {
			value -= ((S[i - 1] - 'a' + 1) * v) % mod;
			if (value < 0) value += mod;
			value %= mod;
			value *= 31;
			value %= mod;
			value += S[i + M - 1] - 'a' + 1;
			value %= mod;
			table[value].insert(S.substr(i, M));
		}
		tmp = "";
		go(0);
		cout << tmp << "\n";
	}
}