#include <bits/stdc++.h>
using namespace std;
#define MOD 100000007
#define xx first
#define yy second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
pii dir[] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} };
int N, M, dfsNum[500005], dfsCnt, scc[500005], sccCnt = 1, deg[500005], cash[500005], S, P, sCash[500005], maxV[500005];
vector<int> vt[500005], s[500005];
bool visit[500005], check[500005], rest[500005];
stack<int> st;
queue<int> q;
int go(int n) {
	dfsNum[n] = ++dfsCnt;
	int ret = dfsNum[n];
	st.push(n);
	for (int nn : vt[n]) {
		if (dfsNum[nn] == -1) ret = min(ret, go(nn));
		else if (scc[nn] == -1) ret = min(ret, dfsNum[nn]);
	}
	if (ret == dfsNum[n]) {
		while (1) {
			int t = st.top(); st.pop();
			scc[t] = sccCnt;
			if (t == n)break;
		}
		sccCnt++;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		dfsNum[i] = -1; scc[i] = -1;
	}
	for (int i = 1, a, b; i <= M; i++) {
		cin >> a >> b;
		vt[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) cin >> cash[i];
	cin >> S >> P;
	for (int i = 1, a; i <= P; i++) {
		cin >> a;
		rest[a] = 1;
	}
	int sS = 0;
	for (int i = 1; i <= N; i++) if (dfsNum[i] == -1) go(i);
	for (int i = 1; i <= N; i++) {
		sCash[scc[i]] += cash[i];
		if (rest[i]) check[scc[i]] = 1;
		if (i == S) sS = scc[i];
		for (int n : vt[i]) {
			if (scc[i] != scc[n]) {
				deg[scc[n]]++;
				s[scc[i]].push_back(scc[n]);
			}
		}
	}
	visit[sS] = 1;
	for (int i = 1; i < sccCnt; i++) {
		maxV[i] = sCash[i];
		if (deg[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int n = q.front(); q.pop();
		for (int nn : s[n]) {
			if (visit[n]) {
				maxV[nn] = max(maxV[nn], maxV[n] + sCash[nn]);
				visit[nn] = 1;
			}
			deg[nn]--;
			if (deg[nn] == 0) q.push(nn);
		}
	}
	int ans = 0;
	for (int i = 1; i < sccCnt; i++) {
		if (check[i] && visit[i]) ans = max(ans, maxV[i]);
	}
	cout << ans;
}