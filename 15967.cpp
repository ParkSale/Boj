#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, Q1, Q2, arr[1000005];
ll seg[1000005 * 4], lazy[1000005 * 4];
ll init(int l, int r, int n) {
	if (l == r) return seg[n] = arr[l];
	int mid = (l + r) / 2;
	return seg[n] = init(l, mid, n * 2) + init(mid + 1, r, n * 2 + 1);
}

void lazy_update(int l, int r, int n) {
	if (lazy[n] != 0) {
		seg[n] += (r - l + 1) * lazy[n];
		if (l != r) {
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

void update(int l, int r, int s, int e, int n, int k) {
	lazy_update(l, r, n);
	if (l > e || r < s) return;
	if (s <= l && r <= e) {
		seg[n] += (r - l + 1) * k;
		if (l != r) {
			lazy[n * 2] += k;
			lazy[n * 2 + 1] += k;
		}
		return;
	}
	int mid = (l + r) / 2;
	update(l, mid, s, e, n * 2, k); update(mid + 1, r, s, e, n * 2 + 1, k);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

ll get(int l, int r, int s, int e, int n) {
	lazy_update(l, r, n);
	if (l > e || r < s) return 0;
	if (s <= l && r <= e) {
		return seg[n];
	}
	int mid = (l + r) / 2;
	return get(l, mid, s, e, n * 2) + get(mid + 1, r, s, e, n * 2 + 1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> Q1 >> Q2;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	init(1, N, 1);
	for (int i = 1; i <= Q1 + Q2; i++) {
		int a, b, c, d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			cout << get(1, N, b, c, 1) << "\n";
		}
		else {
			cin >> b >> c >> d;
			update(1, N, b, c, 1, d);
		}
	}
}