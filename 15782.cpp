#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M, seg[100005 * 4], lazy[100005 * 4], l[100005], r[100005], num, arr[100005], cnt[100005];
vector<int> vt[100005];
void dfs(int n) {
	l[n] = ++num;
	cnt[num] = n;
	for (int nn : vt[n]) {
		if (l[nn] == 0) {
			dfs(nn);
		}
	}
	r[n] = num;
}

int init(int ll, int rr, int n) {
	if (ll == rr) return seg[n] = arr[cnt[ll]];
	int mid = (ll + rr) / 2;
	return seg[n] = (init(ll, mid, n * 2) ^ init(mid + 1, rr, n * 2 + 1));
}

void lazy_update(int l, int r, int n) {
	if (lazy[n] != 0) {
		seg[n] ^= (((r - l + 1) % 2) * lazy[n]);
		if (l != r) {
			lazy[n * 2] ^= lazy[n];
			lazy[n * 2 + 1] ^= lazy[n];
		}
		lazy[n] = 0;
	}
}

void update(int l, int r, int s, int e, int n, int k) {
	lazy_update(l, r, n);
	if (l > e || r < s) return;
	if (s <= l && r <= e) {
		seg[n] ^= (((r - l + 1) % 2) * k);
		if (l != r) {
			lazy[n * 2] ^= k;
			lazy[n * 2 + 1] ^= k;
		}
		return;
	}
	int mid = (l + r) / 2;
	update(l, mid, s, e, n * 2, k); update(mid + 1, r, s, e, n * 2 + 1, k);
	seg[n] = (seg[n * 2] ^ seg[n * 2 + 1]);
}

int get(int l, int r, int s, int e, int n) {
	lazy_update(l, r, n);
	if (l > e || r < s) return 0;
	if (s <= l && r <= e) return seg[n];
	int mid = (l + r) / 2;
	return (get(l, mid, s, e, n * 2) ^ get(mid + 1, r, s, e, n * 2 + 1));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1, a, b; i < N; i++) {
		cin >> a >> b;
		vt[a].push_back(b);
		vt[b].push_back(a);
	}
	dfs(1);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	init(1, N, 1);
	while (M--) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b;
			cout << get(1, N, l[b], r[b], 1) << "\n";
		}
		else {
			cin >> b >> c;
			update(1, N, l[b], r[b], 1, c);
		}
	}
}