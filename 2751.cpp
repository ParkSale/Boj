#include <bits/stdc++.h>
using namespace std;
int N, arr[2000005], cnt[2000005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		arr[i] += 1000000;
		cnt[arr[i]]++;
	}
	for (int i = 0; i <= 2000000; ++i) {
		while (cnt[i] != 0) {
			cout << i - 1000000 << "\n";
			--cnt[i];
		}
	}
}