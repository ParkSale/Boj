#include <bits/stdc++.h>
using namespace std;
int trie[10005 * 10][10], N, M, pos;
bool fin[10005 * 10], ans;
string S, tmp;
void init() {
	for (int i = 0; i < 10005 * 10; ++i) {
		fin[i] = 0;
		for (int j = 0; j < 10; ++j) {
			trie[i][j] = 0;
		}
	}
	pos = 0;
	ans = 0;
}
void add(int root, int state) {
	if (S[state] == 0) {
		fin[root] = 1;
		return;
	}
	if (trie[root][S[state] - '0'] == 0) {
		trie[root][S[state] - '0'] = ++pos;
	}
	int n = trie[root][S[state] - '0'];
	add(n, state + 1);
}
void chk(int root) {
	for (int i = 0; i < 10; ++i) {
		if (trie[root][i] != 0) {
			if (fin[root] == 1) {
				ans = 1;
				return;
			}
			chk(trie[root][i]);
			if (ans) return;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int TC;
	cin >> TC;
	while (TC--) {
		cin >> N;
		init();
		for (int i = 1; i <= N; ++i) {
			cin >> S;
			add(0, 0);
		}
		chk(0);
		if (ans) cout << "NO\n";
		else cout << "YES\n";
	}
}