#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, graph[60][60], pre, ans, minV;
bool visit[60], flag;
vector<int> vt[60];
void goo() {
	for (int i = 1; i <= 52; ++i) {
		for (int n : vt[i]) {
			graph[i][n] -= minV;
			graph[n][i] += minV;
		}
	}
}
void go(int n) {
	if (n == 26) {
		flag = 1;
		return;
	}
	for (int i = 1; i <= 52; ++i) {
		if (!visit[i] && graph[n][i] != 0) {
			minV = min(minV, graph[n][i]);
			visit[i] = 1;
			vt[n].push_back(i);
			go(i);
			if (flag) return;
		}
	}
}
int tf(char ch) {
	if (ch >= 'A' && ch <= 'Z') {
		return ch - 'A' + 1;
	}
	else return ch - 'a' + 27;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		char a, b;
		int c;
		cin >> a >> b >> c;
		graph[tf(a)][tf(b)] += c;
		graph[tf(b)][tf(a)] += c;
	}
	while (1) {
		for (int i = 1; i <= 52; ++i) {
			visit[i] = 0;
			vt[i].clear();
		}
		minV = 1e9;
		flag = 0;
		pre = ans;
		visit[1] = 1;
		go(1);
		if (flag) {
			ans += minV;
		}
		else break;
		goo();
	}
	cout << ans;
}