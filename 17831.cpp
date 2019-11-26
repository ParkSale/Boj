#include <bits/stdc++.h>
using namespace std;
int N, val[2000005], pa[2000005], dp[2][2000005];
vector<int> vt[2000005];
int go(int n, bool chk) {
	int& ret = dp[chk][n];
	if (ret != -1) return ret;
	if (chk == 1) {
		ret = 0;
		for (int nn : vt[n]) {
			ret += go(nn, 0);
		}
	}
	else {
		ret = 0;
		int a = 0, b = 0;
		for (int nn : vt[n]) {
			a += go(nn, 0);
		}
		for (int nn : vt[n]) {
			b = a - go(nn, 0) + go(nn, 1) + (val[n] * val[nn]);
			ret = max(ret, b);
		}
		ret = max(ret, a);
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 2; i <= N; i++) {
		cin >> pa[i];
		vt[pa[i]].push_back(i);
	}
	for (int i = 1; i <= N; i++) {
		cin >> val[i];
		for (int j = 0; j <= 1; j++) {
			dp[j][i] = -1;
		}
	}
	cout << go(1, 0);
}