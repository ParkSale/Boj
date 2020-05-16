#include <bits/stdc++.h>
using namespace std;
#define INF 2100000000
typedef pair<int, int> pii;
int TC, N, M, W, dist[505];
vector<pii> vt[505];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> TC;
	while (TC--) {
		cin >> N >> M >> W;
		for (int i = 1; i <= N; i++) {
			dist[i] = INF;
			vt[i].clear();
		}
		for (int i = 1, a, b, c; i <= M; i++) {
			cin >> a >> b >> c;
			vt[a].push_back({ b,c });
			vt[b].push_back({ a,c });
		}
		for (int i = 1, a, b, c; i <= W; i++) {
			cin >> a >> b >> c;
			vt[a].push_back({ b,-c });
		}
		bool cycle = false;
		dist[1] = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (pii p : vt[j]) {
					if (dist[p.first] > dist[j] + p.second) {
						dist[p.first] = dist[j] + p.second;
						if (i == N) cycle = true;
					}
				}
			}
		}
		if (cycle) cout << "YES\n";
		else cout << "NO\n";
	}
}