#include <bits/stdc++.h>
using namespace std;
int N, K, arr[100005], maxV;
int can(int x) {
	int now = 0, ret = 1e9, cnt = 1;
	for (int i = 1; i <= N; i++) {
		if (now + arr[i] >= x) {
			now += arr[i];
			ret = min(ret, now);
			now = 0;
			cnt++;
			if (cnt > K) {
				maxV = max(maxV, ret);
				return 1;
			}
		}
		else {
			now += arr[i];
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	int s = 0, e = 20 * N;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (can(mid)) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	cout << maxV;
}