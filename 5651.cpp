#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int TC, N, M, graph[305][305], pre[305], minV, cnt, val, tmp[305][305], chk[305][305];
queue<int> q;
vector<int> vtt[305];
bool visit[305], visit2[305];
void init() {
	for (int i = 1; i <= N; ++i) {
		visit[i] = 0;
		pre[i] = 0;
		vtt[i].clear();
		for (int j = 1; j <= N; ++j) {
			graph[i][j] = 0;
			chk[i][j] = 0;
		}
	}
	cnt = 0;
	val = 0;
}
void go(int n) {
	if (n == 1) return;
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
		for (int i = 1; i <= M; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			graph[a][b] += c;
			chk[b][a] = 1;
			vtt[a].push_back(b);
		}
		while (1) {
			for (int i = 1; i <= N; ++i) {
				visit[i] = 0;
				pre[i] = 0;
			}
			visit[1] = 1;
			q.push(1);
			bool flag = 0;
			minV = 1e9;
			while (!q.empty()) {
				int n = q.front(); q.pop();
				for (int i = 1; i <= N; ++i) {
					if (!visit[i] && graph[n][i] > 0) {
						pre[i] = n;
						minV = min(minV, graph[n][i]);
						visit[i] = 1;
						if (i == N) {
							flag = 1;
							while (!q.empty())q.pop();
							break;
						}
						q.push(i);
					}
				}
			}
			if (!flag) break;
			go(N);
		}
		for (int k = 1; k <= N; ++k) {
			for (int i = 1; i <= N; ++i) {
				for (int j = 1; j <= N; ++j) {
					if (graph[i][j] == 0 && graph[i][k] > 0 && graph[k][j] > 0) {
						graph[i][j] = 1;
					}
				}
			}
		}
		for (int i = 1; i <= N; ++i) {
			for (int n : vtt[i]) {
				if (!graph[i][n]) ++cnt;
			}
		}
		cout << cnt << "\n";
	}
}