#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define xx first
#define yy second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
pii dir[] = { {1,1},{0,1},{-1,1}, {1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} };
ll N, M, K, arr[1000005], seg[1000005];
void update(int n, ll val) {
	while (n <= N) {
		seg[n] += val;
		n += (n & -n);
	}
}
ll get(int n) {
	ll ret = 0;
	while (n > 0) {
		ret += seg[n];
		n -= (n & -n);
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		update(i, arr[i]);
	}
	for (int i = 1, a, b, c; i <= M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			ll v = c - arr[b];
			arr[b] = c;
			update(b, v);
		}
		else {
			cout << get(c) - get(b - 1) << "\n";
		}
	}
}