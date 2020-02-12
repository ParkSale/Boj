#include <bits/stdc++.h>
using namespace std;
int N, arr[200005], Q, dp[20][200005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		dp[0][i] = arr[i];
	}
	for (int i = 1; i <= 20; ++i) {
		for (int j = 1; j <= N; ++j) {
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}
	cin >> Q;
	while (Q--) {
		int a, b;
		cin >> a >> b;
		int ans = b, cnt = 0;
		while (a != 0) {
			if (a % 2 == 1) {
				ans = dp[cnt][ans];
			}
			a /= 2;
			++cnt;
		}
		cout << ans << "\n";
	}
}