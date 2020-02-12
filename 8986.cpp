#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, arr[100005];
vector<ll> vt[2];
ll get(ll k) {
	ll ans = 0;
	for (int i = 0; i < vt[1].size(); i++) {
		vt[0][i] = vt[1][i];
	}
	for (int i = 0; i < vt[0].size() - 1; i++) {
		if (vt[0][i] > k) {
			ll tmp = vt[0][i] - k;
			vt[0][i] -= tmp;
			vt[0][i + 1] += tmp;
			ans += tmp;
		}
		else if (vt[0][i] < k) {
			ll tmp = k - vt[0][i];
			vt[0][i] += tmp;
			vt[0][i + 1] -= tmp;
			ans += tmp;
		}
	}
	if (vt[0][vt[0].size() - 1] > k) {
		ans += (vt[0][vt[0].size() - 1] - k);
	}
	else if (vt[0][vt[0].size() - 1] < k) {
		ans += (k - vt[0][vt[0].size() - 1]);
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	ll v = 0;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		v += arr[i];
	}
	if (N == 1) {
		cout << 0;
		exit(0);
	}
	ll sum = 0;
	for (int i = 1; i < N; i++) {
		vt[0].push_back(arr[i + 1] - arr[i]);
		vt[1].push_back(arr[i + 1] - arr[i]);
	}
	int s = 1, e = 2e9, minV = 2e9;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (get(mid) < get(mid + 1)) {
			minV = min(minV, mid);
			e = mid - 1;
		}
		else s = mid + 1;
	}
	cout << get(minV);
}