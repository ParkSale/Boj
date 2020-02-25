using namespace std;
#include <bits/stdc++.h>
int N, M;
int pa[1000001], r[1000001];
int find(int n) {
	if (pa[n] == n) return n;
	return pa[n] = find(pa[n]);
}
void hap(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	if (r[a] > r[b]) {
		swap(a, b);
	}
	pa[a] = b;
	if (r[a] == r[b]) ++r[b];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		pa[i] = i;
		r[i] = 1;
	}
	for (int i = 1, a, b, c; i <= M; i++) {
		cin >> a >> b >> c;
		if (a == 0) {
			hap(b, c);
		}
		else {
			if (find(b) == find(c)) cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
	}
}