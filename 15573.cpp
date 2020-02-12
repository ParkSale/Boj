#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
pii dir[] = { {1,0},{-1,0},{0,1},{0,-1} };
int N, M, graph[1005][1005], chkGraph[1005][1005], K;
bool visit[1005][1005];
queue<pii> q;
void dup() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			chkGraph[i][j] = graph[i][j];
			visit[i][j] = 0;
		}
	}
}
bool can(int x) {
	int cnt = 0;
	for (int i = 2; i <= N; i++) {
		if (chkGraph[i][1] <= x) {
			visit[i][1] = 1;
			q.push({ i,1 });
		}
	}
	for (int j = 1; j <= M; j++) {
		if (chkGraph[1][j] <= x) {
			visit[1][j] = 1;
			q.push({ 1,j });
		}
	}
	for (int i = 2; i <= N; i++) {
		if (chkGraph[i][M] <= x) {
			visit[i][M] = 1;
			q.push({ i,M });
		}
	}
	while (!q.empty()) {
		pii p = q.front(); q.pop();
		bool flag = 0;
		for (int i = 0; i < 4; i++) {
			int px = p.first + dir[i].first, py = p.second + dir[i].second;
			if (chkGraph[px][py] == 0 && chkGraph[p.first][p.second] <= x) {
				cnt++;
				chkGraph[p.first][p.second] = 0;
				flag = 1;
				break;
			}
		}
		if (flag) {
			for (int i = 0; i < 4; i++) {
				int px = p.first + dir[i].first, py = p.second + dir[i].second;
				if (chkGraph[px][py] != 0 && !visit[px][py]) {
					visit[px][py] = 1;
					q.push({ px,py });
				}
			}
		}
	}
	return cnt >= K;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 1; i <= M; i++) {
		graph[N + 1][i] = -1;
	}
	int s = 1, e = 1e6, minV = 1e9;
	while (s <= e) {
		dup();
		int mid = (s + e) / 2;
		if (can(mid)) {
			e = mid - 1;
			minV = min(minV, mid);
		}
		else {
			s = mid + 1;
		}
	}
	cout << minV;
}