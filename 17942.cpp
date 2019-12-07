#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, arr[100005], K, brr[100005];
vector<pii> vt[100005];
bool visit[100005];
bool can(int x) {
	queue<int> q;
	int k = 0;
	for (int i = 1; i <= N; i++) {
		brr[i] = arr[i];
		visit[i] = 0;
		if (arr[i] <= x) {
			q.push(i);
			k++;
			visit[i] = 1;
			if (k >= M) return 1;
		}
	}
	while (!q.empty()) {
		int n = q.front(); q.pop();
		for (pii p : vt[n]) {
			if (visit[p.first]) continue;
			brr[p.first] -= p.second;
			if (brr[p.first] <= x) {
				q.push(p.first);
				visit[p.first] = 1;
				k++;
				if (k >= M) return 1;
			}
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	int s = 1e9, e = -1e9;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		s = min(s, arr[i]);
		e = max(e, arr[i]);
	}
	cin >> K;
	while (K--) {
		int a, b, c;
		cin >> a >> b >> c;
		vt[a].push_back({ b,c });
	}
	int ans = 1e9;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (can(mid)) {
			e = mid - 1;
			ans = min(ans, mid);
		}
		else {
			s = mid + 1;
		}
	}
	cout << ans;
}