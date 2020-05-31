#include <stdio.h>
#define MOD 1000000000
int N, K, dp[205][205];
int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i <= K; i++) dp[0][i] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			for (int k = 0; k <= i; k++) {
				dp[i][j] += dp[i - k][j - 1];
				dp[i][j] %= MOD;
			}
		}
	}
	printf("%d", dp[N][K]);
}