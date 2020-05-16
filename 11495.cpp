#include <bits/stdc++.h>
using namespace std;
int TC, N, M, tmp[55][55], graph[2505][2505], numbering[55][55], S, T, minV, pre[2505];
bool visit[2505];
vector<int> vt[2505];
queue<int> q;
void init() {
	int cnt = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> tmp[i][j];
			numbering[i][j] = ++cnt;
		}
	}
	for (int i = 0; i <= cnt + 1; ++i) {
		for (int j = 0; j <= cnt + 1; ++j) {
			graph[i][j] = 0;
		}
		vt[i].clear();
		pre[i] = 0;
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (i % 2 == j % 2) {
				if (i != 1) {
					graph[numbering[i][j]][numbering[i - 1][j]] = 1e9;
					vt[numbering[i][j]].push_back(numbering[i - 1][j]);
					vt[numbering[i - 1][j]].push_back(numbering[i][j]);
				}
				if (j != 1) {
					graph[numbering[i][j]][numbering[i][j - 1]] = 1e9;
					vt[numbering[i][j]].push_back(numbering[i][j - 1]);
					vt[numbering[i][j - 1]].push_back(numbering[i][j]);
				}
				if (i != N) {
					graph[numbering[i][j]][numbering[i + 1][j]] = 1e9;
					vt[numbering[i][j]].push_back(numbering[i + 1][j]);
					vt[numbering[i + 1][j]].push_back(numbering[i][j]);
				}
				if (j != M) {
					graph[numbering[i][j]][numbering[i][j + 1]] = 1e9;
					vt[numbering[i][j]].push_back(numbering[i][j + 1]);
					vt[numbering[i][j + 1]].push_back(numbering[i][j]);
				}
			}
		}
	}
	S = 0; T = cnt + 1;
}
void goo(int n) {
	if (n == 0) return;
	minV = min(graph[pre[n]][n], minV);
	goo(pre[n]);
}
void go(int n) {
	if (n == 0) return;
	graph[pre[n]][n] -= minV;
	graph[n][pre[n]] += minV;
	go(pre[n]);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> TC;
	while (TC--) {
		cin >> N >> M;
		init();
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				if (tmp[i][j] == 0) continue;
				if (i % 2 == j % 2) {
					graph[S][numbering[i][j]] = tmp[i][j];
					vt[S].push_back(numbering[i][j]);
					vt[numbering[i][j]].push_back(S);
				}
				else {
					graph[numbering[i][j]][T] = tmp[i][j];
					vt[numbering[i][j]].push_back(T);
					vt[T].push_back(numbering[i][j]);
				}
			}
		}
		int ans = 0;
		while (1) {
			for (int i = 0; i <= T; ++i) {
				visit[i] = 0;
				pre[i] = 0;
			}
			q.push(0);
			visit[0] = 1;
			bool flag = 0;
			minV = 1e9;
			while (!q.empty()) {
				int n = q.front(); q.pop();
				for (int i : vt[n]) {
					if (!visit[i] && graph[n][i] > 0) {
						visit[i] = 1;
						pre[i] = n;
						if (i == T) {
							flag = 1;
							while (!q.empty()) q.pop();
							break;
						}
						q.push(i);
					}
				}
			}
			if (!flag) break;
			goo(T);
			go(T);
			ans += minV;
		}
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				if (i % 2 == j % 2) {
					ans += graph[0][numbering[i][j]];
				}
				else {
					ans += graph[numbering[i][j]][T];
				}
			}
		}
		cout << ans << "\n";
	}
}