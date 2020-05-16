#include <bits/stdc++.h>
using namespace std;
int N, M, K, graph[105][105], tmp[105][105], ttmp[105][105], n, m;
void rotate() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			ttmp[j][i] = tmp[n - i + 1][j];
		}
	}
	swap(n, m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			tmp[i][j] = ttmp[i][j];
		}
	}
}
bool func(int a, int b) {
	if (a + n > N + 1) return 0;
	if (b + m > M + 1) return 0;
	for (int i = a; i < a + n; ++i) {
		for (int j = b; j < b + m; ++j) {
			if (graph[i][j] == 1 && tmp[i - a + 1][j - b + 1] == 1) {
				return 0;
			}
		}
	}
	for (int i = a; i < a + n; ++i) {
		for (int j = b; j < b + m; ++j) {
			if (tmp[i - a + 1][j - b + 1] == 1) graph[i][j] = 1;
		}
	}
	return 1;
}
bool chk() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (func(i, j)) {
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= K; ++i) {
		cin >> n >> m;
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= m; ++k) {
				cin >> tmp[j][k];
			}
		}
		int v = 0;
		while (chk() == 0) {
			rotate();
			++v;
			if (v == 4) break;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (graph[i][j]) ++cnt;
		}
	}
	cout << cnt;
}