#include <bits/stdc++.h>
using namespace std;
int N, M, graph[105][105], K, ans[105];
int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		ans[i] = 1e9;
		for (int j = 1; j <= M; j++) {
			sum += graph[i][j];
			if (sum >= K) {
				ans[i] = j;
				break;
			}
		}
	}
	int val = 1e9, minIdx = 1e9;
	for (int i = 1; i <= N; i++) {
		if (ans[i] < val) {
			val = ans[i];
			minIdx = i;
		}
	}
	cout << minIdx << " " << val;
}