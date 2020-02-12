#include <bits/stdc++.h>
using namespace std;
int N, arr[10005], dp[10005][2];
vector<int> vt[10005], tr[10005];
bool visit[10005];
void go(int n) {
	for (int nn : vt[n]) {
		if (!visit[nn]) {
			visit[nn] = 1;
			tr[n].push_back(nn);
			go(nn);
		}
	}
}
int get(int n, bool chk) {
	if (dp[n][chk] != -1) return dp[n][chk];
	int ret = 0;
	if (chk) {
		int v = 0;
		for (int nn : tr[n]) {
			v += get(nn, 0);
		}
		ret = max(ret, v);
	}
	else {
		int v = 0;
		for (int nn : tr[n]) {
			v += max(get(nn, 0), get(nn, 1));
		}
		ret = max(ret, v);
	}
	dp[n][chk] = ret;
	if (chk) {
		return ret + arr[n];
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		for (int j = 0; j < 2; ++j) {
			dp[i][j] = -1;
		}
	}
	for (int i = 1, a, b; i < N; ++i) {
		cin >> a >> b;
		vt[a].push_back(b);
		vt[b].push_back(a);
	}
	visit[1] = 1;
	go(1);
	cout << max(get(1, 0), get(1, 1));
}