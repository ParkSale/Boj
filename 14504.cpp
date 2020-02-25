#include <bits/stdc++.h>
using namespace std;
int N, arr[200005], Q, n, brr[200005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	n = sqrt(N);
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		brr[i] = arr[i];
	}
	for (int i = N; i <= N + 2 * n; ++i) {
		brr[i] = 1e9 + 7;
	}
	int s = 0, e = n;
	while (e < N) {
		sort(brr + s, brr + e);
		s += n;
		e += n;
	}
	sort(brr + s, brr + N);
	cin >> Q;
	while (Q--) {
		int a, b, c, d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			--b; --c;
			int t1 = b / n;
			int t2 = b % n;
			int tt1 = c / n;
			int tt2 = c % n;
			int ans = 0;
			if (t1 == tt1) {
				while (t2 <= tt2) {
					if (arr[t1 * n + t2] > d) {
						++ans;
					}
					++t2;
				}
			}
			else {
				while (t2 != n) {
					if (arr[t1 * n + t2] > d) {
						++ans;
					}
					++t2;
				}
				while (tt2 >= 0) {
					if (arr[tt1 * n + tt2] > d) {
						++ans;
					}
					--tt2;
				}
				for (int i = t1 + 1; i <= tt1 - 1; ++i) {
					int v = upper_bound(brr + i * n, brr + (i + 1) * n, d) - (brr + i * n);
					ans += n - v;
				}
			}
			cout << ans << "\n";
		}
		else {
			cin >> b >> c;
			--b;
			int t1 = b / n;
			int t2 = b % n;
			int v = 0;
			for (int i = 0; i < n; ++i) {
				if (brr[t1 * n + i] == arr[b]) {
					v = t1 * n + i;
					break;
				}
			}
			arr[b] = c;
			brr[v] = c;
			int tt1 = v / n;
			int tt2 = v % n;
			if (tt2 == 0) {
				while (tt2 != n - 1) {
					if (brr[tt1 * n + tt2] > brr[tt1 * n + tt2 + 1]) {
						swap(brr[tt1 * n + tt2], brr[tt1 * n + tt2 + 1]);
						++tt2;
					}
					else break;
				}
			}
			else if (tt2 == n - 1) {
				while (tt2 != 0) {
					if (brr[tt1 * n + tt2] < brr[tt1 * n + tt2 - 1]) {
						swap(brr[tt1 * n + tt2], brr[tt1 * n + tt2 - 1]);
						--tt2;
					}
					else break;
				}
			}
			else {
				if (brr[tt1 * n + tt2] < brr[tt1 * n + tt2 + 1]) {
					while (tt2 != 0) {
						if (brr[tt1 * n + tt2] < brr[tt1 * n + tt2 - 1]) {
							swap(brr[tt1 * n + tt2], brr[tt1 * n + tt2 - 1]);
							--tt2;
						}
						else break;
					}
				}
				else {
					while (tt2 != n - 1) {
						if (brr[tt1 * n + tt2] > brr[tt1 * n + tt2 + 1]) {
							swap(brr[tt1 * n + tt2], brr[tt1 * n + tt2 + 1]);
							++tt2;
						}
						else break;
					}
				}
			}
		}
	}
}