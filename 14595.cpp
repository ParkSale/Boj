#include <bits/stdc++.h>
using namespace std;
int N, M, pa[1000005];
int find(int n) {
	if (pa[n] == n) return n;
	return pa[n] = find(pa[n]);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) pa[i] = i;
	while (M--) {
		int a, b;
		cin >> a >> b;
		if (find(a) == find(b)) continue;
		int ra = find(a), rb = find(b);
		for (int i = ra; i <= rb; ++i) pa[i] = max(ra, rb);
	}
	for (int i = 1; i <= N; ++i) find(i);
	set<int> st;
	for (int i = 1; i <= N; ++i) st.insert(pa[i]);
	cout << st.size();
}