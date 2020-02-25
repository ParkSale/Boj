#include <bits/stdc++.h>
using namespace std;
int N, M, dfsNum[20005], num, scc[20005], sccCnt;
vector<int> vt[20005];
stack<int> st;
int tf(int a) {
	if (a < 0) {
		return -a * 2 - 1;
	}
	return a * 2;
}
int go(int n) {
	dfsNum[n] = ++num;
	int ret = dfsNum[n];
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
	for (int i = 1; i <= 2 * N; ++i) {
		dfsNum[i] = -1;
		scc[i] = -1;
	}
	sccCnt = 1;
	for (int i = 1, a, b; i <= M; ++i) {
		cin >> a >> b;
		vt[tf(-a)].push_back(tf(b));
		vt[tf(-b)].push_back(tf(a));
	}
	for (int i = 1; i <= 2 * N; ++i) {
		if (dfsNum[i] == -1) {
			go(i);
		}
	}
	for (int i = 1; i <= 2 * N; ++i) {
		if (i % 2 == 0) {
			if (scc[i] == scc[i - 1]) {
				cout << 0;
				exit(0);
			}
		}
		else {
			if (scc[i] == scc[i + 1]) {
				cout << 0;
				exit(0);
			}
		}
	}
	cout << 1;
}