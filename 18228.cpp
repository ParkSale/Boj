#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> a, b;
int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	bool flag = 0;
	for (int i = 1, t; i <= N; i++) {
		cin >> t;
		if (t == -1) {
			flag = 1;
			continue;
		}
		if (flag == 0) a.push_back(t);
		else b.push_back(t);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	cout << a[0] + b[0];
}