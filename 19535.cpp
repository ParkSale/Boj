#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, D, G;
vector<ll> vt[300005];
bool v[300005];
void go(int n) {
	for (ll nn : vt[n]) {
		if (v[nn]) continue;
		ll v1 = vt[n].size() - 1, v2 = vt[nn].size() - 1;
		D += v1 * v2;
		v[nn] = 1;
		go(nn);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1, a, b; i < N; ++i) {
		cin >> a >> b;
		vt[a].push_back(b);
		vt[b].push_back(a);
	}
	for (int i = 1; i <= N; ++i) {
		ll k = vt[i].size();
		if (k >= 3) {
			G += (k * (k - 1) * (k - 2)) / 6;
		}
	}
	G *= 3;
	v[1] = 1;
	go(1);
	if (D > G) {
		cout << "D";
	}
	else if (D == G) {
		cout << "DUDUDUNGA";
	}
	else {
		cout << "G";
	}
}
