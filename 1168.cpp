#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<int> vt;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) vt.push_back(i);
	cout << "<";
	int t = 0;
	for (int i = 1; i < N; ++i) {
		t += K;
		t %= vt.size();
		if (t == 0) t = vt.size();
		--t;
		cout << vt[t] << ", ";
		vt.erase(vt.begin() + t);
	}
	cout << vt[0] << ">";
}