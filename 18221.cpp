#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, graph[1005][1005];
pii A, B;
int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 5) {
				B = { i,j };
			}
			else if (graph[i][j] == 2) {
				A = { i,j };
			}
		}
	}
	int v = pow(A.first - B.first, 2) + pow(A.second - B.second, 2);
	if (v < 25) {
		cout << 0;
		exit(0);
	}
	int cnt = 0;
	for (int i = min(A.first, B.first); i <= max(A.first, B.first); i++) {
		for (int j = min(A.second, B.second); j <= max(A.second, B.second); j++) {
			if (graph[i][j] == 1) cnt++;
		}
	}
	if (cnt >= 3) cout << 1;
	else cout << 0;
}