#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct info {
	ll x;
	bool operator <(const info& a) const {
		return x > a.x;
	}
};
ll N, M, arr[105];
priority_queue<info> pq;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		pq.push({ arr[i] });
	}
	ll t, v;
	while (M-- > 1) {
		info tt = pq.top(); pq.pop();
		t = tt.x;
		for (int i = 1; i <= N; i++) {
			v = t * arr[i];
			pq.push({ v });
			if (t % arr[i] == 0) break;
		}
	}
	cout << pq.top().x;
}