#include <bits/stdc++.h>
using namespace std;
int N, M, dfsNum[5005], scc[5005], dfsCnt, sccCnt = 1, ind[5005];
vector<int> vt[5005], s[5005];
stack<int> st;
int go(int n) {
	dfsNum[n] = ++dfsCnt;
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
			int t = st.top(); st.pop();
			scc[t] = sccCnt;
			s[sccCnt].push_back(t);
			if (t == n) break;
		}
		sccCnt++;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	while (N != 0) {
		cin >> M;
		for (int i = 1; i <= N; i++) {
			dfsNum[i] = -1, scc[i] = -1;
			dfsCnt = 0, sccCnt = 1;
			ind[i] = 0;
			vt[i].clear(); s[i].clear();
		}
		for (int i = 1, a, b; i <= M; i++) {
			cin >> a >> b;
			vt[a].push_back(b);
		}
		for (int i = 1; i <= N; i++) {
			if (dfsNum[i] == -1) {
				go(i);
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int n : vt[i]) {
				if (scc[n] != scc[i]) {
					ind[scc[i]]++;
				}
			}
		}
		int ans = 0;
		vector<int> vtt;
		for (int i = 1; i < sccCnt; i++) {
			if (ind[i] == 0) {
				for (int n : s[i]) vtt.push_back(n);
			}
		}
		sort(vtt.begin(), vtt.end());
		for (int n : vtt) cout << n << " ";
		cout << "\n";
		cin >> N;
	}
}