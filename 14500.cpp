#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
pii block[][3] = { {{0,1},{0,2},{0,3}},{{0,1},{1,0},{1,1}},{{1,0},{2,0},{2,1}} ,{{1,0},{1,1},{2,1}},{{0,1},{0,2},{1,1}},{{1,0},{2,0},{3,0}},{{0,1},{1,1},{2,1}},{{1,0},{1,1},{1,2}},{{0,1},{0,2},{-1,2}},{{1,0},{0,1},{-1,1}},{{0,1},{-1,1},{-1,2}},{{0,1},{1,1},{1,2}},{{1,0},{2,0},{1,1}},{{0,1},{-1,1},{1,1}},{{0,1},{0,2},{-1,1}},{{1,0},{2,0},{0,1}},{{0,1},{-1,1},{-2,1}},{{1,0},{0,1},{0,2}},{{0,1},{0,2},{1,2}} };
int N, M, graph[505][505], maxV;
void get(int n) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			bool flag = 0;
			for (int k = 0; k < 3; k++) {
				int px = i + block[n][k].first, py = j + block[n][k].second;
				if (px <= 0 || px > N || py <= 0 || py > M) flag = 1;
			}
			if (!flag) {
				int tmp = 0;
				tmp += graph[i][j];
				for (int k = 0; k < 3; k++) {
					int px = i + block[n][k].first, py = j + block[n][k].second;
					tmp += graph[px][py];
				}
				maxV = max(maxV, tmp);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < 19; i++) get(i);
	cout << maxV;
}