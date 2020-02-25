#include <bits/stdc++.h>
using namespace std;
struct info {
	int V, M, C;
}I[105], t[12000];
int N, M, dp[10005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		I[i] = { a,b,c };
	}
	int idx = 0;
	for (int i = 1; i <= N; ++i) {
		int v = I[i].C, cnt = 1, sum = 1;
		while (sum <= v) {
			t[++idx] = { I[i].V * cnt,I[i].M * cnt,cnt };
			cnt *= 2;
			sum += cnt;
			if (sum >= v) {
				sum -= cnt;
				t[++idx] = { I[i].V * (v - sum),I[i].M * (v - sum),v - sum };
				break;
			}
		}

	}
	for (int i = 1; i <= idx; ++i) {
		for (int j = M; j >= t[i].V; --j) {
			dp[j] = max(dp[j], dp[j - t[i].V] + t[i].M);
		}
	}
	int ans = 0;
	for (int i = 1; i <= M; ++i) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
}