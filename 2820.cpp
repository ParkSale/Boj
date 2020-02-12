#include <bits/stdc++.h>
using namespace std;
#define Blue 0
#define Red 1
typedef long long ll;
typedef pair<int, int> pii;
int N, M, arr[500005], l[500005], r[500005], num[500005], cnt;
ll seg[500005 * 4], lazy[500005 * 4];
vector<int> vt[500005];
void go(int n) {
	l[n] = ++cnt;
	num[cnt] = n;
	for (int nn : vt[n]) {
		if (l[nn] == 0) go(nn);
	}
	r[n] = cnt;
}

ll init(int ll, int rr, int n) {
	if (ll == rr) return seg[n] = arr[num[ll]];
	int mid = (ll + rr) / 2;
	return seg[n] = init(ll, mid, n * 2) + init(mid + 1, rr, n * 2 + 1);
}

void lazy_update(int l, int r, int n) {
	if (lazy[n] != 0) {
		seg[n] += (ll)(r - l + 1) * lazy[n];
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
		seg[n] += (ll)(r - l + 1) * k;
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
	return seg[n] = (get(l, mid, s, e, n * 2) + get(mid + 1, r, s, e, n * 2 + 1));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	cin >> arr[1];
	for (int i = 2, a, b; i <= N; i++) {
		cin >> a >> b;
		vt[b].push_back(i);
		arr[i] = a;
	}
	go(1);
	init(1, N, 1);
	while (M--) {
		char ch;
		int a, b;
		cin >> ch;
		if (ch == 'p') {
			cin >> a >> b;
			//if (l[a] == r[a]) continue;
			update(1, N, l[a] + 1, r[a], 1, b);
		}
		else {
			cin >> a;
			cout << get(1, N, l[a], l[a], 1) << "\n";
		}
	}
}