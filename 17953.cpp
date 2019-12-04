#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, arr[11][100005], dp[11][100005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[j][i] = max(dp[j][i], dp[j][i - 1] + arr[j][i] / 2);
			int maxV = 0;
			for (int k = 1; k <= M; k++) {
				if (j == k)continue;
				maxV = max(maxV, dp[k][i - 1]);
			}
			dp[j][i] = max(dp[j][i], maxV + arr[j][i]);
		}
	}
	int maxV = 0;
	for (int i = 1; i <= M; i++) {
		maxV = max(maxV, dp[i][N]);
	}
	cout << maxV;
}