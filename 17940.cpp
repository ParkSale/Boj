#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, arr[1005], graph[1005][1005];
pii d[1005];
struct info {
	int n, tf, d;
	bool operator < (const info& a) const {
		if (tf == a.tf) {
			return d > a.d;
		}
		return tf > a.tf;
	}
};
priority_queue<info> pq;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	M++;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 0) graph[i][j] = 1e9;
		}
		d[i] = { 1e9,1e9 };
	}
	d[1] = { 0,0 };
	pq.push({ 1,0,0 });
	while (!pq.empty()) {
		info p = pq.top(); pq.pop();
		if (p.n == M) {
			cout << p.tf << " " << p.d;
			exit(0);
		}
		for (int i = 1; i <= N; i++) {
			if (graph[p.n][i] == 1e9) continue;
			pii v = { 0,0 };
			if (arr[i] == arr[p.n]) {
				v.first = p.tf;
			}
			else v.first = p.tf + 1;
			v.second = p.d + graph[p.n][i];
			if (d[i] > v) {
				d[i] = v;
				pq.push({ i,v.first,v.second });
			}
		}
	}
}