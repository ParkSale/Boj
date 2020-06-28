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
				//���� �� ������ �湮�� ��, ó�� �湮�ϰų� �̹� �湮�߰ų� �� �� �ϳ�
				//�̹� �湮�� ������ �湮�� ��, ������ �������� �� �������� ���°� �� �̵����� �ƴϸ� ���� ���°� �� �̵����� �Ǵ��� �ʿ�
				int px = p.x + k * dir[i].first, py = p.y + k * dir[i].second;
				if (px<1 || px>N || py<1 || py>M || graph[px][py] == '#') break;
				if (visit[px][py] == 1e9) {
					//ó���湮
					visit[px][py] = p.dist + 1;
					q.push({ px,py,p.dist + 1 });
				}
				else if (visit[px][py] == p.dist + 1) {
					//�̹� �湮�� ������ �� ���� ����ġ�� ��� �����°� �̵�
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