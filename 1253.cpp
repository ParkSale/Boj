#include <bits/stdc++.h>
using namespace std;
int N, arr[2005];
map<int, pair<int, int>> mp;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	int num = 0;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		mp[arr[i]] = { i,0 };
	}
	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			int k = arr[i] + arr[j];
			if (mp.find(k) != mp.end()) {
				if (mp[k].first != i && mp[k].first != j) {
					mp[k].second = 1;
				}
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (mp[arr[i]].second) ++ans;
	}
	cout << ans;
}