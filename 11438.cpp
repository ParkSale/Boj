#include <bits/stdc++.h>
using namespace std;
int N, M, depth[100005], pa[18][100005];
vector<int> vt[100005];
void go(int n) {
	for (int nn : vt[n]) {
		if (nn != 1 && depth[nn] == 0) {
			depth[nn] = depth[n] + 1;
			pa[0][nn] = n;
			go(nn);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1, a, b; i < N; ++i) {
		cin >> a >> b;
		vt[a].push_back(b);
		vt[b].push_back(a);
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
		int a, b;
		cin >> a >> b;
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
		if (a == b) cout << a << "\n";
		else cout << pa[0][a] << "\n";
	}
}