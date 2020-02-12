#include <bits/stdc++.h>
using namespace std;
int TC, N, arr[1005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> TC;
	while (TC--) {
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> arr[i];
		int sum = 0, maxV = -1e9;
		for (int i = 1; i <= N; i++) {
			sum += arr[i];
			maxV = max(sum, maxV);
			if (sum < 0) sum = 0;
		}
		cout << maxV << "\n";
	}
}