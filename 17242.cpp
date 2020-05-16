#include <bits/stdc++.h>
using namespace std;
#define pb push_back
struct info {
	int n, c, d;
	bool operator <(const info& a) const {
		return c * d < a.c * a.d;
	}
};
vector<info> vt[1005];
int N, M;
queue<info> q;
set<info> val[1005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1, a, b, c, d; i <= M; i++) {
		cin >> a >> b >> c >> d;
		a++, b++;
		vt[a].pb({ b,c,d });
		vt[b].pb({ a,c,d });
	}
	val[1].insert({ 1,0,0 });
	q.push({ 1,0,0 });
	while (!q.empty()) {
		info p = q.front(); q.pop();
		for (int i = 0; i < vt[p.n].size(); ++i) {
			bool flag = 0;
			info t = vt[p.n][i];
			if (p.c + t.c <= 1000 && p.d + t.d <= 1000) {
				for (info tt : val[t.n]) {
					if (tt.c <= t.c + p.c && tt.d <= t.d + p.d) {
						flag = 1;
						break;
					}
				}
				if (!flag) {
					val[t.n].insert({ t.n,t.c + p.c,t.d + p.d });
					q.push({ t.n,t.c + p.c,t.d + p.d });
				}
			}
		}
	}
	if (val[N].size() == 0) cout << -1;
	else cout << val[N].begin()->c * val[N].begin()->d;
}