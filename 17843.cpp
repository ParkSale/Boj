#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int T;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	cout.setf(ios::showpoint);
	cout << fixed;
	cout.precision(6);
	while (T--) {
		double h, m, s;
		cin >> h >> m >> s;
		double a, b, c;
		a = 30 * h + m * ((double)1 / 2) + s * ((double)1 / 120);
		b = m * (6) + s * ((double)1 / 10);
		c = s * 6;
		double aa = 360 - a, bb = 360 - b, cc = 360 - c;
		cout << min({ min({abs(a - b),abs(aa + b),abs(a + bb)}), min({ abs(a - c),abs(aa + c),abs(a + cc)}), min({ abs(b - c),abs(b + cc),abs(bb + c) }) }) << "\n";
	}
}