#include <bits/stdc++.h>
using namespace std;
int N, C, arr[200005];
bool can(int x) {
	int n = arr[1], cnt = 1;
	for (int i = 2; i <= N; i++) {
		if (arr[i] - n >= x) {
			n = arr[i];
			++cnt;
		}
	}
	return cnt >= C;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> C;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	int s = 1, e = 1e9, maxV = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (can(mid)) {
			s = mid + 1;
			maxV = max(maxV, mid);
		}
		else e = mid - 1;
	}
	cout << maxV;
}