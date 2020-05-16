#include <bits/stdc++.h>
using namespace std;
int F, S, G, U, D;
bool visit[1000001];
queue<int> q;
int dis[1000001];
void bfs() {
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		if (a + U <= F) {
			if (visit[a + U] == 0) {
				visit[a + U] = 1;
				q.push(a + U);
				dis[a + U] = dis[a] + 1;
			}
		}
		if (a - D >= 1) {
			if (visit[a - D] == 0) {
				visit[a - D] = 1;
				q.push(a - D);
				dis[a - D] = dis[a] + 1;
			}
		}
		if (a == G) {
			cout << dis[G];
			exit(0);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> F >> S >> G >> U >> D;
	q.push(S);
	visit[S] = true;
	bfs();
	cout << "use the stairs";
}