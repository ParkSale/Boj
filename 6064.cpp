#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
	int t = 1;
	while (t != 0) {
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int TC;
	cin >> TC;
	while (TC--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		int t = (M * N) / gcd(M, N);
		int k = x - 1;
		bool flag = 0;
		while (k <= t - 1) {
			if (k % N == y - 1) {
				flag = 1;
				cout << k + 1 << "\n";
				break;
			}
			k += M;
		}
		if (!flag) cout << -1 << "\n";
	}
}