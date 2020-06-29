#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M, arr[100005];
bool can(ll x) {
	ll cnt = 0;
	for (int i = 1; i <= N; i++) {
		cnt += (x / arr[i]);
	}
	return cnt >= M;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	ll s = 1e9, e = 1;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		s = min(s, arr[i]);
	}
	e = s * M;
	ll minV = e;
	while (s <= e) {
		ll mid = (s + e) / 2;
		if (can(mid)) {
			e = mid - 1;
			minV = min(minV, mid);
		}
		else s = mid + 1;
	}
	cout << minV;
}