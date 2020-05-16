#include <bits/stdc++.h>
using namespace std;
struct info {
	int score, turn, cnt;
};
int N, a, b;
queue<info> q;
bool visit[1005][1005][15];
void go() {
	q.push({ 0,0,0 });
	visit[0][0][0] = 1;
	while (!q.empty()) {
		info p = q.front(); q.pop();
		if (p.score >= N) {
			if (p.cnt * 10 <= p.turn) {
				cout << p.turn;
				exit(0);
			}
			continue;
		}
		if (p.score + a < (N + a) && !visit[p.score + a][p.turn + 1][p.cnt]) {
			q.push({ p.score + a,p.turn + 1,p.cnt });
			visit[p.score + a][p.turn + 1][p.cnt] = 1;
		}
		if (p.score + b < (N + a) && !visit[p.score + b][p.turn + 1][p.cnt]) {
			q.push({ p.score + b,p.turn + 1,p.cnt });
			visit[p.score + b][p.turn + 1][p.cnt] = 1;
		}
		if (p.score != 0 && p.score * 2 < (N + a) && !visit[p.score * 2][p.turn + 1][p.cnt + 1]) {
			if ((p.cnt + 1) * 10 <= p.turn + 1) {
				q.push({ p.score * 2,p.turn + 1,p.cnt + 1 });
				visit[p.score * 2][p.turn + 1][p.cnt + 1] = 1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> a >> b;
	go();
}