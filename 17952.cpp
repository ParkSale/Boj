#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
struct info {
	int n, s, t;
}I[1000005];
int N;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	int idx = 1;
	int ans = 0;
	while (N--) {
		int a, b, c;
		cin >> a;
		if (a == 0) {
			I[idx - 1].t--;
			if (I[idx - 1].t == 0) {
				ans += I[idx - 1].s;
				idx--;
			}
			continue;
		}
		cin >> b >> c;
		I[idx++] = { a,b,c };
		I[idx - 1].t--;
		if (I[idx - 1].t == 0) {
			ans += I[idx - 1].s;
			idx--;
		}
	}
	cout << ans;
}