#include <iostream>
using namespace std;
struct info {
	int x, y;
};
int N, M, graph[505][505], cnt[505][505];
info temp[505][505], dir[] = { {1,0},{1,-1},{1,1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1} };
info go(int x, int y) {
	if (temp[x][y].x == x && temp[x][y].y == y) {
		cnt[x][y]++;
		return { x,y };
	}
	temp[x][y] = go(temp[x][y].x, temp[x][y].y);
	return temp[x][y];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int minV = graph[i][j], minX = i, minY = j;
			for (int k = 0; k < 8; k++) {
				int px = i + dir[k].x, py = j + dir[k].y;
				if (px >= 1 && px <= N && py >= 1 && py <= M) {
					if (minV > graph[px][py]) {
						minV = graph[px][py];
						minX = px, minY = py;
					}
				}
			}
			temp[i][j] = { minX,minY };
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			go(i, j);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << cnt[i][j] << " ";
		}
		cout << "\n";
	}
}