#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, K, sx, sy, ex, ey, minV = 1e9;
char graph[1005][1005];
struct info {
	int x, y, dist;
};
queue<info> q;
int visit[1005][1005];
pii dir[] = { {0,1},{0,-1},{1,0},{-1,0} };
void go() {
	q.push({ sx,sy,0 });
	visit[sx][sy] = 0;
	while (!q.empty()) {
		info p = q.front(); q.pop();
		if (p.x == ex && p.y == ey) {
			cout << p.dist;
			exit(0);
		}
		for (int i = 0; i < 4; i++) {
			for (int k = 1; k <= K; k++) {
				//내가 이 지점을 방문할 땐, 처음 방문하거나 이미 방문했거나 둘 중 하나
				//이미 방문한 지점을 방문할 땐, 이후의 지점들을 그 지점에서 가는게 더 이득인지 아니면 지금 가는게 더 이득인지 판단이 필요
				int px = p.x + k * dir[i].first, py = p.y + k * dir[i].second;
				if (px<1 || px>N || py<1 || py>M || graph[px][py] == '#') break;
				if (visit[px][py] == 1e9) {
					//처음방문
					visit[px][py] = p.dist + 1;
					q.push({ px,py,p.dist + 1 });
				}
				else if (visit[px][py] == p.dist + 1) {
					//이미 방문한 지점일 때 같은 가중치면 계속 가보는게 이득
					continue;
				}
				else break;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> graph[i][j];
			visit[i][j] = 1e9;
		}
	}
	cin >> sx >> sy >> ex >> ey;
	go();
	cout << -1;
}