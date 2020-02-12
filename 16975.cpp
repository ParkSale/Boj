#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, arr[100005], M, seg[100005 * 4], lazy[100005 * 4];
ll init(int l, int r, int n) {
	if (l == r) return seg[n] = arr[l];
	return seg[n] = init(l, (l + r) / 2, n * 2) + init((l + r) / 2 + 1, r, n * 2 + 1);
}
void lazy_update(int l, int r, int n) {
	if (lazy[n] != 0) {
		seg[n] += lazy[n] * (r - l + 1);
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
		seg[n] += k * (l - r + 1);
		if (l != r) {
			lazy[n * 2] += k;
			lazy[n * 2 + 1] += k;
		}
		return;
	}
	int mid = (l + r) / 2;
	update(l, mid, s, e, n * 2, k);
	update(mid + 1, r, s, e, n * 2 + 1, k);
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
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	init(1, N, 1);
	cin >> M;
	while (M--) {
		int a, b, c, d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			update(1, N, b, c, 1, d);
		}
		else {
			cin >> b;
			cout << get(1, N, b, b, 1) << "\n";
		}
	}
}