#include <bits/stdc++.h>
using namespace std;
const int mod = 10000;
typedef long long ll;
int N;
ll fastPow(ll n) {
	if (n == 0) return 1;
	if (n % 2 == 1) {
		ll v = fastPow(n - 1);
		return (v * 2) % mod;
	}
	else {
		ll v = fastPow(n / 2);
		return (v * v) % mod;
	}
}

ll getLength(ll n) {
	string tmp = "9";
	ll a = 1;
	ll ret = 0;
	while (stoll(tmp) <= n) {
		ret += (tmp.length() + 1) * (ll)(stoi(tmp) - a + 1);
		ret %= mod;
		a *= 10;
		tmp.push_back('9');
	}
	ret += (tmp.length() + 1) * (n - a + 1);
	ret %= mod;
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	ll a = (getLength(N) * fastPow(N - 1)) % mod, b = getLength(N) - 1, c = ((N - 1) * 2) % mod, d = N % mod, e = (fastPow(N) - (N + 1)) % mod;
	if (e < 0) e += mod;
	cout << (a + b + c + d + e) % mod;
}