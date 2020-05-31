#include <bits/stdc++.h>
using namespace std;
#define INF 2100000000
int N, dp[100005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) dp[i] = INF;
	for (int i = 1, j; i <= N; i++) {
		j = sqrt(i);
		if (j * j == i) dp[i] = 1;
		else {
			while (j > 0) {
				dp[i] = min(dp[i], dp[j * j] + dp[i - (j * j)]);
				j--;
			}
		}
	}
	cout << dp[N];
}