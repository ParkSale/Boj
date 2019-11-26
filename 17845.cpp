#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, K, dp[2][10005];
pii arr[1005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1, a, b; i <= K; i++) {
		cin >> a >> b;
		arr[i] = { a,b };
	}
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j]);
			if (j - arr[i].second >= 0) {
				dp[i % 2][j] = max(dp[(i - 1) % 2][j - arr[i].second] + arr[i].first, dp[i % 2][j]);
			}
		}
	}
	int maxV = 0;
	for (int i = 0; i <= N; i++) {
		maxV = max(maxV, dp[K % 2][i]);
	}
	cout << maxV;
}