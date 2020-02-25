#include <bits/stdc++.h>
using namespace std;
int N, f[1000005], cnt;
char p[1000005], s[2000005];
int gcd(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
void getF() {
	int j = 0;
	for (int i = 1; i < N; ++i) {
		while (j > 0 && p[i] != p[j]) {
			j = f[j - 1];
		}
		if (p[i] == p[j]) {
			f[i] = ++j;
		}
	}
}
void getAns() {
	int j = 0;
	for (int i = 0; i < 2 * N - 1; ++i) {
		while (j > 0 && s[i] != p[j]) {
			j = f[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == N - 1) {
				++cnt;
				j = f[j];
			}
			else ++j;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> p[i];
	for (int i = 0; i < N; ++i) cin >> s[i];
	for (int i = N; i < 2 * N - 1; ++i) {
		s[i] = s[i - N];
	}
	getF();
	getAns();
	int v = gcd(cnt, N);
	cout << cnt / v << "/" << N / v;
}