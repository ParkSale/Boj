#include <bits/stdc++.h>
using namespace std;
int N, M, pa[16][30005], depth[30005], brr[30005];
vector<int> vt[30005];
void go(int n) {
	for (int nn : vt[n]) {
		if (depth[nn] == -1) {
			depth[nn] = depth[n] + 1;
			pa[0][nn] = n;
			go(nn);
		}
	}
}
int get(int a, int b) {
	int ret = 0;
	if (depth[a] > depth[b]) {
		for (int i = 15; i >= 0; --i) {
			if (a != b && depth[b] <= depth[pa[i][a]]) {
				ret += depth[a] - depth[pa[i][a]];
				a = pa[i][a];
			}
		}
	}
	else if (depth[b] > depth[a]) {
		for (int i = 15; i >= 0; --i) {
			if (a != b && depth[a] <= depth[pa[i][b]]) {
				ret += depth[b] - depth[pa[i][b]];
				b = pa[i][b];
			}
		}
	}
	for (int i = 15; i >= 0; --i) {
		if (a != b && pa[i][a] != pa[i][b]) {
			ret += depth[a] - depth[pa[i][a]];
			ret += depth[b] - depth[pa[i][b]];
			a = pa[i][a];
			b = pa[i][b];
		}
	}
	if (a != b) {
		return ret + 2;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) depth[i] = -1;
	for (int i = 1, a, b; i < N; ++i) {
		cin >> a >> b;
		vt[a].push_back(b);
		vt[b].push_back(a);
	}
	pa[0][1] = 1;
	depth[1] = 0;
	go(1);
	for (int i = 1; i < 16; ++i) {
		for (int j = 1; j <= N; ++j) {
			pa[i][j] = pa[i - 1][pa[i - 1][j]];
		}
	}
	cin >> M;
	for (int i = 1; i <= M; ++i) {
		cin >> brr[i];
	}
	long long ans = 0;
	for (int i = 2; i <= M; ++i) {
		ans += get(brr[i - 1], brr[i]);
	}
	cout << ans;
}