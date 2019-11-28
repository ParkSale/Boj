#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int N, M, visit[50005];
bool flag;
vector<int> vt[50005];
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
	cin >> N >> M;
	for (int i = 1, a, b; i <= M; i++) {
		cin >> a >> b;
		vt[a].push_back(b);
		vt[b].push_back(a);
	}
	visit[1] = 1;
	go(1);
	if (flag) {
		cout << 0;
		exit(0);
	}
	int a = 0, b = 0;
	for (int i = 1; i <= N; i++) {
		if (visit[i] == 1) a++;
		else b++;
	}
	cout << (long long)a * b * 2;
}