#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, scc[20005], dfsNum[20005], num, sccCnt;
char ans[20005];
pii arr[20005];
vector<int> vt[20005];
stack<int> st;
void init() {
	for (int i = 1; i <= 2 * N; ++i) {
		vt[i].clear();
		dfsNum[i] = -1;
		scc[i] = -1;
		ans[i] = ' ';
	}
	num = 0;
	sccCnt = 1;
}
int tf(int a) {
	if (a < 0) {
		return -a * 2 - 1;
	}
	return a * 2;
}
int go(int n) {
	dfsNum[n] = ++num;
	int ret = num;
	st.push(n);
	for (int nn : vt[n]) {
		if (dfsNum[nn] == -1) {
			ret = min(ret, go(nn));
		}
		else if (scc[nn] == -1) {
			ret = min(ret, dfsNum[nn]);
		}
	}
	if (ret == dfsNum[n]) {
		while (1) {
			int v = st.top(); st.pop();
			scc[v] = sccCnt;
			if (v == n) break;
		}
		++sccCnt;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	init();
	for (int i = 1; i <= M; ++i) {
		pair<int, char> t[4];
		for (int j = 1; j <= 3; ++j) {
			int a; char b;
			cin >> a >> b;
			t[j] = { a,b };
		}
		for (int j = 1; j <= 3; ++j) {
			for (int k = j + 1; k <= 3; ++k) {
				int a, b;
				if (t[j].second == 'R') {
					a = -t[j].first;
				}
				else a = t[j].first;
				if (t[k].second == 'R') {
					b = -t[k].first;
				}
				else b = t[k].first;
				vt[tf(-a)].push_back(tf(b));
				vt[tf(-b)].push_back(tf(a));
			}
		}
	}
	for (int i = 1; i <= 2 * N; ++i) {
		if (dfsNum[i] == -1) {
			go(i);
		}
	}
	bool flag = 0;
	for (int i = 1; i <= 2 * N; ++i) {
		if (i % 2 == 1) {
			if (scc[i] == scc[i + 1]) {
				cout << -1;
				exit(0);
			}
		}
		else {
			if (scc[i] == scc[i - 1]) {
				cout << -1;
				exit(0);
			}
		}
	}
	for (int i = 1; i <= 2 * N; ++i) {
		arr[i] = { scc[i],i };
	}
	sort(arr + 1, arr + 2 * N + 1);
	for (int i = 2 * N; i >= 1; --i) {
		int v = arr[i].second;
		if (ans[(v + 1) / 2] == ' ') {
			if (v % 2 == 1) {
				ans[(v + 1) / 2] = 'B';
			}
			else {
				ans[(v + 1) / 2] = 'R';
			}
		}
	}
	for (int i = 1; i <= N; ++i) cout << ans[i];
}