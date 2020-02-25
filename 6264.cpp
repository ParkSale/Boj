#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int TC, N, dfsNum[305], scc[305], sccCnt, num, ind[305];
string str[305];
bool visit[305];
set<int> vt[305];
vector<int> vtt[305], vttt[305];
vector<string> ans;
map<string, int> mp;
pair<int, int> arr[305];
stack<int> st;
queue<pair<int, int>> q;
void init() {
	mp.clear();
	for (int i = 1; i <= N; ++i) {
		dfsNum[i] = -1;
		scc[i] = -1;
		ind[i] = 0;
		vt[i].clear();
		vtt[i].clear();
		vttt[i].clear();
		visit[i] = 0;
	}
	num = 0;
	sccCnt = 1;
	ans.clear();
}
int go(int n) {
	dfsNum[n] = ++num;
	st.push(n);
	int ret = num;
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
			vtt[sccCnt].push_back(v);
			if (v == n) break;
		}
		++sccCnt;
	}
	return ret;
}
void chk(int n) {
	for (int nn : vttt[n]) {
		if (!visit[nn]) {
			visit[nn] = 1;
			chk(nn);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while (cin >> N) {
		if (N == 0) continue;
		int cnt = 0;
		init();
		cin.ignore();
		for (int i = 1; i <= N; ++i) {
			string s;
			cin >> s;
			if (mp.find(s) == mp.end()) {
				mp[s] = ++cnt;
				str[cnt] = s;
			}
			string ss;
			getline(cin, ss);
			string tmp = "";
			for (int i = 1; i < ss.length(); ++i) {
				if (ss[i] == ' ') {
					if (mp.find(tmp) == mp.end()) {
						mp[tmp] = ++cnt;
						str[cnt] = tmp;
					}
					vt[mp[tmp]].insert(mp[s]);
					tmp = "";
				}
				else {
					tmp.push_back(ss[i]);
				}
			}
			if (mp.find(tmp) == mp.end()) {
				mp[tmp] = ++cnt;
				str[cnt] = tmp;
			}
			vt[mp[tmp]].insert(mp[s]);
		}
		for (int i = 1; i <= N; ++i) {
			if (dfsNum[i] == -1) {
				go(i);
			}
		}
		for (int i = 1; i <= N; ++i) {
			for (int n : vt[i]) {
				if (scc[i] != scc[n]) {
					ind[scc[n]]++;
					vttt[scc[n]].push_back(scc[i]);
				}
			}
		}
		for (int i = 1; i < sccCnt; ++i) {
			if (vtt[i].size() >= 2) {
				visit[i] = 1;
				chk(i);
			}
			if (ind[i] == 0) {
				visit[i] = 1;
			}
		}
		for (int i = 1; i < sccCnt; ++i) {
			if (visit[i]) {
				for (int n : vtt[i]) {
					ans.push_back(str[n]);
				}
			}
		}
		sort(ans.begin(), ans.end());
		cout << ans.size() << "\n";
		for (string s : ans) cout << s << " ";
		cout << "\n";
	}
}