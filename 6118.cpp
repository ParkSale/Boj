#include <bits/stdc++.h>
using namespace std;
struct info {
	int n, d;
};
int N, M, dist[20005];
vector<int> vt[20005];
queue<info> q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1, a, b; i <= M; ++i) {
		cin >> a >> b;
		vt[a].push_back(b);
		vt[b].push_back(a);
	}
	for (int i = 1; i <= N; ++i) dist[i] = 1e9;
	dist[1] = 0;
	q.push({ 1,0 });
	while (!q.empty()) {
		info p = q.front(); q.pop();
		for (int nn : vt[p.n]) {
			if (dist[nn] > dist[p.n] + 1) {
				dist[nn] = dist[p.n] + 1;
				q.push({ nn,dist[nn] });
			}
		}
	}
	int maxV = 0;
	for (int i = 1; i <= N; ++i) {
		maxV = max(maxV, dist[i]);
	}
	int cnt = 0, ans = 1e9;
	for (int i = 1; i <= N; ++i) {
		if (dist[i] == maxV) {
			ans = min(ans, i);
			++cnt;
		}
	}
	cout << ans << " " << maxV << " " << cnt;
}