#include <iostream>
using namespace std;
struct info {
	int x, y;
};
struct info2 {
	info r, b;
	int cnt;
};
int N, M, s = 1, e = 1;
char graph[15][15];
bool visit[15][15][15][15];
info R, B;
info dir[] = { {1,0},{0,1},{-1,0},{0,-1} };
info2 queue[1000005];
void go() {
	queue[1] = { R,B,0 };
	while (s <= e) {
		info2 p = queue[s++];
		for (int i = 0; i < 4; ++i) {
			int rx = p.r.x, ry = p.r.y;
			int bx = p.b.x, by = p.b.y;
			bool flagR = 0;
			bool goalR = 0, goalB = 0;
			for (int k = 1; k <= 15; ++k) {
				if (flagR) {
					rx -= dir[i].x;
					ry -= dir[i].y;
					break;
				}
				rx += dir[i].x;
				ry += dir[i].y;
				if (rx < 1 || rx > N || ry < 1 || ry > M) flagR = 1;
				else if (graph[rx][ry] == '.') {
					if (rx == bx && ry == by) {
						flagR = 1;
					}
				}
				else if (graph[rx][ry] == '#') {
					flagR = 1;
				}
				else if (graph[rx][ry] == 'O') {
					goalR = 1;
					break;
				}
			}
			bool flagB = 0;
			for (int k = 1; k <= 15; ++k) {
				if (flagB) {
					bx -= dir[i].x;
					by -= dir[i].y;
					break;
				}
				bx += dir[i].x;
				by += dir[i].y;
				if (bx < 1 || bx > N || by < 1 || by > M) flagB = 1;
				else if (graph[bx][by] == '.') {
					if (bx == rx && by == ry) {
						flagB = 1;
					}
				}
				else if (graph[bx][by] == '#') {
					flagB = 1;
				}
				else if (graph[bx][by] == 'O') {
					goalB = 1;
					break;
				}
			}
			flagR = 0;
			for (int k = 1; k <= 15; ++k) {
				if (flagR) {
					rx -= dir[i].x;
					ry -= dir[i].y;
					break;
				}
				rx += dir[i].x;
				ry += dir[i].y;
				if (rx < 1 || rx > N || ry < 1 || ry > M) flagR = 1;
				else if (graph[rx][ry] == '.') {
					if (rx == bx && ry == by) {
						flagR = 1;
					}
				}
				else if (graph[rx][ry] == '#') {
					flagR = 1;
				}
				else if (graph[rx][ry] == 'O') {
					goalR = 1;
					break;
				}
			}
			if (goalR && goalB) {
				continue;
			}
			else if (goalR) {
				cout << p.cnt + 1;
				exit(0);
			}
			else if (goalB) {
				continue;
			}
			else {
				if (visit[rx][ry][bx][by]) continue;
				visit[rx][ry][bx][by] = 1;
				queue[++e] = { {rx,ry},{bx,by},p.cnt + 1 };
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> graph[i][j];
			if (graph[i][j] == 'B') {
				B = { i,j };
				graph[i][j] = '.';
			}
			else if (graph[i][j] == 'R') {
				R = { i,j };
				graph[i][j] = '.';
			}
		}
	}
	visit[R.x][R.y][B.x][B.y] = 1;
	go();
	cout << -1;
}