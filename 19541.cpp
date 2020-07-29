#include <bits/stdc++.h>
using namespace std;
int N, M, state[100005], ans[100005], ans2[100005], visitP[100005];
vector<int> group[100005], person[100005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; ++i) {
		int k;
		cin >> k;
		while (k--) {
			int n;
			cin >> n;
			group[i].push_back(n);
			person[n].push_back(i);
		}
	}
	for (int i = 1; i <= N; ++i) {
		cin >> state[i];
		ans[i] = state[i];
		ans2[i] = state[i];
	}
	for (int i = M; i >= 1; --i) {
		bool flag = 0;
		for (int n : group[i]) {
			if (ans[n] == 0) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			for (int n : group[i]) {
				ans[n] = 0;
				ans2[n] = 0;
			}
		}
	}
	//ans를 가지고 진행
	for (int i = 1; i <= M; ++i) {
		bool flag = 0;
		for (int n : group[i]) {
			if (ans[n]) {
				//그룹 내 감염자가 현재 있으면
				flag = 1;
				break;
			}
		}
		if (flag) {
			for (int n : group[i]) {
				ans[n] = 1;
				//감염시키기
			}
		}
	}
	bool flag = 0;
	for (int i = 1; i <= N; ++i) {
		if (ans[i] != state[i]) {
			flag = 1;
			break;
		}
	}
	if (flag) {
		cout << "NO";
	}
	else {
		cout << "YES\n";
		for (int i = 1; i <= N; ++i) cout << ans2[i] << " ";
	}
}
