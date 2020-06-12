#include <bits/stdc++.h>
using namespace std;
int N, arr[100005], seg[100005 * 4][2], K;
void update(int n, int k) {
	while (n != 0) {
		seg[n][k] = seg[n * 2][k] + seg[n * 2 + 1][k];
		n /= 2;
	}
}
int get(int s, int e, int k) {
	int ret = 0;
	while (s <= e) {
		if (s % 2 == 1) {
			ret += seg[s++][k];
		}
		if (e % 2 == 0) {
			ret += seg[e--][k];
		}
		s /= 2; e /= 2;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> arr[i];
	int s = 1;
	while (s <= N) s *= 2;
	--s;
	for (int i = s + 1; i <= s + N; ++i) {
		seg[i][arr[i - s] % 2]++;
	}
	for (int i = s; i >= 1; --i) {
		seg[i][0] = seg[i * 2][0] + seg[i * 2 + 1][0];
		seg[i][1] = seg[i * 2][1] + seg[i * 2 + 1][1];
	}
	cin >> K;
	while (K--) {
		int n, a, b;
		cin >> n >> a >> b;
		if (n == 1) {
			if (arr[a] % 2 != b % 2 == 1) {
				seg[s + a][arr[a] % 2]--;
				update((s + a) / 2, arr[a] % 2);
				seg[s + a][b % 2]++;
				update((s + a) / 2, b % 2);
			}
			arr[a] = b;
		}
		else if (n == 2) {
			cout << get(s + a, s + b, 0) << "\n";
		}
		else {
			cout << get(s + a, s + b, 1) << "\n";

		}
	}
}