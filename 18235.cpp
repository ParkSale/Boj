#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, A, B, InQueue[500005][2];
queue<int> q[2];
int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> A >> B;
	int t = 0;
	q[t % 2].push(A);
	q[t % 2].push(B);
	InQueue[A][t % 2] = 1;
	while (1) {
		if (q[t % 2].empty())break;
		while (!q[t % 2].empty()) {
			int n = q[t % 2].front(); q[t % 2].pop();
			InQueue[n][t % 2] = 0;
			int v = n + pow(2, t);
			int vv = n - pow(2, t);
			if (v <= N) {
				if (InQueue[v][(t + 1) % 2]) {
					cout << t + 1;
					exit(0);
				}
				InQueue[v][(t + 1) % 2] = 1;
				q[(t + 1) % 2].push(v);
			}
			if (vv > 0) {
				if (InQueue[vv][(t + 1) % 2]) {
					cout << t + 1;
					exit(0);
				}
				InQueue[vv][(t + 1) % 2] = 1;
				q[(t + 1) % 2].push(vv);
			}
		}
		t++;
	}
	cout << -1;
}