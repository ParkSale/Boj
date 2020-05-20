#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, minV = 1e9;
char graph[15][15];
pii dir[] = { {0,1},{0,-1},{1,0},{-1,0} }, red, blue;
void go(pii r, pii b, int cnt) {
	if (cnt == 10) return;
	for (int i = 0; i < 4; i++) {
		int rx, ry, bx, by;
		int k = 1;
		bool flag = 0;
		while (1) {
			rx = r.first + dir[i].first * k, ry = r.second + dir[i].second * k;
			if (rx > 1 && rx < N && ry>1 && ry < M) {
				if (graph[rx][ry] != '#' && graph[rx][ry] != 'O') {
					k++;
					continue;
				}
				else if (graph[rx][ry] == 'O') {
					flag = 1;
					break;
				}
				else break;
			}
			else break;
		}
		rx -= dir[i].first, ry -= dir[i].second;
		k = 1;
		bool flag2 = 0;
		while (1) {
			bx = b.first + dir[i].first * k, by = b.second + dir[i].second * k;
			if (bx > 1 && bx < N && by>1 && by < M) {
				if (graph[bx][by] != '#' && graph[bx][by] != 'O') {
					k++;
					continue;
				}
				else if (graph[bx][by] == 'O') {
					flag2 = 1;
					break;
				}
				else {
					break;
				}
			}
			else break;
		}
		if (flag2 == 1) continue;
		bx -= dir[i].first, by -= dir[i].second;
		if (flag == 1) {
			minV = min(minV, cnt + 1);
			return;
		}
		if (rx == bx && ry == by) {
			if (i == 0) {
				if (r.second > b.second) {
					by = ry - 1;
				}
				else ry = by - 1;
			}
			else if (i == 1) {
				if (r.second > b.second) {
					ry = by + 1;
				}
				else by = ry + 1;
			}
			else if (i == 2) {
				if (r.first > b.first) {
					bx = rx - 1;
				}
				else rx = bx - 1;
			}
			else {
				if (r.first > b.first) {
					rx = bx + 1;
				}
				else bx = rx + 1;
			}
		}
		if (rx == r.first && ry == r.second && bx == b.first && by == b.second) {
			continue;
		}
		go({ rx,ry }, { bx,by }, cnt + 1);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++) {
			graph[i][j] = s[j - 1];
			if (s[j - 1] == 'R') red = { i,j };
			else if (s[j - 1] == 'B') blue = { i,j };
		}
	}
	go(red, blue, 0);
	minV == 1e9 ? cout << -1 : cout << minV;
}