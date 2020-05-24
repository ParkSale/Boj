#include <bits/stdc++.h>
using namespace std;
int N, graph[2500][2500], cnt[3];
bool check(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (graph[i][j] != graph[x][y]) return 0;
		}
	}
	return 1;
}
void divide(int x, int y, int n) {
	if (!check(x, y, n)) {
		divide(x, y, n / 3);
		divide(x + n / 3, y, n / 3);
		divide(x + (n * 2) / 3, y, n / 3);
		divide(x, y + n / 3, n / 3);
		divide(x, y + (2 * n) / 3, n / 3);
		divide(x + n / 3, y + n / 3, n / 3);
		divide(x + (2 * n) / 3, y + n / 3, n / 3);
		divide(x + n / 3, y + (2 * n) / 3, n / 3);
		divide(x + (2 * n) / 3, y + (2 * n) / 3, n / 3);
	}
	else cnt[graph[x][y] + 1]++;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> graph[i][j];
		}
	}
	divide(1, 1, N);
	for (int i : cnt) cout << i << "\n";
}