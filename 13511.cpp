#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int N, M, depth[100005], pa[18][100005];
ll dist[100005];
vector<pii> vt[100005];
void go(int n) {
	for (pii p : vt[n]) {
		int nn = p.first;
		if (nn != 1 && depth[nn] == 0) {
			depth[nn] = depth[n] + 1;
			dist[nn] = dist[n] + p.second;
			pa[0][nn] = n;
			go(nn);
		}
	}
}
int LCA(int a, int b) {
	if (depth[a] > depth[b]) {
		for (int i = 17; i >= 0; --i) {
			if (a != b && depth[pa[i][a]] >= depth[b]) a = pa[i][a];
		}
	}
	else if (depth[a] < depth[b]) {
		for (int i = 17; i >= 0; --i) {
			if (a != b && depth[pa[i][b]] >= depth[a]) b = pa[i][b];
		}
	}
	for (int i = 17; i >= 0; --i) {
		if (a != b && pa[i][a] != pa[i][b]) {
			a = pa[i][a];
			b = pa[i][b];
		}
	}
	if (a == b) return a;
	return pa[0][a];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1, a, b, c; i < N; ++i) {
		cin >> a >> b >> c;
		vt[a].push_back({ b,c });
		vt[b].push_back({ a,c });
	}
	depth[1] = 0;
	pa[0][1] = 1;
	go(1);
	for (int i = 1; i <= 17; ++i) {
		for (int j = 1; j <= N; ++j) {
			pa[i][j] = pa[i - 1][pa[i - 1][j]];
		}
	}
	cin >> M;
	while (M--) {
		int a, b, c, d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			int p = LCA(b, c);
			cout << dist[b] + dist[c] - 2 * dist[p] << "\n";;
		}
		else {
			cin >> b >> c >> d;
			int p = LCA(b, c);
			int cnt = 0;
			if (d > depth[b] - depth[p] + 1) {
				d -= depth[b] - depth[p] + 1;
				d = (depth[c] - depth[p]) - d;
				while (d != 0) {
					if (d % 2 == 1) {
						c = pa[cnt][c];
					}
					d /= 2;
					++cnt;
				}
				cout << c << "\n";
			}
			else {
				--d;
				while (d != 0) {
					if (d % 2 == 1) {
						b = pa[cnt][b];
					}
					d /= 2;
					++cnt;
				}
				cout << b << "\n";
			}
		}
	}
}