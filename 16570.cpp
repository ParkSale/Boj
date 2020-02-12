#include <bits/stdc++.h>
using namespace std;
const int mod = 1999997;
int N, arr[1000005], brr[1000005], f[1000005];
void getF() {
	int idx = 0;
	for (int i = 1; i < N; ++i) {
		while (idx > 0 && brr[i] != brr[idx]) {
			idx = f[idx - 1];
		}
		if (brr[i] == brr[idx]) {
			f[i] = ++idx;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];
	for (int i = N - 1; i >= 0; --i) brr[i] = arr[N - 1 - i];
	getF();
	int maxV = 0, cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (maxV < f[i]) {
			maxV = f[i];
			cnt = 1;
		}
		else if (maxV == f[i]) ++cnt;
	}
	if (maxV == 0) cout << -1;
	else cout << maxV << " " << cnt;
}