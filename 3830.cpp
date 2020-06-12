#include <bits/stdc++.h>
using namespace std;
struct info {
	int type, n, diff;
}arr[100005];
int N, M, pa[100005], v[100005];
vector<info> vt[100005];
bool visit[100005];
int find(int n) {
	if (pa[n] == n) return n;
	return pa[n] = find(pa[n]);
}
void dfs(int n, int value) {
	v[n] = value;
	for (info p : vt[n]) {
		if (!visit[p.n]) {
			visit[p.n] = 1;
			dfs(p.n, value + p.diff);
		}
	}
}
void hap(int a, int b) {
	a = find(a), b = find(b);
	pa[a] = b;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	while (N != 0 && M != 0) {
		for (int i = 1; i <= N; ++i) {
			pa[i] = i;
			v[i] = 0;
			vt[i].clear();
		}
		for (int i = 1; i <= M; ++i) {
			char ch;
			cin >> ch;
			if (ch == '!') {
				int a, b, c;
				cin >> a >> b >> c;
				arr[i] = { 0,a,b };
				vt[a].push_back({ 0,b,c });
				vt[b].push_back({ 0,a, -c });
			}
			else {
				int a, b;
				cin >> a >> b;
				arr[i] = { 1,a,b };
			}
		}
		for (int i = 1; i <= N; ++i) visit[i] = 0;
		for (int i = 1; i <= N; ++i) {
			if (!visit[i]) {
				visit[i] = 1;
				dfs(i, 0);
			}
		}
		for (int i = 1; i <= M; ++i) {
			if (arr[i].type == 0) {
				hap(arr[i].n, arr[i].diff);
			}
			else {
				int a = arr[i].n, b = arr[i].diff;
				if (find(a) != find(b)) {
					cout << "UNKNOWN\n";
				}
				else {
					cout << v[b] - v[a] << "\n";
				}
			}
		}
		cin >> N >> M;
	}
}