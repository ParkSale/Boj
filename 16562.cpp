#include <bits/stdc++.h>
using namespace std;
int N, M, K, arr[10005], pa[10005];
int find(int n) {
	if (pa[n] == n)return n;
	return pa[n] = find(pa[n]);
}
void hap(int a, int b) {
	a = find(a); b = find(b);
	if (arr[a] < arr[b]) {
		pa[b] = a;
	}
	else {
		pa[a] = b;
	}
}
set<int> st;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		pa[i] = i;
	}
	while (M--) {
		int a, b;
		cin >> a >> b;
		if (find(a) != find(b)) hap(a, b);
	}
	for (int i = 1; i <= N; ++i) st.insert(find(i));
	int ans = 0;
	for (int n : st) ans += arr[n];
	if (ans > K) cout << "Oh no";
	else cout << ans;
}