#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, dp[100005], seg[500005 * 4];
pii arr[100005];
vector<int> vt;
void update(int n) {
	while (n != 1) {
		seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
		n /= 2;
	}
}
int get(int s, int e) {
	int ret = 0;
	while (s <= e) {
		if (s % 2 == 1) ret = max(ret, seg[s++]);
		if (e % 2 == 0) ret = max(ret, seg[e--]);
		s /= 2; e /= 2;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int maxV = 0;
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = { b,a };
		maxV = max(maxV, a);
	}
	sort(arr + 1, arr + N + 1);
	int s = 1;
	while (s < maxV) s *= 2;
	s--;
	int maxValue = 0;
	for (int i = 1; i <= N; i++) {
		int n = arr[i].second;
		int v = get(s + 1, s + n);
		dp[i] = v + 1;
		seg[s + n] = dp[i];
		update((s + n) / 2);
		maxValue = max(maxValue, dp[i]);
	}
	int now = maxValue;
	for (int i = N; i >= 1; i--) {
		if (dp[i] == now) {
			now--;
		}
		else {
			vt.push_back(arr[i].second);
		}
	}
	cout << vt.size() << "\n";
	sort(vt.begin(), vt.end());
	for (int n : vt) cout << n << "\n";
}