#include <bits/stdc++.h>
using namespace std;
int N, B, K, graph[505][505];
pair<int, int> dp[505][505];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> B >> K;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> graph[i][j];
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (i + B > N + 1) break;
		for (int j = 1; j <= N; ++j) {
			int maxV = 0, minV = 1e9;
			for (int k = i; k < i + B; ++k) {
				maxV = max(maxV, graph[k][j]);
				minV = min(minV, graph[k][j]);
			}
			dp[i][j] = { maxV,minV };
		}
	}
	for (int i = 1; i <= K; ++i) {
		int a, b;
		cin >> a >> b;
		int maxV = 0, minV = 1e9;
		for (int j = b; j < b + B; ++j) {
			maxV = max(maxV, dp[a][j].first);
			minV = min(minV, dp[a][j].second);
		}
		cout << maxV - minV << "\n";
	}
}