#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, dp[105];
pii arr[105];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = { b,a };
	}
	sort(arr + 1, arr + N + 1);
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i].second > arr[j].second) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	int maxV = 0;
	for (int i = 1; i <= N; i++)maxV = max(maxV, dp[i]);
	cout << N - maxV;
}