#include <bits/stdc++.h>
using namespace std;
int N, M, S, E;
vector<int> vt[300005];
struct info {
	int n, d;
};
queue<info> q;
bool visit[300005];
int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> S >> E;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		vt[a].push_back(b);
		vt[b].push_back(a);
	}
	q.push({ S,0 });
	visit[S] = 1;
	while (!q.empty()) {
		info p = q.front(); q.pop();
		if (p.n == E) {
			cout << p.d;
			exit(0);
		}
		for (int n : vt[p.n]) {
			if (!visit[n]) {
				visit[n] = 1;
				q.push({ n,p.d + 1 });
			}
		}
		if (p.n < N && !visit[p.n + 1]) {
			visit[p.n + 1] = 1;
			q.push({ p.n + 1,p.d + 1 });
		}
		if (p.n >= 1 && !visit[p.n - 1]) {
			visit[p.n - 1] = 1;
			q.push({ p.n - 1,p.d + 1 });
		}
	}
}