#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, arr[100005], ans;
pii brr[100005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		brr[i] = { arr[i],i };
	}
	sort(brr + 1, brr + N + 1);
	reverse(brr + 1, brr + N + 1);
	int s = 1, e = N, idx = 1;
	while (s < e) {
		while (brr[idx].second < s) idx++;
		int v = brr[idx].second, t = 0;
		for (int i = s; i <= v; i++) {
			t += arr[i];
		}
		ans += (brr[idx].first * (v - s + 1) - t);
		s = v + 1;
	}
	cout << ans;
}