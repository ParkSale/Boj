#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, pa[200005];
struct info {
	int x, y, d;
	bool operator <(const info& a) const {
		return d < a.d;
	}
}I[200005];
int find(int n) {
	if (pa[n] == n) return n;
	return pa[n] = find(pa[n]);
}
void hap(int a, int b) {
	pa[find(a)] = find(b);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	while (N != 0) {
		for (int i = 0; i < N; i++) {
			pa[i] = i;
		}
		int ans = 0;
		for (int i = 1; i <= M; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			I[i] = { a,b,c };
			ans += c;
		}
		int cnt = 0;
		sort(I + 1, I + M + 1);
		for (int i = 1; i <= M; i++) {
			if (find(I[i].x) != find(I[i].y)) {
				hap(I[i].x, I[i].y);
				ans -= I[i].d;
				cnt++;
			}
			if (cnt == N - 1) break;
		}
		cout << ans << "\n";
		cin >> N >> M;
	}
}