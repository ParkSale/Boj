#include <bits/stdc++.h>
using namespace std;
long long N, D, G;
vector<long long> vt[300005];
void go(int n) {
	for (int nn : vt[n]) {
		D += (vt[n].size() - 1) * (vt[nn].size() - 1);
		go(nn);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		vt[a].push_back(b);
		vt[b].push_back(a);
	}
	for (int i = 1; i <= N; ++i) {
		if (vt[i].size() >= 3) {
			long long k = vt[i].size();
			G += (k * (k - 1) * (k - 2)) / 6;
		}
	}
	go(1);
	if (D > 3 * G) {
		cout << "D";
	}
	else if (D == 3 * G) {
		cout << "DUDUDUNGA";
	}
	else {
		cout << "G";
	}
}
