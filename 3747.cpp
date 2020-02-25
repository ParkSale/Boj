#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
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
void init() {
	for (int i = 1; i <= 2 * N; ++i) {
		vt[i].clear();
		scc[i] = -1;
		dfsNum[i] = -1;
	}
	sccCnt = 1;
	num = 0;
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
		for (int i = 1; i <= 2 * N; ++i) {
			if (dfsNum[i] == -1) {
				go(i);
			}
		}
		bool flag = 0;
		for (int i = 1; i <= 2 * N; ++i) {
			if (i % 2 == 0) {
				if (scc[i] == scc[i - 1]) {
					flag = 1;
					break;
				}
			}
			else {
				if (scc[i] == scc[i + 1]) {
					flag = 1;
					break;
				}
			}
		}
		if (flag) cout << 0 << "\n";
		else cout << 1 << "\n";
	}

}