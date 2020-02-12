#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct info {
	ll x, y, d, idx;
	bool operator <(const info& a) const {
		return d < a.d;
	}
}I[200005];
struct info2 {
	ll n, d;
};
ll N, M, pa[200005], ans[200005], dp[20][200005], val[20][200005], depth[200005];
vector<pair<ll, ll>> vt[200005];
vector<info2> tr[200005];
bool chk[200005];

int find(int n) {
	if (pa[n] == n) return n;
	return pa[n] = find(pa[n]);
}

void hap(int a, int b) {
	pa[find(a)] = find(b);
}

void go(int n) {
	for (info2 p : tr[n]) {
		if (depth[p.n] == -1) {
			dp[0][p.n] = n;
			val[0][p.n] = p.d;
			depth[p.n] = depth[n] + 1;
			go(p.n);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		pa[i] = i;
		depth[i] = -1;
	}
	for (int i = 1, a, b, c; i <= M; ++i) {
		cin >> a >> b >> c;
		vt[a].push_back({ b,c });
		vt[b].push_back({ a,c });
		I[i] = { a,b,c,i };
	}
	sort(I + 1, I + M + 1);
	ll cnt = 0, value = 0;
	for (int i = 1; i <= M; ++i) {
		if (find(I[i].x) != find(I[i].y)) {
			hap(I[i].x, I[i].y);
			tr[I[i].x].push_back({ I[i].y,I[i].d });
			tr[I[i].y].push_back({ I[i].x,I[i].d });
			value += I[i].d;
			chk[I[i].idx] = 1;
			++cnt;
		}
		if (cnt == N - 1) break;
	}
	depth[1] = 0;
	dp[0][1] = 1;
	val[0][1] = 0;
	go(1);
	for (int i = 1; i <= 18; ++i) {
		for (int j = 1; j <= N; ++j) {
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
			val[i][j] = max(val[i - 1][j], val[i - 1][dp[i - 1][j]]);
		}
	}
	for (int i = 1; i <= M; ++i) {
		if (chk[I[i].idx]) {
			ans[I[i].idx] = value;
		}
		else {
			ll a = I[i].x, b = I[i].y, maxV = 0;
			if (depth[a] > depth[b]) {
				for (int i = 18; i >= 0; --i) {
					if (a != b && depth[b] <= depth[dp[i][a]]) {
						maxV = max(maxV, val[i][a]);
						a = dp[i][a];
					}
				}
			}
			else if (depth[b] > depth[a]) {
				for (int i = 18; i >= 0; --i) {
					if (a != b && depth[a] <= depth[dp[i][b]]) {
						maxV = max(maxV, val[i][b]);
						b = dp[i][b];
					}
				}
			}
			for (int i = 18; i >= 0; --i) {
				if (a != b && dp[i][a] != dp[i][b]) {
					maxV = max({ maxV,val[i][a],val[i][b] });
					a = dp[i][a];
					b = dp[i][b];
				}
			}
			if (a != b) {
				maxV = max({ maxV,val[0][a],val[0][b] });
			}
			ans[I[i].idx] = value - maxV + I[i].d;
		}
	}
	for (int i = 1; i <= M; ++i) {
		cout << ans[i] << "\n";
	}
}