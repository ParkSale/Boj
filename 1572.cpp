#include <bits/stdc++.h>
using namespace std;
int N, K, arr[250005], seg[65536 * 4], s = 1;
void update(int n, int k) {
	while (n != 0) {
		seg[n] += k;
		n /= 2;
	}
}
int get() {
	int n = 1, cnt = 0;
	while (n * 2 < s * 2) {
		if (seg[n * 2] >= ((K + 1) / 2) - cnt) {
			n = n * 2;
		}
		else {
			cnt += seg[n * 2];
			n = n * 2 + 1;
		}
	}
	return n - s;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	while (s <= 65535)s *= 2;
	for (int i = 1; i <= K; i++) {
		update(s + arr[i], 1);
	}
	long long ans = 0;
	for (int i = K + 1; i <= N; i++) {
		ans += get();
		update(s + arr[i], 1);
		update(s + arr[i - K], -1);
	}
	cout << ans + get();
}