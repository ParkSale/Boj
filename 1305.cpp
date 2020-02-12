#include <bits/stdc++.h>
using namespace std;
const int mod = 1000007;
int N, f[1000005];
string S;
void getF() {
	int idx = 0;
	f[1] = 0;
	for (int i = 1; i < N; ++i) {
		while (idx > 0 && S[i] != S[idx]) {
			idx = f[idx - 1];
		}
		if (S[i] == S[idx]) {
			f[i] = ++idx;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> S;
	getF();
	cout << N - f[N - 1];
}