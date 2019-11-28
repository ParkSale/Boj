#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int N, M, visit[20005], TC;
bool flag;
vector<int> vt[20005];
void go(int n) {
	for (int nn : vt[n]) {
		if (flag) return;
		if (visit[nn] == 0) {
			if (visit[n] == 1) {
				visit[nn] = 2;
			}
			else visit[nn] = 1;
			go(nn);
		}
		else {
			if (visit[n] == visit[nn]) {
				flag = 1;
				return;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> TC;
	while (TC--) {
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			vt[i].clear();
			visit[i] = 0;
		}
		flag = 0;
		for (int i = 1, a, b; i <= M; i++) {
			cin >> a >> b;
			vt[a].push_back(b);
			vt[b].push_back(a);
		}
		for (int i = 1; i <= N; i++) {
			if (visit[i] == 0) {
				visit[i] = 1;
				go(i);
			}
		}
		flag == 0 ? cout << "YES\n" : cout << "NO\n";
	}
}