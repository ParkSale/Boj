#include <bits/stdc++.h>
using namespace std;
int N, graph[66][66];
string s;
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
		s += "(";
		divide(x, y, n / 2);
		divide(x, y + n / 2, n / 2);
		divide(x + n / 2, y, n / 2);
		divide(x + n / 2, y + n / 2, n / 2);
		s += ")";
	}
	else s += to_string(graph[x][y]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= N; j++) {
			graph[i][j] = s[j - 1] - '0';
		}
	}
	divide(1, 1, N);
	cout << s;
}