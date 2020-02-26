#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, graph[600][600], pre, ans, minV;
bool visit[600], flag;
vector<int> vt[600];
queue<int> q;
void goo() {
	int n = 2;
	while (n != 1) {
		graph[vt[n][0]][n]--;
		graph[n][vt[n][0]]++;
		n = vt[n][0];
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1, a, b; i <= M; ++i) {
		cin >> a >> b;
		graph[a][b]++;
	}
	while (1) {
		for (int i = 1; i <= N; ++i) {
			visit[i] = 0;
			vt[i].clear();
		}
		flag = 0;
		q.push(1);
		visit[1] = 1;
		while (!q.empty()) {
			int n = q.front(); q.pop();
			for (int i = 1; i <= N; ++i) {
				if (graph[n][i] != 0 && !visit[i]) {
					visit[i] = 1;
					q.push(i);
					vt[i].push_back(n);
					if (i == 2) {
						flag = 1;
						while (!q.empty()) q.pop();
						break;
					}
				}
			}
		}
		if (flag) {
			ans++;
		}
		else break;
		goo();
	}
	cout << ans;
}