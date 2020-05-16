#include <bits/stdc++.h>
using namespace std;
int N;
bool visit[1005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	int cnt = 0;
	for (int i = 1; i <= N; ++i) {
		int t;
		cin >> t;
		if (t == 1) continue;
		bool flag = 0;
		for (int i = 2; i < t; ++i) {
			if (t % i == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) ++cnt;
	}
	cout << cnt;
}