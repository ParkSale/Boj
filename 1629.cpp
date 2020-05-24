#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A, B, C, ans = 1;
int main() {
	cin >> A >> B >> C;
	while (B > 0) {
		if (B & 1) {
			B--;
			ans = (ans * A) % C;
		}
		else {
			B /= 2;
			A = (A * A) % C;
		}
	}
	cout << ans;
}