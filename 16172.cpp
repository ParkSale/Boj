#include <bits/stdc++.h>
using namespace std;
string S, P;
int f[1000005], ff[1000005];
void getFailureFunc() {
	f[1] = 0;
	int idx = 0;
	for (int i = 1; i < P.length(); ++i) {
		while (idx > 0 && P[i] != P[idx]) {
			idx = f[idx - 1];
		}
		if (P[i] == P[idx]) {
			f[i] = ++idx;
		}
	}
}
void getAns() {
	int idx = 0;
	for (int i = 0; i < S.length(); ++i) {
		while (idx > 0 && S[i] != P[idx]) {
			idx = f[idx - 1];
		}
		if (S[i] == P[idx]) {
			if (idx == P.length() - 1) {
				cout << 1;
				exit(0);
			}
			else ++idx;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string T;
	cin >> T >> P;
	for (int i = 0; i < T.length(); ++i) {
		if (!(T[i] >= '0' && T[i] <= '9')) {
			S.push_back(T[i]);
		}
	}
	getFailureFunc();
	getAns();
	cout << 0;
}