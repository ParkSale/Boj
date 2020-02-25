#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, arr[100005], seg[100005 * 4], ans[100005];
pii brr[100005];
void update(int n) {
	while (n != 0) {
		seg[n]++;
		n /= 2;
	}
}
int get(int s, int e) {
	int ret = 0;
	while (s <= e) {
		if (s % 2 == 1) ret += seg[s++];
		if (e % 2 == 0) ret += seg[e--];
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
	while (s < N) s *= 2;
	--s;
	for (int i = 1; i <= N; ++i) {
		int ss = 1, ee = N, minV = 1e9;
		while (ss <= ee) {
			int mid = (ss + ee) / 2;
			int v = mid - get(s + 1, s + mid);
			if (v > arr[i]) {
				ee = mid - 1;
				minV = min(minV, mid);
			}
			else ss = mid + 1;
		}
		update(s + minV);
		ans[minV] = i;
	}
	for (int i = 1; i <= N; ++i) cout << ans[i] << "\n";
}