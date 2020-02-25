#include <bits/stdc++.h>
using namespace std;
int N, M, scc[2005], dfsNum[2005], num, sccCnt;
vector<int> vt[2005];
stack<int> st;
void init() {
	for (int i = 1; i <= 2 * N; ++i) {
		vt[i].clear();
		dfsNum[i] = -1;
		scc[i] = -1;
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
	while (cin >> N) {
		cin >> M;
		init();
		for (int i = 1, a, b; i <= M; ++i) {
			cin >> a >> b;
			vt[tf(-a)].push_back(tf(b));
			vt[tf(-b)].push_back(tf(a));
		}
		vt[tf(-1)].push_back(tf(1));
		for (int i = 1; i <= 2 * N; ++i) {
			if (dfsNum[i] == -1) {
				go(i);
			}
		}
		bool flag = 0;
		for (int i = 1; i <= 2 * N; ++i) {
			if (i % 2 == 1) {
				if (scc[i] == scc[i + 1]) {
					flag = 1;
					break;
				}
			}
			else {
				if (scc[i] == scc[i - 1]) {
					flag = 1;
					break;
				}
			}
		}
		if (flag) cout << "no\n";
		else cout << "yes\n";
	}
}