#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll N, M, K, dist[100005];
vector<pll> vt[100005];
vector<int> vtt;
struct info {
	ll n, d;
	bool operator < (const info& a) const {
		return d > a.d;
	}
};
priority_queue<info> pq;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 1, a, b, c; i <= M; i++) {
		cin >> a >> b >> c;
		vt[b].push_back({ a,c });
	}
	for (int i = 1; i <= N; i++) dist[i] = 1e18;
	for (int i = 1, a; i <= K; i++) {
		cin >> a;
		vtt.push_back(a);
		dist[a] = 0;
		pq.push({ a,0 });
	}
	while (!pq.empty()) {
		info p = pq.top(); pq.pop();
		if (p.d != dist[p.n]) continue;
		ll n = p.n;
		for (pll pp : vt[n]) {
			ll nn = pp.first, dd = pp.second;
			if (dist[nn] > dist[n] + dd) {
				dist[nn] = dist[n] + dd;
				pq.push({ nn,dist[nn] });
			}
		}
	}
	ll maxV = -1, ans = 0;
	for (int i = 1; i <= N; i++) {
		if (maxV < dist[i]) {
			maxV = dist[i];
			ans = i;
		}
	}
	cout << ans << "\n" << maxV;
}
