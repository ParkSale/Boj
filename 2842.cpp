#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, piro[55][55], cnt;
char graph[55][55];
bool visit[55][55];
pii S, dir[] = { {0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1} };
set<int> st;
queue<pii> q;
bool can(int l, int r) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visit[i][j] = 0;
		}
	}
	if (piro[S.first][S.second] < l || piro[S.first][S.second] > r) return 0;
	visit[S.first][S.second] = 1;
	q.push(S);
	int ret = 0;
	while (!q.empty()) {
		pii p = q.front(); q.pop();
		for (int i = 0; i < 8; i++) {
			int px = p.first + dir[i].first, py = p.second + dir[i].second;
			if (px >= 1 && px <= N && py >= 1 && py <= N && !visit[px][py] && piro[px][py] >= l && piro[px][py] <= r) {
				visit[px][py] = 1;
				q.push({ px,py });
				if (graph[px][py] == 'K') ret++;
			}
		}
	}
	return ret == cnt;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'P') {
				S = { i,j };
			}
			else if (graph[i][j] == 'K') {
				++cnt;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> piro[i][j];

			st.insert(piro[i][j]);
		}
	}
	auto s = st.begin(), e = st.begin();
	int minV = 1e9;
	while (s != st.end() && e != st.end()) {
		if (can(*s, *e)) {
			minV = min(minV, *e - *s);
			s++;
		}
		else e++;
	}
	cout << minV;
}