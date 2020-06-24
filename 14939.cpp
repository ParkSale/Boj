#include <iostream>
using namespace std;
int min(int a, int b) {
	return a > b ? b : a;
}
struct info {
	int x, y;
}dir[] = { {1,0},{-1,0},{0,1},{0,-1} };
int arr[15], minV = 1e9;
char graph[15][15], tmp[15][15];
void toggle(int x, int y) {
	if (tmp[x][y] == '#') tmp[x][y] = 'O';
	else tmp[x][y] = '#';
}
void change(int x, int y) {
	for (int i = 0; i < 4; ++i) {
		int px = x + dir[i].x, py = y + dir[i].y;
		if (px >= 1 && px <= 10 && py >= 1 && py <= 10) {
			toggle(px, py);
		}
	}
	toggle(x, y);
}
void go(int a, int n, int k) {
	if (n == k) {
		int cnt = 0;
		for (int i = 1; i <= 10; ++i) {
			for (int j = 1; j <= 10; ++j) {
				tmp[i][j] = graph[i][j];
			}
		}
		for (int i = 1; i <= 10; ++i) {
			if (arr[i] == 1) {
				change(1, i);
				++cnt;
			}
		}
		for (int i = 2; i <= 10; ++i) {
			for (int j = 1; j <= 10; ++j) {
				if (tmp[i - 1][j] == 'O') {
					change(i, j);
					++cnt;
				}
			}
		}
		for (int i = 1; i <= 10; ++i) {
			for (int j = 1; j <= 10; ++j) {
				if (tmp[i][j] == 'O') {
					return;
				}
			}
		}
		minV = min(minV, cnt);
		return;
	}
	for (int i = a + 1; i <= 10; ++i) {
		if (arr[i] == 0) {
			arr[i] = 1;
			go(i, n + 1, k);
			arr[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 1; i <= 10; ++i) {
		for (int j = 1; j <= 10; ++j) {
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i <= 10; ++i) {
		go(0, 0, i);
	}
	int cnt = 0;
	minV == 1e9 ? cout << -1 : cout << minV;
}