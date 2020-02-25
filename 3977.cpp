#include <bits/stdc++.h>
using namespace std;
int TC, N, M, SCC[100005], sccCnt = 1, dfsNum[100005], num, ind[100005];
vector<int> vt[100005], vtt[100005], vttt[100005];
stack<int> st;
int go(int n) {
	dfsNum[n] = ++num;
	int ret = dfsNum[n];
	st.push(n);
	for (int nn : vt[n]) {
		if (dfsNum[nn] == -1) {
			ret = min(ret, go(nn));
		}
		else if (SCC[nn] == -1) {
			ret = min(ret, dfsNum[nn]);
		}
	}
	if (ret == dfsNum[n]) {
		while (st.top() != n) {
			int v = st.top(); st.pop();
			SCC[v] = sccCnt;
			vtt[sccCnt].push_back(v);
		}
		int v = st.top(); st.pop();
		SCC[v] = sccCnt;
		vtt[sccCnt].push_back(v);
		++sccCnt;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> TC;
	while (TC--) {
		cin >> N >> M;
		for (int i = 1; i <= N; ++i) {
			vt[i].clear();
			vtt[i].clear();
			ind[i] = 0;
			SCC[i] = -1;
			dfsNum[i] = -1;
			sccCnt = 1;
			num = 0;
		}
		for (int i = 1, a, b; i <= M; ++i) {
			cin >> a >> b;
			++a; ++b;
			vt[a].push_back(b);
		}
		for (int i = 1; i <= N; ++i) {
			if (dfsNum[i] == -1) {
				go(i);
			}
		}
		for (int i = 1; i <= N; ++i) {
			for (int nn : vt[i]) {
				if (SCC[i] != SCC[nn]) {
					ind[SCC[nn]]++;
				}
			}
		}
		int v = 0, cnt = 0;
		for (int i = 1; i < sccCnt; ++i) {
			if (ind[i] == 0) {
				v = i;
				++cnt;
			}
		}
		if (cnt >= 2) {
			cout << "Confused\n\n";
			continue;
		}
		sort(vtt[v].begin(), vtt[v].end());
		for (int n : vtt[v]) cout << n - 1 << "\n";
		cout << "\n";
	}
}