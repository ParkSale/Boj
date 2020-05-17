#include <bits/stdc++.h>
using namespace std;
int N;
pair<long long, long long> arr[200005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 1, a, b; i <= N; ++i) {
		cin >> a >> b;
		arr[i] = { a,b };
	}
	long long a = -1e18, b = 1e18, c = -1e18, d = 1e18;
	for (int i = 1; i <= N; ++i) {
		a = max(a, arr[i].second - arr[i].first);
		b = min(b, -arr[i].first + arr[i].second);
		c = max(c, arr[i].first + arr[i].second);
		d = min(d, arr[i].first + arr[i].second);
	}
	unsigned long long maxV = max(a - b, c - d);
	if (maxV % 2 == 0) {
		cout << maxV * maxV / 2;
	}
	else {
		cout << (maxV * maxV) / 2;
		cout << ".5";
	}
}