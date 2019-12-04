#include <bits/stdc++.h>
using namespace std;
int N, Q, arr[200005], brr[200005];
int get(int a, int b) {
	return brr[a] ^ brr[b];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> Q;
	brr[1] = 1;
	for (int i = 2; i <= N; i++) {
		cin >> arr[i];
		int v = brr[i - 1], d = arr[i];
		string s = "";
		while (!(v == 0 && d == 0)) {
			if (v % 2 == d % 2) {
				s += "0";
			}
			else {
				s += "1";
			}
			v /= 2;
			d /= 2;
		}
		int vv = 1, ans = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '1') {
				ans += vv;
			}
			vv *= 2;
		}
		brr[i] = ans;
	}
	while (Q--) {
		int a, b, c, d;
		cin >> a;
		if (a == 0) {
			cin >> b >> c;
			cout << get(b, c) << "\n";
		}
		else {
			cin >> b >> c >> d;
			int v = get(b, c);
			string s = "";
			while (!(v == 0 && d == 0)) {
				if (v % 2 == d % 2) {
					s += "0";
				}
				else {
					s += "1";
				}
				v /= 2;
				d /= 2;
			}
			int vv = 1, ans = 0;
			for (int i = 0; i < s.length(); i++) {
				if (s[i] == '1') {
					ans += vv;
				}
				vv *= 2;
			}
			cout << ans << "\n";
		}
	}
}