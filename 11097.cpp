#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int TC, N, graph[305][305], dfsNum[305], scc[305], sccCnt, num;
vector<int> vt[305], vtt[305];
vector<pii> ans;
map<string, vector<int>> mp;
stack<int> st;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> TC;
	while (TC--) {
		cin >> N;
		sccCnt = 1;
		num = 0;
		ans.clear();
		mp.clear();
		for (int i = 1; i <= N; ++i) {
			vt[i].clear();
			vtt[i].clear();
			scc[i] = -1;
			string s;
			cin >> s;
			mp[s].push_back(i);
			for (int j = 1; j <= N; ++j) {
				graph[i][j] = 0;
				if (s[j - 1] == '1') {
					vt[i].push_back(j);
				}
			}
		}
		for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
			for (int n : iter->second) {
				scc[n] = sccCnt;
				vtt[sccCnt].push_back(n);
			}
			++sccCnt;
		}
		for (int i = 1; i <= N; ++i) {
			for (int n : vt[i]) {
				if (scc[i] != scc[n]) {
					graph[scc[i]][scc[n]] = 1;
				}
			}
		}
		for (int k = 1; k < sccCnt; ++k) {
			for (int i = 1; i < sccCnt; ++i) {
				if (graph[i][k]) {
					for (int j = 1; j < sccCnt; ++j) {
						if (graph[i][j] && graph[i][k] && graph[k][j]) {
							graph[i][j] = 0;
						}
					}
				}
			}
		}
		for (int i = 1; i < sccCnt; ++i) {
			if (vtt[i].size() > 1) {
				for (int j = vtt[i].size() - 1; j >= 1; --j) {
					ans.push_back({ vtt[i][j - 1],vtt[i][j] });
				}
				ans.push_back({ vtt[i][vtt[i].size() - 1],vtt[i][0] });
			}
		}
		for (int i = 1; i < sccCnt; ++i) {
			for (int j = 1; j < sccCnt; ++j) {
				if (graph[i][j]) {
					ans.push_back({ vtt[i][0],vtt[j][0] });
				}
			}
		}
		cout << ans.size() << "\n";
		for (pair<int, int> p : ans) cout << p.first << " " << p.second << "\n";
		cout << "\n";
	}
}