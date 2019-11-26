#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, T, graph[105][105];
struct info {
	int x, y, t, flag;
};
queue<info> q;
bool visit[105][105][2];
pii dir[] = { {1,0},{0,1},{-1,0},{0,-1} };
void go() {
	q.push({ 1,1,0,0 });
	visit[1][1][0] = 1;
	while (!q.empty()) {
		info p = q.front(); q.pop();
		if (p.t > T) continue;
		if (p.x == N && p.y == M) {
			cout << p.t;
			exit(0);
		}
		for (int i = 0; i < 4; i++) {
			int px = p.x + dir[i].first, py = p.y + dir[i].second;
			if (px >= 1 && px <= N && py >= 1 && py <= M && !visit[px][py][p.flag]) {
				if (p.flag == 1) {
					visit[px][py][p.flag] = 1;
					q.push({ px,py,p.t + 1,p.flag });
				}
				else {
					if (graph[px][py] == 0) {
						visit[px][py][p.flag] = 1;
						q.push({ px,py,p.t + 1,p.flag });
					}
					else if (graph[px][py] == 2) {
						visit[px][py][p.flag] = 1;
						q.push({ px,py,p.t + 1,1 });
					}
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> graph[i][j];
		}
	}
	go();
	cout << "Fail";
}