#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct info {
	int a, b, c, idx;
	bool operator < (const info& aa)const {
		return a < aa.a;
	}
}Query1[100005], Query2[100005];
int N, arr[200005], Q;
ll seg[100005 * 4], ans[100005];
void update(int n, ll k) {
	while (n != 0) {
		seg[n] += k;
		n /= 2;
	}
}
ll get(int s, int e) {
	ll ret = 0;
	while (s <= e) {
		if (s % 2 == 1) {
			ret += seg[s++];
		}
		if (e % 2 == 0) {
			ret += seg[e--];
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
		seg[i] = arr[i - s];
	}
	for (int i = s; i >= 1; --i) {
		seg[i] = (seg[i * 2] + seg[i * 2 + 1]);
	}
	cin >> Q;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= Q; ++i) {
		int a, b, c, d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			Query1[++cnt1] = { b,c };
		}
		else {
			cin >> b >> c >> d;
			Query2[cnt2] = { b,c,d,++cnt2 };
		}
	}
	sort(Query2 + 1, Query2 + cnt2 + 1);
	int t = 0, idx = 1;
	for (int i = 1; i <= cnt2; ++i) {
		while (t < cnt1 && t < Query2[i].a) {
			++t;
			ll k = Query1[t].b - seg[s + Query1[t].a];
			update(s + Query1[t].a, k);
		}
		ans[Query2[i].idx] = get(s + Query2[i].b, s + Query2[i].c);
	}
	for (int i = 1; i <= cnt2; ++i) {
		cout << ans[i] << "\n";
	}
}